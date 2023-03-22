/*
 * PB_int.h
 *
 *  Created on: Feb 2, 2023
 *      Author: DELL
 */

#ifndef PB_PB_INT_H_
#define PB_PB_INT_H_

typedef enum
{
	ACTIVE_LOW,
	ACTIVE_HIGH
}Active_t;

typedef struct PushButton
{
	u8 			PB_ID;
	u8 			PB_Port;
	u8 			PB_Pin;
	Active_t 	PB_ActiveMode;
	u8			PB_InitState;
}PB_t;

/****************      Public Macros     ****************/
#define NOT_PRESSED_AL				1
#define PRESSED_AL					0

#define NOT_PRESSED_AH				0
#define PRESSED_AH					1

/***************   Function Prototypes   ****************/

void	H_PB_voidinit	(const PB_t * psPB);
void	H_PB_voidread	(const PB_t * psPB, u8 * pReturnVal);
void	H_PB_voidread_1	(PB_t * psPB, u8 * pReturnVal);


#endif /* PB_PB_INT_H_ */
