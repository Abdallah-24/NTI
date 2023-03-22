/*
 * SSD_prg.c
 *
 *  Created on: Feb 1, 2023
 *      Author: DELL
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_pvt.h"
#include "SSD_config.h"
#include "SSD_int.h"
#include "Delay.h"

/****************  Function Definition  ****************/
void	H_SSD_voidinit			(void)
{
	/* Set all SSD LEDs as OUTPUT */
	M_DIO_void_setPinDir(SSD_LED_A_PORT, SSD_LED_A_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(SSD_LED_B_PORT, SSD_LED_B_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(SSD_LED_C_PORT, SSD_LED_C_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(SSD_LED_D_PORT, SSD_LED_D_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(SSD_LED_E_PORT, SSD_LED_E_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(SSD_LED_F_PORT, SSD_LED_F_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(SSD_LED_G_PORT, SSD_LED_G_PIN , OUT_10MHZ_PP);
	M_DIO_void_setPinDir(SSD_LED_DOT_PORT, SSD_LED_DOT_PIN , OUT_10MHZ_PP);
	/* Set SSD_1 EN pin as OUTPUT */
	M_DIO_void_setPinDir(SSD_LED_1_EN_PORT, SSD_LED_1_EN_PIN , OUT_10MHZ_PP);
	/* Set SSD_2 EN pin as OUTPUT */
	M_DIO_void_setPinDir(SSD_LED_2_EN_PORT, SSD_LED_2_EN_PIN , OUT_10MHZ_PP);
	/* Disable 2 SSDs */
	M_DIO_void_setPinVal(SSD_LED_1_EN_PORT, SSD_LED_1_EN_PIN , DIO_LOW );
	M_DIO_void_setPinVal(SSD_LED_2_EN_PORT, SSD_LED_2_EN_PIN , DIO_LOW );
}
void	H_SSD_voiddisplayNumber	(u8 number)
{
	u8  Local_u8Dig1 = 0, Local_u8Dig2 = 0;
	u32 Local_u32Counter = 0;
	if(number < 100)
	{
		Local_u8Dig1 = number % 10; // number = 23  -> 2.3   -> Local_u8Dig1 = 3
		Local_u8Dig2 = number / 10;
		for(Local_u32Counter = 0 ; Local_u32Counter < SSD_DISPLAY_TIME ; Local_u32Counter++)
		{
			/* Enable  SSD_1 , Disable SSD_2 */
//			M_DIO_void_setPinVal(SSD_LED_1_EN_PORT, SSD_LED_1_EN_PIN , DIO_HIGH);
//			M_DIO_void_setPinVal(SSD_LED_2_EN_PORT, SSD_LED_2_EN_PIN , DIO_LOW );
			/* Select number */
			switch(Local_u8Dig1)
			{
			case 0:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_LOW );
				break;
			case 1:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_LOW );
				break;
			case 2:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
				break;
			case 3:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
				break;
			case 4:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
				break;
			case 5:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
				break;
			case 6:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
				break;
			case 7:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_LOW );
				break;
			case 8:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
				break;
			case 9:
				M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
				M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
				M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
				break;
			default : /* do nothing */ break;
			}

			/* delay 20 ms */
//			_delay_ms(10);
//			if(Local_u8Dig2 != 0)
//			{
//				/* Disable  SSD_1 , Enable SSD_2 */
//				M_DIO_void_setPinVal(SSD_LED_1_EN_PORT, SSD_LED_1_EN_PIN , DIO_HIGH);
//				/* Select number */
//				switch(Local_u8Dig2)
//				{
//				case 0:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_LOW );
//					break;
//				case 1:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_LOW );
//					break;
//				case 2:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
//					break;
//				case 3:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
//					break;
//				case 4:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
//					break;
//				case 5:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
//					break;
//				case 6:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
//					break;
//				case 7:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_LOW );
//					break;
//				case 8:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
//					break;
//				case 9:
//					M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN , DIO_LOW );
//					M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN , DIO_HIGH);
//					M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN , DIO_HIGH);
//					break;
//				default : /* do nothing */ break;
//				}
//				/* delay 20 ms */
//				_delay_ms(10);
//			}
//			else
//			{
//				_delay_ms(10);
//			}
		}

	}
	else
	{
		/* do nothing */
	}
}





