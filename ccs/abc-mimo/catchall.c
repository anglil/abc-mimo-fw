#include <msp430.h>


#pragma vector=RTC_VECTOR       //".int41" 0xFFD2 RTC
#pragma vector=PORT2_VECTOR     //".int42" 0xFFD4 Port 2
#pragma vector=TIMER2_A1_VECTOR //".int43" 0xFFD6 Timer0_A5 CC1-4, TA
//#pragma vector=TIMER2_A0_VECTOR //".int44" 0xFFD8 Timer0_A5 CC0
#pragma vector=USCI_B1_VECTOR   //".int45" 0xFFDA USCI B1 Receive/Transmit
#pragma vector=USCI_A1_VECTOR   //".int46" 0xFFDC USCI A1 Receive/Transmit
#pragma vector=PORT1_VECTOR     //".int47" 0xFFDE Port 1
#pragma vector=TIMER1_A1_VECTOR //".int48" 0xFFE0 Timer1_A3 CC1-2, TA1
//#pragma vector=TIMER1_A0_VECTOR //".int49" 0xFFE2 Timer1_A3 CC0
#pragma vector=DMA_VECTOR       //".int50" 0xFFE4 DMA
#pragma vector=LDO_PWR_VECTOR   //".int51" 0xFFE6 LDO Power Management event
#pragma vector=TIMER0_A1_VECTOR //".int52" 0xFFE8 Timer0_A5 CC1-4, TA
#pragma vector=TIMER0_A0_VECTOR //".int53" 0xFFEA Timer0_A5 CC0
#pragma vector=ADC10_VECTOR     //".int54" 0xFFEC ADC
#pragma vector=USCI_B0_VECTOR   //".int55" 0xFFEE USCI B0 Receive/Transmit
#pragma vector=USCI_A0_VECTOR   //".int56" 0xFFF0 USCI A0 Receive/Transmit
#pragma vector=WDT_VECTOR       //".int57" 0xFFF2 Watchdog Timer
#pragma vector=TIMER0_B1_VECTOR //".int58" 0xFFF4 Timer0_B7 CC1-6, TB
#pragma vector=TIMER0_B0_VECTOR //".int59" 0xFFF6 Timer0_B7 CC0
#pragma vector=COMP_B_VECTOR    //".int60" 0xFFF8 Comparator B
#pragma vector=UNMI_VECTOR      //".int61" 0xFFFA User Non-maskable
#pragma vector=SYSNMI_VECTOR    //".int62" 0xFFFC System Non-maskable

// Catch unregistered interrupts before they catch you.
__interrupt void isr_catchall(void) {
  	return;
}
