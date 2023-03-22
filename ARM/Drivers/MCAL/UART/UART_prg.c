/*
 * UART_prg.c
 *
 *  Created on: Feb 21, 2023
 *      Author: dell
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_ini.h"
void M_UART_void_Init(void)
{

	 //USART DIV value
	 USART1->USART_BRR = 0x341; //for 8MHZ on APB2 bus

	 //USART RE BIT ENABLE
	 SET_BIT(USART1->USART_CR1,2);
	 //USART TE BIT ENABLE
	 SET_BIT(USART1->USART_CR1,3);
	 //USART UE BIT ENABLE
	 SET_BIT(USART1->USART_CR1,13);
}
void  M_UART_void_sendByte(u8 Byte)
{
	 USART1->USART_DR = Byte;
	 while (! GET_BIT(USART1-> USART_SR ,6));
}
 u8 M_UART_u8_recieveByte(void )
{
	 u8 Byte;
	 while (! GET_BIT(USART1-> USART_SR ,5));
	 Byte= USART1->USART_DR;
	 return Byte;
}
void M_UART_u8_sendString(u8 *ptr)
{
	while(*ptr)
	{
		M_UART_void_sendByte(*ptr);
		ptr++;
	}
}


