/*******************************************************************************
 * File Name	: LCD_cfg.h                                                    *
 * Description	: Header file for LCD user configuration                       *
 * Created on	: 9/23/2019 6:00 PM                                            *
 * Author		: Nancy                                                        *
 *******************************************************************************/

#ifndef E15_REPO_SRC_CONFIG_LCD_CFG_H_
#define E15_REPO_SRC_CONFIG_LCD_CFG_H_

/*================================================================================
 * LCD Dependencies
 * DIO Driver
 * PORT Driver 	: 1- all used pins shall be configured as OUTPUT
 * 				: 2- PORT Driver shall be initialized before using this module
 ================================================================================*/


/*
 * define LCD_ mode with the following options
 * LCD_MODE_4_PIN
 * LCD_MODE_8_PIN
 * */

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define LCD_MAX_NUMBER_OF_CHR	16

#define LCD_MODE_SELECTOR		LCD_MODE_4_PIN

#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN
#define LCD_PIN_D0				PINC0
#define LCD_PIN_D1				PINC1
#define LCD_PIN_D2				PINC2
#define LCD_PIN_D3				PINC3
#endif

#define LCD_PIN_D4				PINA4
#define LCD_PIN_D5				PINA5
#define LCD_PIN_D6				PINA6
#define LCD_PIN_D7				PINA7

#define LCD_PIN_RS				PINA1
#define LCD_PIN_RW				PINA2
#define LCD_PIN_E				PINA3
/*******************************************************************************/


#endif /* E15_REPO_SRC_CONFIG_LCD_CFG_H_ */
