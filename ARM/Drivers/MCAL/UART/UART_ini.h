/*
 * UART_ini.h
 *
 *  Created on: Feb 21, 2023
 *      Author: dell
 */

#ifndef UART_UART_INI_H_
#define UART_UART_INI_H_

void M_UART_void_Init(void);
void  M_UART_void_sendByte(u8 Byte);
u8 M_UART_u8_recieveByte(void );

void M_UART_u8_sendString(u8 *ptr);

void M_UART_void_EnableInt(void);
void M_UART_void_DisableInt(void);
void M_UART_void_setCallBack(void);


#endif /* UART_UART_INI_H_ */
