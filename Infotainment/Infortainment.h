/*******************************************************************************
 * File Name	: Infotainment.h                                               *
 * Description	: Header file for Infotainment Module                          *
 * Created on	: 9/23/2019 6:00 PM                                            *
 * Author		: Nancy & Saif El-Deen                                         *
 *******************************************************************************/

#ifndef E15_REPO_SRC_INFORTAINMENT_H_
#define E15_REPO_SRC_INFORTAINMENT_H_

/*******************************************************************************
 *                      Configuration Enums                                    *
 *******************************************************************************/
typedef enum
{
	Start,
	Display_Q,
	Display_correct,
	Display_uncorrect,
	Display_Score_END
}LCD_FSM_States;

typedef enum
{
	Q0,
	Q1,
	Q2,
	Q3,
	Q4
}LCD_FSM_Qs;
/*******************************************************************************/


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_FSM(void);
void Get_Key(void);
/*******************************************************************************/


#endif /* E15_REPO_SRC_INFORTAINMENT_H_ */
