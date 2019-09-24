/*******************************************************************************
 * File Name	: LCD.c                                                        *
 * Description	: Source file for LCD Module                                   *
 * Created on	: 9/23/2019 6:00 PM                                            *
 * Author		: Nancy                                                        *
 *******************************************************************************/



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define LCD_MODE_4_PIN		0
#define LCD_MODE_8_PIN		1
/*******************************************************************************/



/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include <util/delay.h>
#include "typedefs.h"
#include "bitwise.h"
#include "DIO.h"
#include "LCD_types.h"
#include "LCD.h"
#include "LCD_cfg.h"
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Implementation                               *
 *******************************************************************************/

void LCD_init(void)
{
#if (LCD_MODE_SELECTOR == LCD_MODE_8_PIN)
	DIO_SetPinDirection(LCD_PIN_D0, 1);
	DIO_SetPinDirection(LCD_PIN_D1, 1);
	DIO_SetPinDirection(LCD_PIN_D2, 1);
	DIO_SetPinDirection(LCD_PIN_D3, 1);
#endif

	DIO_SetPinDirection(LCD_PIN_D4, 1);
	DIO_SetPinDirection(LCD_PIN_D5, 1);
	DIO_SetPinDirection(LCD_PIN_D6, 1);
	DIO_SetPinDirection(LCD_PIN_D7, 1);
	DIO_SetPinDirection(LCD_PIN_RS, 1);
	DIO_SetPinDirection(LCD_PIN_RW, 1);
	DIO_SetPinDirection(LCD_PIN_E, 1);

#if(LCD_MODE_SELECTOR == LCD_MODE_8_PIN)
	/*
	 * init LCD in 8 pin mode
	 * 0x38 0b00111000 ==> 0b001<DataLength><NumofRow><Font5*7>--
	 * */
	LCD_sendCommand(0x38);
#elif (LCD_MODE_SELECTOR == LCD_MODE_4_PIN)
	/*
	 * init LCD in 4 pin mode
	 * 0x33
	 * 0x32
	 * 0x28 ==> 0b001<DataLength_4><NumofRow_2><Font5*7>--
	 * */
	LCD_sendCommand(0x33);
	LCD_sendCommand(0x32);
	LCD_sendCommand(0x28);
#endif
	/*
	 * 0x0E 0b00001110 ==> 0b00001<DisplayOn><CursorOn><Blink>
	 * 0x01 0b00000001 ==> 0b0000000<ClearDisplay>
	 */
	LCD_sendCommand(0x0E);
	LCD_sendCommand(LCD_CMD_CLEAR_SCREEN);
	_delay_ms(3);
}


