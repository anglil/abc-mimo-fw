/*
 * pindef.h
 *
 *  Created on: Jan 12, 2014
 *      Author: anparks
 */

#ifndef PINDEF_H_
#define PINDEF_H_

/*---------------------------------------------------------------------------*/
// Port 1
/*---------------------------------------------------------------------------*/

#define P1DIR_INIT ~(COUT_BIT)
#define P1SEL_INIT (CORR_CHIPQ_BIT | CORR_CHIPI_BIT | CREF_BIT )
#define P1OUT_INIT (0)

#define COUT_BIT BIT1
#define PDIR_COUT P1DIR
#define PSEL_COUT P1SEL
#define POUT_COUT P1OUT
#define PIN_COUT P1IN

#define CORR_CHIPQ_BIT BIT2
#define PDIR_CORR_CHIPQ P1DIR
#define PSEL_CORR_CHIPQ P1SEL
#define POUT_CORR_CHIPQ P1OUT
#define PIN_CORR_CHIPQ P1IN

#define CORR_CHIPI_BIT BIT3
#define PDIR_CORR_CHIPI P1DIR
#define PSEL_CORR_CHIPI P1SEL
#define POUT_CORR_CHIPI P1OUT
#define PIN_CORR_CHIPI P1IN

#define CORR_RST_BIT BIT4
#define PDIR_CORR_RST P1DIR
#define PSEL_CORR_RST P1SEL
#define POUT_CORR_RST P1OUT
#define PIN_CORR_RST P1IN

#define TX1_BIT BIT5
#define PDIR_TX1 P1DIR
#define PSEL_TX1 P1SEL
#define POUT_TX1 P1OUT
#define PIN_TX1 P1IN

#define TX2_BIT BIT6
#define PDIR_TX2 P1DIR
#define PSEL_TX2 P1SEL
#define POUT_TX2 P1OUT
#define PIN_TX2 P1IN

#define CREF_BIT BIT7
#define PDIR_CREF P1DIR
#define PSEL_CREF P1SEL
#define POUT_CREF P1OUT
#define PIN_CREF P1IN

/*---------------------------------------------------------------------------*/
// Port 2
/*---------------------------------------------------------------------------*/

#define P2DIR_INIT ~(0)
#define P2SEL_INIT (0)
#define P2OUT_INIT (0)

/*---------------------------------------------------------------------------*/
// Port 4
/*---------------------------------------------------------------------------*/

#define P4DIR_INIT ~(0)
#define P4SEL_INIT (0)
#define P4OUT_INIT (0)

#define MIMO_SDN_BIT BIT0
#define PDIR_MIMO_SDN P4DIR
#define PSEL_MIMO_SDN P4SEL
#define POUT_MIMO_SDN P4OUT
#define PIN_MIMO_SDN P4IN

#define CORR_SDN_BIT BIT1
#define PDIR_CORR_SDN P4DIR
#define PSEL_CORR_SDN P4SEL
#define POUT_CORR_SDN P4OUT
#define PIN_CORR_SDN P4IN

#define SUM_SDN_BIT BIT2
#define PDIR_SUM_SDN P4DIR
#define PSEL_SUM_SDN P4SEL
#define POUT_SUM_SDN P4OUT
#define PIN_SUM_SDN P4IN

#define COMP_PWR_BIT BIT3
#define PDIR_COMP_PWR P4DIR
#define PSEL_COMP_PWR P4SEL
#define POUT_COMP_PWR P4OUT
#define PIN_COMP_PWR P4IN

#define SW0_BIT BIT4
#define PDIR_SW0 P4DIR
#define PSEL_SW0 P4SEL
#define POUT_SW0 P4OUT
#define PIN_SW0 P4IN

#define SW1_BIT BIT5
#define PDIR_SW1 P4DIR
#define PSEL_SW1 P4SEL
#define POUT_SW1 P4OUT
#define PIN_SW1 P4IN

