#include <msp430.h>
#include "comm.h"
#include "lpstd.h"
#include "pindef.h"

/*
 * comm.c
 *
 *  Created on: Jan 12, 2014
 *      Author: anparks
 */



//uint16_t chipcounter;
//uint16_t corr_chip_len;

void COMM_ALL_ON(){

	COMM_MIMO_ON();
	COMM_CORR_ON();
	COMM_SUM_ON();
	COMM_COMP_ON();
	COMM_VCOM_ON();

}

void COMM_ALL_OFF(){

	COMM_MIMO_OFF();
	COMM_CORR_OFF();
	COMM_SUM_OFF();
	COMM_COMP_OFF();
	COMM_VCOM_OFF();

}

void COMM_SW_POS(uint8_t pos) {
	switch(pos) {
		case 1:
			BITSET(POUT_SW0, SW0_BIT);
			BITCLR(POUT_SW1, SW1_BIT);
			break;

		case 2:
			BITCLR(POUT_SW0, SW0_BIT);
			BITSET(POUT_SW1, SW1_BIT);
			break;

		default:
			BITCLR(POUT_SW0, SW0_BIT);
			BITCLR(POUT_SW1, SW1_BIT);
			break;
	}
}

void COMM_INIT_CHIPGEN() {
	TA0CTL =  TASSEL_2 | ID_0 | MC_0 | TACLR;
//	TA0CCTL0 = CCIE; // Interrupt twice per chip?
	TA0CCTL2 =  OUTMOD_4; // I channel
	TA0CCTL1 = OUTMOD_4; // Q channel
	TA0CCR0 = 3; // Reset every fourth cycle
	TA0CCR2 = 1; // I channel toggles first
	TA0CCR1 = 3; // Q channel toggles second
//	__bis_SR_register(GIE);
}

void COMM_SET_CHIPGEN_DIV(uint16_t div) {
	TA0CCR0 = TA0CCR1 = 2*div+1;
	TA0CCR2 = 1*div;
}

void COMM_START_CHIPGEN() {
	TA0CTL |= MC_1 | TACLR; // Up mode
}

void COMM_STOP_CHIPGEN() {
	TA0CTL &= ~(MC_3); // Kill it
}

void COMM_RST_RATE(uint16_t per, uint16_t div) {
//	corr_chip_len=per;
//	chipcounter=0;
	TA1CTL =  TASSEL_2 | div | MC_0 | TACLR;
	TA1CCR0 = per-1;
	TA1CTL |= MC_1 | TACLR;
	TA1CCTL0 = CCIE;
	__bis_SR_register(GIE);
}

//#pragma vector=TIMER0_A0_VECTOR
//__interrupt void corr_chip_isr(void) {
//	chipcounter++;
//
//	if(chipcounter>corr_chip_len) {
//		BITSET(POUT_CORR_RST, CORR_RST_BIT);
//		BITCLR(POUT_CORR_RST, CORR_RST_BIT);
//		chipcounter=0;
//	}
//}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void corr_rst_isr(void) {
	BITSET(POUT_CORR_RST, CORR_RST_BIT);
	__delay_cycles(40);
	BITCLR(POUT_CORR_RST, CORR_RST_BIT);
}