void LCD_displayChar(uint8 u8Data)
{
	/* write data to data register */
	DIO_WritePin(LCD_PIN_RS,1);

	/*enter write mode*/
	DIO_WritePin(LCD_PIN_RW,0);

	/* apply output data on Bus*/
#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN

	DIO_WritePin(LCD_PIN_D0,GetBit(u8Data,0));
	DIO_WritePin(LCD_PIN_D1,GetBit(u8Data,1));
	DIO_WritePin(LCD_PIN_D2,GetBit(u8Data,2));
	DIO_WritePin(LCD_PIN_D3,GetBit(u8Data,3));
	DIO_WritePin(LCD_PIN_D4,GetBit(u8Data,4));
	DIO_WritePin(LCD_PIN_D5,GetBit(u8Data,5));
	DIO_WritePin(LCD_PIN_D6,GetBit(u8Data,6));
	DIO_WritePin(LCD_PIN_D7,GetBit(u8Data,7));

#elif LCD_MODE_SELECTOR == LCD_MODE_4_PIN

	DIO_WritePin(LCD_PIN_D4,GetBit(u8Data,4));
	DIO_WritePin(LCD_PIN_D5,GetBit(u8Data,5));
	DIO_WritePin(LCD_PIN_D6,GetBit(u8Data,6));
	DIO_WritePin(LCD_PIN_D7,GetBit(u8Data,7));

	/*enable latch*/
	DIO_WritePin(LCD_PIN_E,1);
	_delay_us(0.450);
	DIO_WritePin(LCD_PIN_E,0);

	DIO_WritePin(LCD_PIN_D4,GetBit(u8Data,0));
	DIO_WritePin(LCD_PIN_D5,GetBit(u8Data,1));
	DIO_WritePin(LCD_PIN_D6,GetBit(u8Data,2));
	DIO_WritePin(LCD_PIN_D7,GetBit(u8Data,3));

#else
#error LCD_MODE_SELECTOR configuration parameter error
#endif

	/*Enable Latch*/
	DIO_WritePin(LCD_PIN_E,1);
	_delay_us(0.450);
	DIO_WritePin(LCD_PIN_E,0);
}
void LCD_sendCommand(uint8 u8Cmd)
{
	/* write data to data register */
	DIO_WritePin(LCD_PIN_RS,0);

	/*enter write mode*/
	DIO_WritePin(LCD_PIN_RW,0);

	/* apply output data on Bus*/
#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN

	DIO_WritePin(LCD_PIN_D0,GetBit(u8Cmd,0));
	DIO_WritePin(LCD_PIN_D1,GetBit(u8Cmd,1));
	DIO_WritePin(LCD_PIN_D2,GetBit(u8Cmd,2));
	DIO_WritePin(LCD_PIN_D3,GetBit(u8Cmd,3));
	DIO_WritePin(LCD_PIN_D4,GetBit(u8Cmd,4));
	DIO_WritePin(LCD_PIN_D5,GetBit(u8Cmd,5));
	DIO_WritePin(LCD_PIN_D6,GetBit(u8Cmd,6));
	DIO_WritePin(LCD_PIN_D7,GetBit(u8Cmd,7));

#elif LCD_MODE_SELECTOR == LCD_MODE_4_PIN

	DIO_WritePin(LCD_PIN_D4,GetBit(u8Cmd,4));
	DIO_WritePin(LCD_PIN_D5,GetBit(u8Cmd,5));
	DIO_WritePin(LCD_PIN_D6,GetBit(u8Cmd,6));
	DIO_WritePin(LCD_PIN_D7,GetBit(u8Cmd,7));

	/*enable latch*/
	DIO_WritePin(LCD_PIN_E,1);
	_delay_us(0.450);
	DIO_WritePin(LCD_PIN_E,0);

	DIO_WritePin(LCD_PIN_D4,GetBit(u8Cmd,0));
	DIO_WritePin(LCD_PIN_D5,GetBit(u8Cmd,1));
	DIO_WritePin(LCD_PIN_D6,GetBit(u8Cmd,2));
	DIO_WritePin(LCD_PIN_D7,GetBit(u8Cmd,3));

#else
#error LCD_MODE_SELECTOR configuration parameter error
#endif

	/*Enable Latch*/
	DIO_WritePin(LCD_PIN_E,1);
	_delay_us(0.450);
	DIO_WritePin(LCD_PIN_E,0);

	_delay_us(100);

}

void LCD_clear(void)
{
	LCD_sendCommand(0x01);
}


void LCD_displayStringRowColumn(uint8* str,uint8 row,uint8 col)
{
	uint8 i =0;
	LCD_gotoRowColumn(row,col);
	while(str[i]!='\0' && i<LCD_MAX_NUMBER_OF_CHR)
	{;
	LCD_displayChar(str[i]);
	i++;
	}
}

void LCD_gotoRowColumn(uint8 row,uint8 col)
{
	/* LCD_writeCmd(0x80 | ((row<<6) | col) ) */
	LCD_sendCommand(0x80 | ((row*0x40) + col) );
}
/*******************************************************************************
 *                      Functions Implementation                               *
 /*******************************************************************************/