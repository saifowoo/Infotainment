/*******************************************************************************
 * File Name	: DIO.c                                                        *
 * Description	: Source file DIO registers map and pin Description            *
 * Created on	: 8/17/2019 11:42 AM                                           *
 * Author		: Saif El-Deen Moustafa                                        *
 *******************************************************************************/



/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "DIO.h"
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Implementation                               *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	DIO_WritePin
 * Description: 	used to write on specific pin 
 * parameters:
 *		Inputs:			1- Pin number
 *						2- Pin value (High,Low)
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
void DIO_WritePin (uint8 PinNum,uint8 PinValue)
{
	if((PinNum >= PINA0) && (PinNum <= PINA7))
	{
		if (PinValue == LOW)
		{
			ClrBit(PORTA,PinNum);
		}
		else if (PinValue == HIGH)
		{
			SetBit(PORTA,PinNum);
		}
		else
		{
			//#error "Please enter number 0 or 1"
		}	
	}
	else if ((PinNum >= PINB0) && (PinNum <= PINB7))
	{
		if (PinValue == LOW)
		{
			ClrBit(PORTB,(PinNum-8));
		}
		else if (PinValue == HIGH)
		{
			SetBit(PORTB,(PinNum-8));
		}
		else
		{
			//#error "Please enter 0 or 1"
		}
	}
	else if ((PinNum >= PINC0) && (PinNum <= PINC7))
	{
		if (PinValue == LOW)
		{
			ClrBit(PORTC,(PinNum-16));
		}
		else if (PinValue == HIGH)
		{
			SetBit(PORTC,(PinNum-16));
		}
		else
		{
			//#error "Please enter 0 or 1"
		}
	}
	else if ((PinNum >= PIND0) && (PinNum <= PIND7))
	{
		if (PinValue == LOW)
		{
			ClrBit(PORTD,(PinNum-24));
		}
		else if (PinValue == HIGH)
		{
			SetBit(PORTD,(PinNum-24));
		}
		else
		{
			//#error "Please enter 0 or 1"
		}
	}
	else
	{
		//#error "Please enter number between 0 and 31"
	}
}
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	DIO_ReadPin
 * Description: 	used to read pin value
 * parameters:
 *		Inputs:			1- Pin number
 *		Outputs:		None
 * Return:			Pin value (High,Low)
 *******************************************************************************/
uint8 DIO_ReadPin (uint8 PinNum)
{
	uint8 value = LOW;
	if((PinNum >= PINA0) && (PinNum <= PINA7))
	{
		value = GetBit(PINA,PinNum);
	}
	else if ((PinNum >= PINB0) && (PinNum <= PINB7))
	{
		value = GetBit(PINB,(PinNum-8));
	}
	else if ((PinNum >= PINC0) && (PinNum <= PINC7))
	{
		value = GetBit(PINC,(PinNum-16));
	}
	else if ((PinNum >= PIND0) && (PinNum <= PIND7))
	{
		value = GetBit(PIND,(PinNum-24));
	}
	else
	{
		//#error "Please enter number between 0 and 31"
	}
	if(value != LOW)
	{
		value = HIGH;
	}
	return value;
}
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	DIO_SetPinDirection
 * Description: 	used to initialize pin direction 
 * parameters:
 *		Inputs:			1- Pin number
 *						2- Pin direction (Input,Output)
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
void DIO_SetPinDirection (uint8 PinNum,uint8 PinDirection)
{
	if((PinNum >= PINA0) && (PinNum <= PINA7))
	{
		if (PinDirection == LOW)
		{
			ClrBit(DDRA,PinNum);
		}
		else if (PinDirection == HIGH)
		{
			SetBit(DDRA,PinNum);
		}
		else
		{
			//#error "Please enter number 0 or 1"
		}
	}
	else if ((PinNum >= PINB0) && (PinNum <= PINB7))
	{
		if (PinDirection == LOW)
		{
			ClrBit(DDRB,(PinNum-8));
		}
		else if (PinDirection == HIGH)
		{
			SetBit(DDRB,(PinNum-8));
		}
		else
		{
			//#error "Please enter number 0 or 1"
		}
	}
	else if ((PinNum >= PINC0) && (PinNum <= PINC7))
	{
		if (PinDirection == LOW)
		{
			ClrBit(DDRC,(PinNum-16));
		}
		else if (PinDirection == HIGH)
		{
			SetBit(DDRC,(PinNum-16));
		}
		else
		{
			//#error "Please enter number 0 or 1"
		}
	}
	else if ((PinNum >= PIND0) && (PinNum <= PIND7))
	{
		if (PinDirection == LOW)
		{
			ClrBit(DDRD,(PinNum-24));
		}
		else if (PinDirection == HIGH)
		{
			SetBit(DDRD,(PinNum-24));
		}
		else
		{
			//#error "Please enter number 0 or 1"
		}
	}
	else
	{
		//#error "Please enter number between 0 and 31"
	}
}
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
void DIO_PullUpPin (uint8 PinNum,uint8 PinValue)
{
	if((PinNum >= PINA0) && (PinNum <= PINA7))
	{
		if (PinValue == PULL_DOWN)
		{
			ClrBit(PORTA,PinNum);
		}
		else if (PinValue == PULL_UP)
		{
			SetBit(PORTA,PinNum);
		}
		else
		{
			//#error "Please enter number 0 or 1"
		}	
	}
	else if ((PinNum >= PINB0) && (PinNum <= PINB7))
	{
		if (PinValue == PULL_DOWN)
		{
			ClrBit(PORTB,(PinNum-8));
		}
		else if (PinValue == PULL_UP)
		{
			SetBit(PORTB,(PinNum-8));
		}
		else
		{
			//#error "Please enter 0 or 1"
		}
	}
	else if ((PinNum >= PINC0) && (PinNum <= PINC7))
	{
		if (PinValue == PULL_DOWN)
		{
			ClrBit(PORTC,(PinNum-16));
		}
		else if (PinValue == PULL_UP)
		{
			SetBit(PORTC,(PinNum-16));
		}
		else
		{
			//#error "Please enter 0 or 1"
		}
	}
	else if ((PinNum >= PIND0) && (PinNum <= PIND7))
	{
		if (PinValue == PULL_DOWN)
		{
			ClrBit(PORTD,(PinNum-24));
		}
		else if (PinValue == PULL_UP)
		{
			SetBit(PORTD,(PinNum-24));
		}
		else
		{
			//#error "Please enter 0 or 1"
		}
	}
	else
	{
		//#error "Please enter number between 0 and 31"
	}
}
/*******************************************************************************/