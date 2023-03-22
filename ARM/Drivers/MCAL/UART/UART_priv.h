/*
 * UART_priv.h
 *
 *  Created on: Feb 21, 2023
 *      Author: dell
 */

#ifndef UART_UART_PRIV_H_
#define UART_UART_PRIV_H_

typedef	struct
{
	volatile	u32		USART_SR ;
	volatile	u32		USART_DR ;
	volatile	u32		USART_BRR ;
	volatile	u32    USART_CR1 ;
	volatile	u32    USART_CR2 ;
	volatile	u32    USART_CR3 ;
	volatile	u32    USART_GTPR ;

}USART_Type;

#define		USART1 	((USART_Type *)0x40013800)


#endif /* UART_UART_PRIV_H_ */
