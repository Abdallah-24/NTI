/*
 * BIT_MATH.h
 *
 *  Created on: Jan 30, 2023
 *      Author: DELL
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*
 * REG = 0b11001010
 * BIT = 5
 *
 * * SET_BIT(REG , BIT) -> 		  REG |=  ( 0b00000001 << 5 )
 * 								  REG |=	0b00100000
 * 								  REG  =  REG | 0b00100000
 * 								  REG  =  0b11001010 | 0b00100000
 *
 * 						   					0b11001010
 * 						   								OR
 * 						   					0b00100000
 * 						   					----------
 * 						   		  REG  =	0b11101010
 * to be continue.....
 *
 * */

#define SET_BIT(REG , BIT)	REG |=  (1 << BIT)
#define CLR_BIT(REG , BIT)	REG &= ~(1 << BIT)
#define GET_BIT(REG , BIT)	((REG >> BIT) & 1)
#define TOG_BIT(REG , BIT)	REG ^=  (1 << BIT)

#endif /* BIT_MATH_H_ */
