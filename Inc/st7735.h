/*
 * st7735.h
 *
 *  Created on: 16 бер. 2019 р.
 *      Author: Andriy Honcharenko
 *        Blog: https://stm32withoutfear.blogspot.com
 */

#ifndef __ST7735_H__
#define __ST7735_H__

#include "fonts.h"
#include "st7735_cfg.h"
#include <stdbool.h>

extern SPI_HandleTypeDef ST7735_SPI_PORT;

#define ST7735_MADCTL_MY  0x80
#define ST7735_MADCTL_MX  0x40
#define ST7735_MADCTL_MV  0x20
#define ST7735_MADCTL_RGB 0x00
#define ST7735_MADCTL_BGR 0x08

// AliExpress/eBay 1.8" display, default orientation
#ifdef ST7735_1_8_DEFAULT_ORIENTATION
#define ST7735_IS_160X128		1
#define ST7735_WIDTH  			128
#define ST7735_HEIGHT 			160
#define ST7735_XSTART 			0
#define ST7735_YSTART 			0
#define ST7735_DATA_ROTATION 	(ST7735_MADCTL_MX | ST7735_MADCTL_MY)
#endif //ST7735_1_8_DEFAULT_ORIENTATION

// WaveShare ST7735S-based 1.8" display, default orientation
#ifdef ST7735S_1_8_DEFAULT_ORIENTATION
#define ST7735_IS_160X128 		1
#define ST7735_WIDTH  			128
#define ST7735_HEIGHT 			160
#define ST7735_XSTART 			2
#define ST7735_YSTART 			1
#define	ST7735_DATA_ROTATION	(ST7735_MADCTL_MX | ST7735_MADCTL_MY | ST7735_MADCTL_RGB)
#endif //ST7735S_1_8_DEFAULT_ORIENTATION

// 1.44" display, default orientation
#ifdef ST7735_1_44_DEFAULT_ORIENTATION
#define ST7735_IS_128X128 		1
#define ST7735_WIDTH  			128
#define ST7735_HEIGHT 			128
#define ST7735_XSTART 			2
#define ST7735_YSTART 			3
//#define ST7735_VALUE_ROTATION	0
#define ST7735_DATA_ROTATION 	(ST7735_MADCTL_MX | ST7735_MADCTL_MY | ST7735_MADCTL_BGR)
#endif //ST7735_1_44_DEFAULT_ORIENTATION

// mini 160x80 display (it's unlikely you want the default orientation)
#ifdef ST7735_MINI_DEFAULT_ORIENTATION
#define ST7735_IS_160X80 		1
#define ST7735_XSTART 			26
#define ST7735_YSTART 			1
#define ST7735_WIDTH  			80
#define ST7735_HEIGHT 			160
//#define ST7735_VALUE_ROTATION	0
#define ST7735_DATA_ROTATION 	(ST7735_MADCTL_MX | ST7735_MADCTL_MY | ST7735_MADCTL_BGR)
#endif //ST7735_MINI_DEFAULT_ORIENTATION
/****************************/

#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09

#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13

#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E

#define ST7735_PTLAR   0x30
#define ST7735_COLMOD  0x3A
#define ST7735_MADCTL  0x36

#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6

#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5

#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD

#define ST7735_PWCTR6  0xFC

#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1

// Color definitions
#define	ST7735_BLACK   0x0000
#define	ST7735_BLUE    0x001F
#define	ST7735_RED     0xF800
#define	ST7735_GREEN   0x07E0
#define ST7735_CYAN    0x07FF
#define ST7735_MAGENTA 0xF81F
#define ST7735_YELLOW  0xFFE0
#define ST7735_WHITE   0xFFFF

void ST7735_Backlight_On(void);
void ST7735_Backlight_Off(void);
void ST7735_Init(void);
void ST7735_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void ST7735_DrawString(uint16_t x, uint16_t y, const char* str, FontDef font, uint16_t color, uint16_t bgcolor);
void ST7735_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void ST7735_FillScreen(uint16_t color);
void ST7735_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);
void ST7735_InvertColors(bool invert);
void ST7735_DrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void ST7735_DrawCircleHelper( int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
void ST7735_FillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void ST7735_FillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
void ST7735_DrawEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint16_t color);
void ST7735_FillEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint16_t color);
void ST7735_DrawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void ST7735_DrawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
void ST7735_FillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
void ST7735_DrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void ST7735_FillTriangle( int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void ST7735_DrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void ST7735_DrawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void ST7735_DrawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
void ST7735_SetRotation(uint8_t m);
uint8_t ST7735_GetRotation(void);
int16_t ST7735_GetHeight(void);
int16_t ST7735_GetWidth(void);


#endif // __ST7735_H__
