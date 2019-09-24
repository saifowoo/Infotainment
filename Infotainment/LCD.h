/*******************************************************************************
 * File Name	: LCD.h                                                        *
 * Description	: Header file for LCD Module                                   *
 * Created on	: 9/23/2019 6:00 PM                                            *
 * Author		: Nancy                                                        *
 *******************************************************************************/


#ifndef E15_REPO_SRC_EHAL_LCD_LCD_H_
#define E15_REPO_SRC_EHAL_LCD_LCD_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "typedefs.h"
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_init(void);
void LCD_displayChar(uint8 u8Data);
void LCD_sendCommand(uint8 u8Cmd);
void LCD_clear(void);
void LCD_displayStringRowColumn(uint8* str,uint8 row,uint8 col);
void LCD_gotoRowColumn(uint8 row,uint8 col);
/*******************************************************************************/


#endif /* E15_REPO_SRC_EHAL_LCD_LCD_H_ */
