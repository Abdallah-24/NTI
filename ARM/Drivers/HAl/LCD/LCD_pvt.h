/*
 * LCD_pvt.h
 *
 *  Created on: Feb 5, 2023
 *      Author: DELL
 */

#ifndef LCD_LCD_PVT_H_
#define LCD_LCD_PVT_H_

/*********************** Private Macros ***********************/
#define LCD_4BIT_MODE_				0
#define LCD_8BIT_MODE_				1

#define LCD_4BIT_MODE_2LINES_5X7			0x28
#define LCD_8BIT_MODE_2LINES_5X7			0x38
#define LCD_DISPLAYON_CURON_BBLINKOFF		0x0E
#define LCD_DISPLAYON_CUROFF				0x0C
#define LCD_CLEAR_DISPLAY					0x01
#define LCD_ENTERY_MODE_SET					0x06 // increment position and disable shift
#define LCD_SET_R0C0_						0x80
#define LCD_SET_R1C0_						0xC0

/***************** Private Function Prototypes *****************/
static void H_LCD_void_writeNlatch(u8 Copy_u8Byte);

#endif /* LCD_LCD_PVT_H_ */
