#include <msp430.h> 
#include "lpstd.h"
#include "pindef.h"
#include "sys.h"
#include "comm.h"

uint16_t corr_setting;

void signalNewSetting(uint16_t corr_setting) {
	BITSET(POUT_LED, LED_BIT);
	wait(16384);
	BITCLR(POUT_LED, LED_BIT);
	wait(16384);
	int flashct;
	for(flashct=0;flashct<=corr_setting;flashct++) {
		BITSET(POUT_LED, LED_BIT);
		wait(1000);
		BITCLR(POUT_LED, LED_BIT);
		wait(10000);
	}
}

/*
 * main.c
 */
void main(void) {

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    IO_INIT(); // Initialize IO

    XT1_INIT();

//    COMM_ALL_ON();
    COMM_COMP_ON();
    COMM_CORR_ON();
//    COMM_MIMO_ON();
    COMM_SUM_ON();
//    COMM_VCOM_ON();

    COMM_SW_POS(1); // Select Vsig1 as correlator input

    __bis_SR_register(LPM4_bits);

    COMM_INIT_CHIPGEN();
    COMM_START_CHIPGEN();

    // Initial setting
	FLL_ADJ(10); //100 Hz, 100 chip
	COMM_SET_CHIPGEN_DIV(820);
	COMM_RST_RATE(20525,ID_2);

    corr_setting=0;

    signalNewSetting(corr_setting);

    while(1) {

    	// Switch logic
    	if(PJIN & BIT2){

    		if(corr_setting < 8) {
    			corr_setting++;
    		} else {
    			corr_setting=0;
    		}

    		switch(corr_setting) {

    		case 0:
//    			// 0.9990 kHz, 10 chip
//        		FLL_ADJ(10);
//        		COMM_SET_CHIPGEN_DIV(82);
//        		COMM_RST_RATE(1660, ID_0);
    			FLL_ADJ(10); //100 Hz, 100 chip
    			COMM_SET_CHIPGEN_DIV(820);
    			COMM_RST_RATE(20525,ID_2);
        		break;
    		case 1:
    			// 0.9990 kHz, 100 chips
    			FLL_ADJ(10);
       			COMM_SET_CHIPGEN_DIV(82);
       			COMM_RST_RATE(16600, ID_0);
       			break;
    		case 2:
    			// 0.9990 kHz, 1000 chips
    			FLL_ADJ(10);
    			COMM_SET_CHIPGEN_DIV(82);
    			COMM_RST_RATE(20750, ID_3);
    			break;

    		case 3:
    			// 9.9990 kHz, 10 chips
    			FLL_ADJ(83);
    			COMM_SET_CHIPGEN_DIV(68);
    			COMM_RST_RATE(1380, ID_0);

    			break;

    		case 4:
    			// 9.9990 kHz, 100 chips
    			FLL_ADJ(83);
    			COMM_SET_CHIPGEN_DIV(68);
    			COMM_RST_RATE(13800, ID_0);
				break;

    		case 5:
    			// 9.9990 kHz, 1000 chips
    			FLL_ADJ(83);
    			COMM_SET_CHIPGEN_DIV(68);
    			COMM_RST_RATE(34500,ID_2);
    			break;

    		case 6:
    			// 100.011 kHz, 10 chips
    			FLL_ADJ(293);
    			COMM_SET_CHIPGEN_DIV(24);
    			COMM_RST_RATE(500,ID_0);
    			break;

    		case 7:
    			// 100.011 kHz, 100 chips
    			FLL_ADJ(293);
    			COMM_SET_CHIPGEN_DIV(24);
    			COMM_RST_RATE(5000,ID_0);
    			break;

    		case 8:
    			// 100.011 kHz, 1000 chips
    			FLL_ADJ(293);
    			COMM_SET_CHIPGEN_DIV(24);
    			COMM_RST_RATE(50000,ID_0);
    			break;
    		}

    		signalNewSetting(corr_setting);


    		wait(16384);
    	}
    }
}


