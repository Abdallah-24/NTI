/*
 * SSD_config.h
 *
 *  Created on: Feb 1, 2023
 *      Author: DELL
 */

#ifndef SSD_SSD_CONFIG_H_
#define SSD_SSD_CONFIG_H_

/*
 * Please choose:
 * 		SSD_LED_PORT		: PORTA_ID 		......	 PORTD_ID
 * 		SSD_LED_PIN 		: PIN0			......	 PIN7
 */

#define SSD_LED_A_PORT			PORTA
#define SSD_LED_A_PIN			PIN1

#define SSD_LED_B_PORT			PORTA
#define SSD_LED_B_PIN			PIN2

#define SSD_LED_C_PORT			PORTA
#define SSD_LED_C_PIN			PIN3

#define SSD_LED_D_PORT			PORTA
#define SSD_LED_D_PIN			PIN4

#define SSD_LED_E_PORT			PORTA
#define SSD_LED_E_PIN			PIN5

#define SSD_LED_F_PORT			PORTA
#define SSD_LED_F_PIN			PIN6

#define SSD_LED_G_PORT			PORTA
#define SSD_LED_G_PIN			PIN7

#define SSD_LED_DOT_PORT		PORTA
#define SSD_LED_DOT_PIN			PIN8

#define SSD_LED_1_EN_PORT		PORTA
#define SSD_LED_1_EN_PIN		PIN9

#define SSD_LED_2_EN_PORT		PORTA
#define SSD_LED_2_EN_PIN		PIN10

#define SSD_DISPLAY_TIME		50		// 50 for 1 second

#endif /* SSD_SSD_CONFIG_H_ */
