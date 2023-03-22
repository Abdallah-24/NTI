/*
 * LCD_prg.c
 *
 *  Created on: Feb 5, 2023
 *      Author: DELL
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_pvt.h"
#include "LCD_config.h"
#include "LCD_int.h"
#include "Delay.h"

/****************  Function Definition  ****************/
void H_LCD_void_init				(void)
{
	_delay_ms(30);
	// Set direction
	// for RS , EN
	M_DIO_void_setPinDir(LCD_RS_PORT, LCD_RS_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(LCD_EN_PORT, LCD_EN_PIN , OUT_10MHZ_PP);
	// for D4 : D7
	M_DIO_void_setPinDir(LCD_D4_PORT, LCD_D4_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(LCD_D5_PORT, LCD_D5_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(LCD_D6_PORT, LCD_D6_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(LCD_D7_PORT, LCD_D7_PIN , OUT_10MHZ_PP);
#if(LCD_MODE == LCD_8BIT_MODE_)
	// for D0 : D3

#endif
	// Send init sequence
#if(LCD_MODE == LCD_8BIT_MODE_)
	_delay_ms(35);
	H_LCD_void_sendCommand(LCD_8BIT_MODE_2LINES_5X7);

#elif(LCD_MODE == LCD_4BIT_MODE_)
	// RS = 0
	M_DIO_void_setPinVal(LCD_RS_PORT, LCD_RS_PIN, DIO_LOW);
	//deActive Enable , E -> 0
	M_DIO_void_setPinVal(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	//Prepare data
	M_DIO_void_setPinVal(LCD_D4_PORT, LCD_D4_PIN , DIO_LOW);
	M_DIO_void_setPinVal(LCD_D5_PORT, LCD_D5_PIN , DIO_HIGH);
	M_DIO_void_setPinVal(LCD_D6_PORT, LCD_D6_PIN , DIO_LOW);
	M_DIO_void_setPinVal(LCD_D7_PORT, LCD_D7_PIN , DIO_LOW);
	//Step 4 : activate Enable , E -> 1
	M_DIO_void_setPinVal(LCD_EN_PORT, LCD_EN_PIN, DIO_HIGH);
	_delay_ms(1);
	//deActive Enable , E -> 0
	M_DIO_void_setPinVal(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	//Step 5 : Delay to allow LCD to Process
	_delay_ms(5);
	H_LCD_void_sendCommand(LCD_4BIT_MODE_2LINES_5X7);

#else
#error("Wrong LCD_MODE!")
#endif
	// Display ON/OFF
	H_LCD_void_sendCommand(LCD_DISPLAYON_CUROFF);
	// Clear display
	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY);
	// Entry Mode set
	H_LCD_void_sendCommand(LCD_ENTERY_MODE_SET);
}
void H_LCD_void_clear				(void)
{
	H_LCD_void_sendCommand(LCD_CLEAR_DISPLAY);
}
void H_LCD_void_clearRaw1			(void)
{
	H_LCD_void_goToXY(0,0);
	H_LCD_void_sendString("               ");
	H_LCD_void_goToXY(0,0);
}
void H_LCD_void_clearRaw2			(void)
{
	H_LCD_void_goToXY(1,0);
	H_LCD_void_sendString("               ");
	H_LCD_void_goToXY(1,0);
}
void H_LCD_void_sendCommand			(u8   		Copy_u8Command)
{
	// Step 1: RS -> 0
	M_DIO_void_setPinVal(LCD_RS_PORT, LCD_RS_PIN, DIO_LOW);
	// Step 2:
	H_LCD_void_writeNlatch(Copy_u8Command);
}
void H_LCD_void_sendData			(u8   		Copy_u8Data)
{
	// Step 1: RS -> 1
	M_DIO_void_setPinVal(LCD_RS_PORT, LCD_RS_PIN, DIO_HIGH);
	// Step 2:
	H_LCD_void_writeNlatch(Copy_u8Data);
}
void H_LCD_void_sendString			(const s8 * Copy_pu8String)
{
	while(* Copy_pu8String)
	{
		H_LCD_void_sendData(* Copy_pu8String++);
	}
}
void H_LCD_void_sendIntNum			(s32  		Copy_s32Num) //569
{
    s32 Local_s32Num 	= Copy_s32Num;
    s8 Local_s8len 		= 0;
    u8 Local_u8Negflag  = 0;
    u8 Local_pStr[10] 	= {0};
    if(Copy_s32Num == 0)
    {
    	H_LCD_void_sendData('0');
    }
    else
    {
        if(Copy_s32Num < 0)
        {
        	Copy_s32Num  = Copy_s32Num * (-1);
        	Local_u8Negflag = 1;
        }

		while(Local_s32Num != 0)
		{
			Local_s32Num /= 10;
			Local_s8len++;
		}
		for(int i = (Local_s8len-1) + Local_u8Negflag ; i >= 0 + Local_u8Negflag ; i--)
		{
			Local_pStr[i] = (Copy_s32Num % 10) + 48;
			Copy_s32Num /= 10;
		}
		Local_pStr[Local_s8len + Local_u8Negflag] = 0;
		if(Local_u8Negflag == 1)
		{
			Local_pStr[0] = '-';
		}
		H_LCD_void_sendString(Local_pStr);

    }

}
void H_LCD_void_goToXY				(u8 		Copy_u8Row,			u8 Copy_u8Col)
{
	if(Copy_u8Row >= 0 || Copy_u8Row == 1) // check on Row
	{
		if(Copy_u8Col >= 0 && Copy_u8Col <= 15)
		{
			switch(Copy_u8Row)
			{
			case 0:
				H_LCD_void_sendCommand(LCD_SET_R0C0_ + Copy_u8Col);
				break;
			case 1:
				H_LCD_void_sendCommand(LCD_SET_R1C0_ + Copy_u8Col);
				break;
			}
		}
	}
}
void H_LCD_void_creatCustomChar		(const u8 * Copy_pu8CharPattern,u8 Copy_u8CharCode)
{
    u8 iteration1;
    static u8 add = 64;
    /*DDRAM-->CGRAM*/
    H_LCD_void_sendCommand(add);
	for(iteration1=0 ; iteration1<8 ; iteration1++)
	{
		H_LCD_void_sendData(Copy_pu8CharPattern[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	H_LCD_void_sendCommand(128);
	add+=8;
}
void H_LCD_void_displayCustomChar	(u8 		Copy_u8CharCode)
{
	H_LCD_void_sendData(Copy_u8CharCode);
}
static void H_LCD_void_writeNlatch(u8 Copy_u8Byte)
{
#if(LCD_MODE == LCD_8BIT_MODE_)
	//Step 1 : Prepare Data
	M_DIO_void_setPinVal(LCD_D0_PORT, LCD_D0_PIN , GET_BIT(Copy_u8Byte, 0));
	M_DIO_void_setPinVal(LCD_D1_PORT, LCD_D1_PIN , GET_BIT(Copy_u8Byte, 1));
	M_DIO_void_setPinVal(LCD_D2_PORT, LCD_D2_PIN , GET_BIT(Copy_u8Byte, 2));
	M_DIO_void_setPinVal(LCD_D3_PORT, LCD_D3_PIN , GET_BIT(Copy_u8Byte, 3));
	M_DIO_void_setPinVal(LCD_D4_PORT, LCD_D4_PIN , GET_BIT(Copy_u8Byte, 4));
	M_DIO_void_setPinVal(LCD_D5_PORT, LCD_D5_PIN , GET_BIT(Copy_u8Byte, 5));
	M_DIO_void_setPinVal(LCD_D6_PORT, LCD_D6_PIN , GET_BIT(Copy_u8Byte, 6));
	M_DIO_void_setPinVal(LCD_D7_PORT, LCD_D7_PIN , GET_BIT(Copy_u8Byte, 7));
	//Step 2 : Active Enable , E -> 1
	M_DIO_void_setPinVal(LCD_RS_PORT, LCD_RS_PIN, DIO_HIGH);
	//Step 3 : Delay for 1ms
	_delay_ms(1);
	//Step 4 : Deactivate Enable , E -> 0
	M_DIO_void_setPinVal(LCD_RS_PORT, LCD_RS_PIN, DIO_LOW);
	//Step 5 : Delay to allow LCD to Process
	_delay_ms(5);
#elif(LCD_MODE == LCD_4BIT_MODE_)
////////////////////////////////////  1 -> Send the four mostsegn bits
	//deActive Enable , E -> 0
		M_DIO_void_setPinVal(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	//Step 1 : Prepare Data
	M_DIO_void_setPinVal(LCD_D4_PORT, LCD_D4_PIN , GET_BIT(Copy_u8Byte, 4));
	M_DIO_void_setPinVal(LCD_D5_PORT, LCD_D5_PIN , GET_BIT(Copy_u8Byte, 5));
	M_DIO_void_setPinVal(LCD_D6_PORT, LCD_D6_PIN , GET_BIT(Copy_u8Byte, 6));
	M_DIO_void_setPinVal(LCD_D7_PORT, LCD_D7_PIN , GET_BIT(Copy_u8Byte, 7));
	//Step 2 : Active Enable , E -> 1
	M_DIO_void_setPinVal(LCD_EN_PORT, LCD_EN_PIN, DIO_HIGH);
	//Step 3 : Delay for 1ms
	_delay_ms(1);
	//Step 4 : Deactivate Enable , E -> 0
	M_DIO_void_setPinVal(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	//Step 5 : Delay to allow LCD to Process
	_delay_ms(5);
////////////////////////////////////  2	-> Send the four leastsegn bits
	//deActive Enable , E -> 0
		M_DIO_void_setPinVal(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	//Step 1 : Prepare Data
	M_DIO_void_setPinVal(LCD_D4_PORT, LCD_D4_PIN , GET_BIT(Copy_u8Byte, 0));
	M_DIO_void_setPinVal(LCD_D5_PORT, LCD_D5_PIN , GET_BIT(Copy_u8Byte, 1));
	M_DIO_void_setPinVal(LCD_D6_PORT, LCD_D6_PIN , GET_BIT(Copy_u8Byte, 2));
	M_DIO_void_setPinVal(LCD_D7_PORT, LCD_D7_PIN , GET_BIT(Copy_u8Byte, 3));
	//Step 2 : Active Enable , E -> 1
	M_DIO_void_setPinVal(LCD_EN_PORT, LCD_EN_PIN, DIO_HIGH);
	//Step 3 : Delay for 1ms
	_delay_ms(1);
	//Step 4 : Deactivate Enable , E -> 0
	M_DIO_void_setPinVal(LCD_EN_PORT, LCD_EN_PIN, DIO_LOW);
	//Step 5 : Delay to allow LCD to Process
	_delay_ms(5);

#else
#error("Wrong LCD_MODE!")
#endif
}
