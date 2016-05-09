/*
 * lpstd.h
 *
 *  Created on: Jan 12, 2014
 *      Author: anparks
 */

#ifndef LPSTD_H_
#define LPSTD_H_

#include <stdint.h>

#define BITSET(reg,bit) reg|=(bit)
#define BITCLR(reg,bit) reg&=~(bit)
#define BITTOG(reg,bit) reg^=(bit)

typedef enum{
	FALSE=0,
	TRUE=1
} BOOL;

#endif /* LPSTD_H_ */