#define VCOM_PWR_BIT BIT6
#define PDIR_VCOM_PWR P4DIR
#define PSEL_VCOM_PWR P4SEL
#define POUT_VCOM_PWR P4OUT
#define PIN_VCOM_PWR P4IN

/*---------------------------------------------------------------------------*/
// Port 5
/*---------------------------------------------------------------------------*/

#define P5DIR_INIT ~(CORROUTQ_BIT | SSUM_BIT)
#define P5SEL_INIT (XIN_BIT | XOUT_BIT)
#define P5OUT_INIT (0)

#define CORROUTQ_BIT BIT0
#define PDIR_CORROUTQ P5DIR
#define PSEL_CORROUTQ P5SEL
#define POUT_CORROUTQ P5OUT
#define PIN_CORROUTQ P5IN

#define SSUM_BIT BIT1
#define PDIR_SSUM P5DIR
#define PSEL_SSUM P5SEL
#define POUT_SSUM P5OUT
#define PIN_SSUM P5IN

#define XIN_BIT BIT4
#define PDIR_XIN P5DIR
#define PSEL_XIN P5SEL
#define POUT_XIN P5OUT
#define PIN_XIN P5IN

#define XOUT_BIT BIT5
#define PDIR_XOUT P5DIR
#define PSEL_XOUT P5SEL
#define POUT_XOUT P5OUT
#define PIN_XOUT P5IN

/*---------------------------------------------------------------------------*/
// Port 6
/*---------------------------------------------------------------------------*/

#define P6DIR_INIT ~(VSIG1_BIT | VSIG2_BIT | RXMIMO_BIT | CORROUTI_BIT)
#define P6SEL_INIT (0)
#define P6OUT_INIT (0)

#define VSIG1_BIT BIT0
#define PDIR_VSIG1 P6DIR
#define PSEL_VSIG1 P6SEL
#define POUT_VSIG1 P6OUT
#define PIN_VSIG1 P6IN

#define VSIG2_BIT BIT1
#define PDIR_VSIG2 P6DIR
#define PSEL_VSIG2 P6SEL
#define POUT_VSIG2 P6OUT
#define PIN_VSIG2 P6IN

#define RXMIMO_BIT BIT2
#define PDIR_RXMIMO P6DIR
#define PSEL_RXMIMO P6SEL
#define POUT_RXMIMO P6OUT
#define PIN_RXMIMO P6IN

#define CORROUTI_BIT BIT3
#define PDIR_CORROUTI P6DIR
#define PSEL_CORROUTI P6SEL
#define POUT_CORROUTI P6OUT
#define PIN_CORROUTI P6IN

/*---------------------------------------------------------------------------*/
// Port J
/*---------------------------------------------------------------------------*/

#define PJDIR_INIT ~(DBG_BIT)
#define PJOUT_INIT (0)

#define DBG_BIT BIT2
#define PDIR_DBG PJDIR
#define POUT_DBG PJOUT
#define PIN_DBG PJIN

#define LED_BIT BIT3
#define PDIR_LED PJDIR
#define POUT_LED PJOUT
#define PIN_LED PJIN

/*---------------------------------------------------------------------------*/
// Port init macro
/*---------------------------------------------------------------------------*/

#define IO_INIT() \
		P1OUT=P1OUT_INIT; P1SEL=P1SEL_INIT; P1DIR=P1DIR_INIT;\
		P2OUT=P2OUT_INIT; P2SEL=P2SEL_INIT; P2DIR=P2DIR_INIT;\
		P4OUT=P4OUT_INIT; P4SEL=P4SEL_INIT; P4DIR=P4DIR_INIT;\
		P5OUT=P5OUT_INIT; P5SEL=P5SEL_INIT; P5DIR=P5DIR_INIT;\
		P6OUT=P6OUT_INIT; P6SEL=P6SEL_INIT; P6DIR=P6DIR_INIT;\
		PJOUT=PJOUT_INIT; PJDIR=PJDIR_INIT;


#endif /* PINDEF_H_ */
