/*******************************************************************************
 * File Name	: Infotainment.c                                               *
 * Description	: Source file for Infotainment Module                          *
 * Created on	: 9/23/2019 6:00 PM                                            *
 * Author		: Nancy & Saif El-Deen                                         *
 *******************************************************************************/



/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "DIO.h"
#include "LCD.h"
#include "Infortainment.h"
#include "keypad.h"
/*******************************************************************************/



/*******************************************************************************
 *                       	Global Variables                                   *
 *******************************************************************************/
uint8 B1Pressing;
uint8 B2Pressing;
static LCD_FSM_States LCD_state=Start;
static uint8 QestCounter=0;
static uint8 score=0;
uint8  MaxQestCounter=5;
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Implementation                               *
 *******************************************************************************/
void LCD_FSM(void)
{
	LCD_init();

	switch(LCD_state)
	{
		case Start:
		{
			LCD_displayStringRowColumn("Press B1",0,0);
			LCD_displayStringRowColumn("To Start",1,0);
			DIO_SetPinDirection(LED2,1);
			DIO_WritePin(LED2,1);
			if(B1Pressing==1)
			{
				QestCounter=0;
				score=0;
				LCD_state=Display_Q;
				B1Pressing=0;
				B2Pressing=0;
			}
		}
		break;
		case Display_Q:
		{
			switch(QestCounter)
			{
				case Q0:
				{
					LCD_clear();
					LCD_displayStringRowColumn("Wave 3 is 19",0,1);
					LCD_displayStringRowColumn("Press Yes or No",1,0);
					if(B1Pressing==1)
					{
						LCD_state=Display_correct;
						B1Pressing=0;
						B2Pressing=0;
					}
					else if (B2Pressing==1)
					{
						LCD_state=Display_uncorrect;
						B1Pressing=0;
						B2Pressing=0;
					}
					else
						LCD_state=Display_Q;
				}
				break;
				case Q1:
				{
					LCD_clear();
					LCD_displayStringRowColumn("Started in Aug",0,0);
					LCD_displayStringRowColumn("Press Yes or No",1,0);
					if(B1Pressing==1)
					{
						LCD_state=Display_correct;
						B1Pressing=0;
						B2Pressing=0;
					}
					else if (B2Pressing==1)
					{
						LCD_state=Display_uncorrect;
						B1Pressing=0;
						B2Pressing=0;
					}
					else
						LCD_state=Display_Q;
				}
				break;
				case Q2:
				{
					LCD_clear();
					LCD_displayStringRowColumn("Ended in Nov",0,0);
					LCD_displayStringRowColumn("Press Yes or No",1,0);
					if(B1Pressing==1)
					{
						LCD_state=Display_correct;
						B1Pressing=0;
						B2Pressing=0;
					}
					else if (B2Pressing==1)
					{
						LCD_state=Display_uncorrect;
						B1Pressing=0;
						B2Pressing=0;
					}
					else
						LCD_state=Display_Q;
				}
				break;
				case Q3:
				{
					LCD_clear();
					LCD_displayStringRowColumn("All Hired",0,0);
					LCD_displayStringRowColumn("Press Yes or No",1,0);
					if(B1Pressing==1)
					{
						LCD_state=Display_correct;
						B1Pressing=0;
						B2Pressing=0;
					}
					else if (B2Pressing==1)
					{
						LCD_state=Display_uncorrect;
						B1Pressing=0;
						B2Pressing=0;
					}
					else
						LCD_state=Display_Q;
				}
				break;
				case Q4:
				{
					LCD_clear();
					LCD_displayStringRowColumn("All Paid",0,0);
					LCD_displayStringRowColumn("Press Yes or No",1,0);
					if(B1Pressing==1)
					{
						LCD_state=Display_uncorrect;
						B1Pressing=0;
						B2Pressing=0;
					}
					else if (B2Pressing==1)
					{
						LCD_state=Display_correct;
						B1Pressing=0;
						B2Pressing=0;
					}
					else
						LCD_state=Display_Q;
				}
				break;
				default:
					LCD_state=Display_Score_END;
			}

		}
		break;
		case Display_correct:
		{
			LCD_clear();
			LCD_displayStringRowColumn(":)",0,0);
			LCD_displayStringRowColumn("Press B1 to cont.",1,0);
			if(QestCounter<MaxQestCounter && B1Pressing==1)
			{
				LCD_state=Display_Q;
				B1Pressing=0;
				B2Pressing=0;
				score++;
				QestCounter++;
			}
			else if(QestCounter>=MaxQestCounter && B1Pressing==1)
			{
				LCD_state=Display_Score_END;
				B1Pressing=0;
				B2Pressing=0;
				QestCounter++;
			}
			else
				LCD_state=Display_correct;
		}
		break;
		case Display_uncorrect:
		{
			LCD_clear();
			LCD_displayStringRowColumn(":(",0,0);
			LCD_displayStringRowColumn("Press B1 to cont.",1,0);

			if(QestCounter<MaxQestCounter && B1Pressing==1)
			{
				LCD_state=Display_Q;
				B1Pressing=0;
				B2Pressing=0;
				QestCounter++;
			}
			else if(QestCounter>=MaxQestCounter && B1Pressing==1)
			{
				LCD_state=Display_Score_END;
				B1Pressing=0;
				B2Pressing=0;
				QestCounter++;
			}
			else
				LCD_state=Display_uncorrect;

		}
		break;
		case Display_Score_END:
		{
			LCD_clear();
			LCD_displayStringRowColumn("END Press B1",0,0);
			LCD_displayStringRowColumn("Score= ",1,0);
			LCD_displayChar(score+'0');
			if(B1Pressing==1)
			{
				LCD_state=Start;
				B1Pressing=0;
				B2Pressing=0;
			}
			else
				LCD_state=Display_Score_END;
		}
		break;


	}
}

void Get_Key(void)
{
	static uint8 keypressed,prev_pressed_sw=0xff;
	keypressed=0xff;
	keypressed=Keypad_GetKey();
	if(keypressed!=255)
	{
		if(prev_pressed_sw==255)
		{
			if(keypressed==0xff)
			{
				B1Pressing=0;
				B2Pressing=0;
				DIO_SetPinDirection(LED0,1);
				DIO_WritePin(LED0,1);
			}
			else if(keypressed=='1')
			{
				B1Pressing=1;
				B2Pressing=0;
				DIO_SetPinDirection(LED1,1);
				DIO_WritePin(LED1,1);
			}
			else if(keypressed=='2')
			{
				B1Pressing=0;
				B2Pressing=1;
			}
			else
			{
				B1Pressing=0;
				B2Pressing=0;
				DIO_SetPinDirection(LED3,1);
				DIO_WritePin(LED3,1);
			}
		}

	}
	else
	{
		prev_pressed_sw=keypressed;
	}

}
/*******************************************************************************/