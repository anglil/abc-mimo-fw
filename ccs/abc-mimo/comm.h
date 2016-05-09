#include <stdint.h>

/*
 * comm.h
 *
 *  Created on: Jan 12, 2014
 *      Author: anparks
 */

#ifndef COMM_H_
#define COMM_H_

#define COMM_MIMO_ON()	BITSET(POUT_MIMO_SDN, MIMO_SDN_BIT);
#define COMM_CORR_ON()	BITSET(POUT_CORR_SDN, CORR_SDN_BIT);
#define COMM_SUM_ON()	BITSET(POUT_SUM_SDN, SUM_SDN_BIT);
#define COMM_COMP_ON()	BITSET(POUT_COMP_PWR, COMP_PWR_BIT);
#define COMM_VCOM_ON()	BITSET(POUT_VCOM_PWR, VCOM_PWR_BIT);

#define COMM_MIMO_OFF()	BITCLR(POUT_MIMO_SDN, MIMO_SDN_BIT);
#define COMM_CORR_OFF()	BITCLR(POUT_CORR_SDN, CORR_SDN_BIT);
#define COMM_SUM_OFF()	BITCLR(POUT_SUM_SDN, SUM_SDN_BIT);
#define COMM_COMP_OFF()	BITCLR(POUT_COMP_PWR, COMP_PWR_BIT);
#define COMM_VCOM_OFF()	BITCLR(POUT_VCOM_PWR, VCOM_PWR_BIT);


void COMM_ALL_ON();
void COMM_ALL_OFF();
void COMM_SW_POS(uint8_t pos);
void COMM_INIT_CHIPGEN();
void COMM_SET_CHIPGEN_DIV(uint16_t div);
void COMM_START_CHIPGEN();
void COMM_STOP_CHIPGEN();
void COMM_RST_RATE(uint16_t per, uint16_t div);

#endif /* COMM_H_ */
