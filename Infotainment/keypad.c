/*******************************************************************************
 * File Name	: keypad.c                                                     *
 * Description	: Source file for keypad module                                *
 * Created on	: 9/23/2019 6:00 PM                                            *
 * Author		: Saif El-Deen                                                 *
 *******************************************************************************/


/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "keypad.h"
/*******************************************************************************/



/*******************************************************************************
 *                      Configuration Global Variables                         *
 *******************************************************************************/
extern uint8 RowsConfig[NUMBER_OF_ROWS];
extern uint8 LinesConfig[NUMBER_OF_LINES];
extern const uint8 sg_keypad_mapping[NUMBER_OF_ROWS][NUMBER_OF_LINES];
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Implementation                               *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	Keypad_Init
 * Description: 	used to initialize keypad module
 * parameters:
 *		Inputs:			None
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
void Keypad_Init (void)
{
    uint8 InitLoopIndex = 0;
    /*Rows are outputs*/
    /*Set outputs in no state (1)*/
    for (InitLoopIndex = 0 ; InitLoopIndex < NUMBER_OF_ROWS ; InitLoopIndex++)
    {
        DIO_SetPinDirection(RowsConfig[InitLoopIndex],OUTPUT);
        DIO_WritePin(RowsConfig[InitLoopIndex],HIGH);
    }
    /*Lines are input*/
    /*Activate pull up inputs*/
    for (InitLoopIndex = 0 ; InitLoopIndex < NUMBER_OF_LINES ; InitLoopIndex++)
    {
        DIO_SetPinDirection(LinesConfig[InitLoopIndex],INPUT);
        DIO_PullUpPin(LinesConfig[InitLoopIndex],PULL_UP);
    }
}
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	Keypad_GetKey
 * Description: 	used to scan the pressed key
 * parameters:
 *		Inputs:			None
 *		Outputs:		None
 * Return:			Pressed Key
 *******************************************************************************/
uint8 Keypad_GetKey (void)
{
    uint8 GetKeyLoopIndex = 0;
	uint8 BreakFlag = 0;
    static uint8 state = RELEASED;
    static uint8 sampler = 0;
    static uint8 CapturedInput = 0;
    static uint8 row = 0;
    static uint8 line = NO_VALID_IN;
    uint8 result = NO_VALID_IN;
    /*Check if we have captured */
    if (CapturedInput == 0)
    {
        /*Loop on rows*/
        for(row = 0 ; row < NUMBER_OF_ROWS ; row++)
        {
            /*Set Rows in no state (1)*/
            for (GetKeyLoopIndex = 0 ; GetKeyLoopIndex < NUMBER_OF_ROWS ; GetKeyLoopIndex++)
            {
              DIO_WritePin(RowsConfig[GetKeyLoopIndex],HIGH);
            }
            /*Set the numbered row in output state (0)*/
            DIO_WritePin(RowsConfig[row],LOW);
            /*Check the inputs*/
            for (GetKeyLoopIndex = 0 ; GetKeyLoopIndex < NUMBER_OF_LINES ; GetKeyLoopIndex++)
            {
                /*Check if we have any inputs on the selected push button*/
                if(DIO_ReadPin(LinesConfig[GetKeyLoopIndex]) == VALID_IN)
                {
                    /*get key line*/
                    line = GetKeyLoopIndex;
                    /*get key result*/
                    CapturedInput = sg_keypad_mapping[row][line];
                    /*Set row break flag*/
                    BreakFlag = 1;
                    /*Break from lines Loop*/
                    break;
                }
                else
                {/*Do Nothing*/}
            }
            /*Check if rows break flag is set*/
			if (BreakFlag == 1)
			{
				/*clear flag*/
                BreakFlag = 0;
                /*Break from rows Loop*/
				break;
			}
			else
			{/*Do Nothing*/}
        }
    }
    else
    {
        //Check keypad state
        switch(state)
        {
            case RELEASED:
            /*Check if we have any inputs on the selected push button*/
            if(DIO_ReadPin(LinesConfig[line]) == VALID_IN)
            {
	            /*Increament sampler value*/
                sampler++;
                /*Cheak if sampler value less than 5*/
	            if(sampler < 5)
	            {/*Do Nothing*/}
	            else
	            {
		            /*Change state to pressed*/
                    state = PRESSED;
	            }
            }
            else
            {
	            /*Reset sampler value*/
                sampler = 0;
            }
            break;
			
			case PRESSED:
            /*Check if we have any inputs on the selected push button*/
            if(DIO_ReadPin(LinesConfig[line]) == VALID_IN)
            {
                /*Reset sampler value*/
                sampler = 0;
            }
            else
            {
                /*Increament sampler value*/
                sampler++;
                /*Cheak if sampler value less than 5*/
                if(sampler < 5)
                {/*Do Nothing*/}
                else
                {
                    /*Reset all static variables*/
                    result = CapturedInput;
                    sampler = 0;
                    CapturedInput = 0;
                    row = 0;
                    line = NO_VALID_IN;
                    /*Change state to released*/
                    state = RELEASED;
                }
            }
            break;

            default:
            /*Do Nothing*/
            break;
        }
    }
    /*If we have key pressed -> Return key*
     *If we have no inputs -> Return 0xFF */
    return result;
}
/*******************************************************************************/