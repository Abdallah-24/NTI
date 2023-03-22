/*
 * UART_config.h
 *
 *  Created on: Feb 21, 2023
 *      Author: dell
 */

#ifndef UART_UART_CONFIG_H_
#define UART_UART_CONFIG_H_

//Config Character size Length (5 , 6 , 7 , 8)
#define UART_DATA_SIZE        UART_SIZE8
//Config Parity (Even , Odd , No parity)
#define UART_PARITY_MODE      UART_PARITY_DISABLE
//Config No of Stop Bits
#define UART_STOP_BIT_NUM     UART_STOP_BIT1
//Config BR
#define UART_BAUD_RATE        UART_BAUD_RATE_16MHZ_9600
//Config Polling or Interrupt
#define UART_INTERRUPT_MODE   UART_DISABLE_INTERRUPT

#endif /* UART_UART_CONFIG_H_ */
