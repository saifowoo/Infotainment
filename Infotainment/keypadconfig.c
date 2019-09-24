/*******************************************************************************
 * File Name	: keypadconfig.c                                               *
 * Description	: Keypad configuration source file for user interface          *
 * Created on	: 9/23/2019 6:00 PM                                            *
 * Author		: Saif El-Deen                                                 *
 *******************************************************************************/



/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "keypadconfig.h"
/*******************************************************************************/



/*******************************************************************************
 *                       	Global Variables                                   *
 *******************************************************************************/
/*Please Write in the array below pin number for each Row*/
uint8 RowsConfig[NUMBER_OF_ROWS] = { ROW0,
									 ROW1,
									 ROW2,
								   };
								   
/*Please Write in the array below pin number for each Line*/		   
uint8 LinesConfig[NUMBER_OF_LINES] = {  LINE0,
										LINE1,
										LINE2
									 };

/*Please Write in the array below the mapping of your keypad*/
const uint8 sg_keypad_mapping[NUMBER_OF_ROWS][NUMBER_OF_LINES] = { {'1','2','3'},
																   {'4','5','6'},
																   {'7','8','9'}
																 };
/*******************************************************************************/
										