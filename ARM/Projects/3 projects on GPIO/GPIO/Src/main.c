/*
 * main.c
 *
 *  Created on: ٠٢‏/٠٣‏/٢٠٢٣
 *      Author: abdal
 */
#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"PB_int.h"
#include	"SSD_int.h"
#include	"LCD_int.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"



#if 0
/******************* MACROS **********************/
#define OFF_STATE	0
#define ON_STATE	1

void main(void)
{
	/*****************  Initialization Part  ****************/

	u8 Local_u8Value = DIO_HIGH;
	u8 Local_u8State = ON_STATE;
	PB_t PB1 = {1,PORTA, PIN0, ACTIVE_LOW , NOT_PRESSED_AL};

	// System Clk init
	MRCC_voidSysClkInit();

	// Enable Per Clk "RCC" DIO_A
	MRCC_voidEnablePerClk(RCC_APB2,DIO_A);

	// Init PB
	H_PB_voidinit(& PB1);

	// Direction for A1 for LED is OUTPUT
	M_DIO_void_setPinDir(PORTA, PIN1, OUT_10MHZ_PP);


	while(1)
	{
		H_PB_voidread_1	(& PB1, &Local_u8Value);
		if(Local_u8Value == PRESSED_AL)
		{
			switch(Local_u8State)
			{
			case ON_STATE:
				M_DIO_void_setPinVal(PORTA, PIN1, DIO_HIGH);
				Local_u8State = OFF_STATE;
				break;
			case OFF_STATE:
				M_DIO_void_setPinVal(PORTA, PIN1, DIO_LOW);
				Local_u8State = ON_STATE;
				break;
			default: /* DO NOTHING */ break;
			}
		}
		else
		{
			/* DO NOTHING */
		}
	}
}
#endif

#if 1

void main(void)
{
	/*****************  Initialization Part  ****************/

	u8 Local_u8Value = DIO_HIGH;
	u8 Local_u8Num = 0;
	PB_t PB1 = {1,PORTA, PIN0, ACTIVE_LOW , NOT_PRESSED_AL};

	// System Clk init
	MRCC_voidSysClkInit();

	// Enable Per Clk "RCC" DIO_A
	MRCC_voidEnablePerClk(RCC_APB2,DIO_A);

	// Init PB
	H_PB_voidinit(& PB1);

	// Init SSD
	H_SSD_voidinit();


	while(1)
	{
		H_PB_voidread_1	(& PB1, &Local_u8Value);
		if(Local_u8Value == PRESSED_AL)
		{
			if(Local_u8Num < 9)
			{
				H_SSD_voiddisplayNumber(Local_u8Num++);
			}
			else
			{
				Local_u8Num = 0;
			}

		}
		else
		{
			/* DO NOTHING */
		}
	}
}
#endif

#if 0

void main(void)
{
	/*****************  Initialization Part  ****************/

	// System Clk init
	MRCC_voidSysClkInit();

	// Enable Per Clk "RCC" DIO_A
	MRCC_voidEnablePerClk(RCC_APB2,DIO_A);

	// Init LCD
	H_LCD_void_init();

	// Write on LCD
	H_LCD_void_sendString("  Hello World");
	while(1)
	{

	}
}
#endif
