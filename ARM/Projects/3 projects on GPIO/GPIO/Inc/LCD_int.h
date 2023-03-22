/*
 * LCD_int.h
 *
 *  Created on: Feb 5, 2023
 *      Author: DELL
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_

/****************      Public Macros     ****************/


/***************   Function Prototypes   ****************/
void H_LCD_void_init				(void);
void H_LCD_void_clearRaw1			(void);
void H_LCD_void_clearRaw2			(void);
void H_LCD_void_clear				(void);
void H_LCD_void_sendCommand			(u8   		Copy_u8Command);
void H_LCD_void_sendData			(u8   		Copy_u8Data);
void H_LCD_void_sendString			(const s8 * Copy_pu8String);
void H_LCD_void_sendIntNum			(s32  		Copy_s32Num);
void H_LCD_void_goToXY				(u8 		Copy_u8Row,			u8 Copy_u8Col);
void H_LCD_void_creatCustomChar		(const u8 * Copy_pu8CharPattern,u8 Copy_u8CharCode);
void H_LCD_void_displayCustomChar	(u8 		Copy_u8CharCode);

#endif /* LCD_LCD_INT_H_ */
