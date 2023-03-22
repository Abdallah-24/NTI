/*
 * PB_prg.c
 *
 *  Created on: Feb 2, 2023
 *      Author: DELL
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PB_pvt.h"
#include "PB_config.h"
#include "PB_int.h"
#include "Delay.h"


/****************  Function Definition  ****************/
void	H_PB_voidinit	(const PB_t * psPB)
{
	//	Direction for PB is INPUT PULL UP
	M_DIO_void_setPinDir(psPB -> PB_Port, psPB -> PB_Pin, IN_PULL_UP_DOWN);
	M_DIO_void_setPinVal(PORTA, PIN0, DIO_HIGH);
}
void	H_PB_voidread	(const PB_t * psPB, u8 * pReturnVal)
{
	u8 Local_u8Read;
	if(psPB -> PB_ActiveMode == ACTIVE_LOW)
	{
		* pReturnVal = NOT_PRESSED_AL;
		M_DIO_void_getPinVal(psPB -> PB_Port, psPB -> PB_Pin,& Local_u8Read);
		if(Local_u8Read == PRESSED_AL)
		{
			_delay_ms(200);
			M_DIO_void_getPinVal(psPB -> PB_Port, psPB -> PB_Pin,& Local_u8Read);
			if(Local_u8Read == PRESSED_AL)
			{
				while(Local_u8Read == PRESSED_AL)
				{
					M_DIO_void_getPinVal(psPB -> PB_Port, psPB -> PB_Pin,& Local_u8Read);
				}
				* pReturnVal = PRESSED_AL;
				return;
			}
			else
			{}
		}
		else
		{}
	}
	else if(psPB -> PB_ActiveMode == ACTIVE_HIGH)
	{
		* pReturnVal = NOT_PRESSED_AH;
		M_DIO_void_getPinVal(psPB -> PB_Port, psPB -> PB_Pin,& Local_u8Read);
		if(Local_u8Read == PRESSED_AH)
		{
			_delay_ms(200);
			M_DIO_void_getPinVal(psPB -> PB_Port, psPB -> PB_Pin,& Local_u8Read);
			if(Local_u8Read == PRESSED_AH)
			{
				while(Local_u8Read == PRESSED_AH)
				{
					M_DIO_void_getPinVal(psPB -> PB_Port, psPB -> PB_Pin,& Local_u8Read);
				}
				* pReturnVal = PRESSED_AH;
				return;
			}
			else
			{}
		}
		else
		{}
	}
}
void	H_PB_voidread_1	(PB_t * psPB, u8 * pReturnVal)
{
	u8 Local_u8Read;
	if(psPB -> PB_ActiveMode == ACTIVE_LOW)
	{
		* pReturnVal = NOT_PRESSED_AL;
		M_DIO_void_getPinVal(psPB -> PB_Port, psPB -> PB_Pin,& Local_u8Read);
		if(Local_u8Read != psPB -> PB_InitState)
		{
			_delay_ms(50);
			M_DIO_void_getPinVal(psPB -> PB_Port, psPB -> PB_Pin,& Local_u8Read);
			if(Local_u8Read == PRESSED_AL)
			{
				* pReturnVal = PRESSED_AL;
				psPB -> PB_InitState = PRESSED_AL;
				return;
			}
			else
			{
				psPB -> PB_InitState = NOT_PRESSED_AL;
				return;
			}
		}
		else
		{}
	}
}

