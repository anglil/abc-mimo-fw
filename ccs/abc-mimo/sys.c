#include <msp430.h>
#include "sys.h"
#include "pindef.h"
/*
 * sys.c
 *
 *  Created on: Jan 12, 2014
 *      Author: anparks
 */

void XT1_INIT() {

	P5SEL |= XIN_BIT|XOUT_BIT;                // Port select XT1
	UCSCTL6 &= ~(XT1OFF);                     // XT1 On
//	UCSCTL6 |= XCAP_3;                        // Internal load cap

	// Loop until XT1 fault flag is cleared
	do
	{
		UCSCTL7 &= ~XT1LFOFFG;                  // Clear XT1 fault flags
	}while (UCSCTL7&XT1LFOFFG);               // Test XT1 fault flag


}

void RSEL_ADJ(uint16_t rsel_val) {

}

/* Minimum value of multiplier is 7 */
void FLL_ADJ(uint16_t multiplier)
{



  __bis_SR_register(SCG0);                  // Disable the FLL control loop
  UCSCTL0 = 0x0000;                         // Set lowest possible DCOx, MODx

//	// Set up RSEL based on desired multiplier
	if(multiplier<7)
		return;
	else if(multiplier<22)
		UCSCTL1 = DCORSEL_1;
	else if(multiplier<45)
		UCSCTL1 = DCORSEL_2;
	else if(multiplier<97)
		UCSCTL1 = DCORSEL_3;
	else if(multiplier<186)
		UCSCTL1 = DCORSEL_4;
	else if(multiplier<376)
		UCSCTL1 = DCORSEL_5;
	else if(multiplier<724)
		UCSCTL1 = DCORSEL_6;
	//else if(multiplier<1191)
	else
		UCSCTL1 = DCORSEL_7;


  UCSCTL2 = FLLD_1 | (multiplier-1);

  __bic_SR_register(SCG0);

  // Worst-case settling time for the DCO when the DCO range bits have been
  // changed is n x 32 x 32 x f_MCLK / f_FLL_reference. See UCS chapter in 5xx
  // UG for optimization.
  // 32 x 32 x 2.45 MHz / 32,768 Hz = 76563 = MCLK cycles for DCO to settle
  	  __delay_cycles(76563);


  // Loop until XT1,XT2 & DCO fault flag is cleared
  do
  {
    UCSCTL7 &= ~(XT2OFFG | XT1LFOFFG  | DCOFFG);
                                            // Clear XT2,XT1,DCO fault flags
    SFRIFG1 &= ~OFIFG;                      // Clear fault flags
  }while (SFRIFG1&OFIFG);                   // Test oscillator fault flag

}


void wait(uint16_t time) {
	TA2CTL =  TASSEL_1 | ID_0 | MC_0 | TACLR;
	TA2CCR0 = time-1;
	TA2CTL |= MC_1 | TACLR;
	TA2CCTL0 = CCIE;
	__bis_SR_register(GIE | LPM0_bits);
	TA2CCTL0 = 0x0000;
	TA2CTL = 0x0000;
}

#pragma vector=TIMER2_A0_VECTOR
__interrupt void wait_isr(void) {
	__bic_SR_register_on_exit(LPM4_bits);
}


