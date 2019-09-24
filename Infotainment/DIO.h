/*******************************************************************************
 * File Name	: DIO.h                                                        *
 * Description	: header file DIO registers map and pin Description            *
 * Created on	: 8/17/2019 11:42 AM                                           *
 * Author		: Saif El-Deen Moustafa                                        *
 *******************************************************************************/



#ifndef INCFILE1_H_
#define INCFILE1_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "typedefs.h"
#include "DIO.h"
#include "bitwise.h"
/*******************************************************************************/



/*******************************************************************************
*                          Mapped Registers                                    *
********************************************************************************/

/******************** PORT (A) Data Direction Register ********************/
#define DDRA		(*((volatile uint8 *)0x3A))
/******************** PORT (A) Data Register ********************/
#define PORTA		(*((volatile uint8 *)0x3B))
/******************** PORT (A) Input Pins Address ********************/
#define PINA		(*((volatile uint8 *)0x39))
/********** Pin Description **********/
#define PINA0		0
#define PINA1		1
#define PINA2		2
#define PINA3		3
#define PINA4		4
#define PINA5		5
#define PINA6		6
#define PINA7		7

/******************** PORT (B) Data Direction Register ********************/
#define DDRB		(*((volatile uint8 *)0x37))
/******************** PORT (B) Data Register ********************/
#define PORTB		(*((volatile uint8 *)0x38))
/******************** PORT (B) Input Pins Address ********************/
#define PINB		(*((volatile uint8 *)0x36))
/********** Pin Description **********/
#define PINB0		8
#define PINB1		9
#define PINB2		10
#define PINB3		11
#define PINB4		12
#define PINB5		13
#define PINB6		14
#define PINB7		15

/******************** PORT (C) Data Direction Register ********************/
#define DDRC		(*((volatile uint8 *)0x34))
/******************** PORT (C) Data Register ********************/
#define PORTC		(*((volatile uint8 *)0x35))
/******************** PORT (C) Input Pins Address ********************/
#define PINC		(*((volatile uint8 *)0x33))
/********** Pin Description **********/
#define PINC0		16
#define PINC1		17
#define PINC2		18
#define PINC3		19
#define PINC4		20
#define PINC5		21
#define PINC6		22
#define PINC7		23

/******************** PORT (D) Data Direction Register ********************/
#define DDRD		(*((volatile uint8 *)0x31))
/******************** PORT (D) Data Register ********************/
#define PORTD		(*((volatile uint8 *)0x32))
/******************** PORT (D) Input Pins Address ********************/
#define PIND		(*((volatile uint8 *)0x30))
/********** Pin Description **********/
#define PIND0		24
#define PIND1		25
#define PIND2		26
#define PIND3		27
#define PIND4		28
#define PIND5		29
#define PIND6		30
#define PIND7		31
/*******************************************************************************/



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/********** Pins Number **********/
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15
#define PIN16		16
#define PIN17		17
#define PIN18		18
#define PIN19		19
#define PIN20		20
#define PIN21		21
#define PIN22		22
#define PIN23		23
#define PIN24		24
#define PIN25		25
#define PIN26		26
#define PIN27		27
#define PIN28		28
#define PIN29		29
#define PIN30		30
#define PIN31		31

/********** Hardware LEDs Number **********/
#define LED0		12
#define LED1		13
#define LED2		14
#define LED3		15

/********** Hardware PBs Number **********/
#define PushButton1	10
#define PushButton0	20

/********** Pin Directions **********/
#define INPUT		0
#define OUTPUT		1

/********** Pin Output/Input **********/
#define LOW			0
#define HIGH		1

/********** Pin Pull Up/Pull Down **********/
#define PULL_UP		1
#define PULL_DOWN	0

/********** Hardware Keypad Pins **********/
/*#define ROW1		18	
#define ROW2		19
#define ROW3		20
#define LINE1		21
#define LINE2		22
#define LINE3		23*/

/********** Hardware 7 Segment Pins **********/
#define SEGA		8
#define SEGB		9
#define SEGC		10
#define SEGD		11
#define SEGEN1		26
#define SEGEN2		27
#define SEGDP		28
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	DIO_SetPinDirection
 * Description: 	used to initialize pin direction 
 * parameters:
 *		Inputs:			1- Pin number
 *						2- Pin direction (Input,Output)
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
void DIO_SetPinDirection (uint8 PinNum,uint8 PinDirection);
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	DIO_WritePin
 * Description: 	used to write on specific pin 
 * parameters:
 *		Inputs:			1- Pin number
 *						2- Pin value (High,Low)
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
void DIO_WritePin (uint8 PinNum,uint8 PinValue);
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	DIO_ReadPin
 * Description: 	used to read pin value
 * parameters:
 *		Inputs:			1- Pin number
 *		Outputs:		None
 * Return:			Pin value (High,Low)
 *******************************************************************************/
uint8 DIO_ReadPin (uint8 PinNum);
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	DIO_PullUpPin
 * Description: 	used to active pull up for specific pin 
 * parameters:
 *		Inputs:			1- Pin number
 *						2- Pin value (PULL_UP,PULL_DOWN)
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
void DIO_PullUpPin (uint8 PinNum,uint8 PinValue);
/*******************************************************************************/

#endif /* INCFILE1_H_ */
