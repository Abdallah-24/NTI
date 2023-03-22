/*
 * LCD_config.h
 *
 *  Created on: Feb 5, 2023
 *      Author: DELL
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_

/*
 * choose LCD_MODE:
 * 					LCD_4BIT_MODE_
 * 					LCD_8BIT_MODE_
 */
#define LCD_MODE			LCD_4BIT_MODE_

#define LCD_D7_PORT			PORTA
#define LCD_D7_PIN			PIN6

#define LCD_D6_PORT			PORTA
#define LCD_D6_PIN			PIN5

#define LCD_D5_PORT			PORTA
#define LCD_D5_PIN			PIN4

#define LCD_D4_PORT			PORTA
#define LCD_D4_PIN			PIN3

#if(LCD_MODE == LCD_8BIT_MODE_)
#define LCD_D3_PORT
#define LCD_D3_PIN

#define LCD_D2_PORT
#define LCD_D2_PIN

#define LCD_D1_PORT
#define LCD_D1_PIN

#define LCD_D0_PORT
#define LCD_D0_PIN
#endif

#define LCD_EN_PORT			PORTA
#define LCD_EN_PIN			PIN2

#define LCD_RS_PORT			PORTA
#define LCD_RS_PIN			PIN1


#endif /* LCD_LCD_CONFIG_H_ */
