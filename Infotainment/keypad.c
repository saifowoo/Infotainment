/*******************************************************************************
 * File Name	: keypad.c                                                     *
 * Description	: Source file for keypad module                                *
 * Created on	: 9/15/2019 6:00 PM                                            *
 * Author		: Saif El-Deen                                                 *
 *******************************************************************************/


#include "keypad.h"

extern uint8 RowsConfig[NUMBER_OF_ROWS];
extern uint8 LinesConfig[NUMBER_OF_LINES];

extern const uint8 sg_keypad_mapping[NUMBER_OF_ROWS][NUMBER_OF_LINES];

void Keypad_Init (void)
{
    uint8 InitLoopIndex = 0;
    //rows are outputs
    //set outputs in no state (1)
    for (InitLoopIndex = 0 ; InitLoopIndex < NUMBER_OF_ROWS ; InitLoopIndex++)
    {
        DIO_SetPinDirection(RowsConfig[InitLoopIndex],OUTPUT);
        DIO_WritePin(RowsConfig[InitLoopIndex],HIGH);
    }
    //lines are input
    //activate pull up inputs
    for (InitLoopIndex = 0 ; InitLoopIndex < NUMBER_OF_LINES ; InitLoopIndex++)
    {
        DIO_SetPinDirection(LinesConfig[InitLoopIndex],INPUT);
        DIO_PullUpPin(LinesConfig[InitLoopIndex],PULL_UP);
    }
}

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
    //row = 0;
    //line = NO_VALID_IN;
    if (CapturedInput == 0)
    {
        //loop on rows
        for(row = 0 ; row < NUMBER_OF_ROWS ; row++)
        {
            //set outputs in no state (1)
            for (GetKeyLoopIndex = 0 ; GetKeyLoopIndex < NUMBER_OF_ROWS ; GetKeyLoopIndex++)
            {
              DIO_WritePin(RowsConfig[GetKeyLoopIndex],HIGH);
            }
            //set the numbered row in output state (0)
            DIO_WritePin(RowsConfig[row],LOW);
            //check the inputs
            for (GetKeyLoopIndex = 0 ; GetKeyLoopIndex < NUMBER_OF_LINES ; GetKeyLoopIndex++)
            {
                if(DIO_ReadPin(LinesConfig[GetKeyLoopIndex]) == VALID_IN)
                {
                  line = GetKeyLoopIndex;
                  CapturedInput = sg_keypad_mapping[row][line];
				  BreakFlag = 1;
                  break;
                }
                else
                {/*Do Nothing*/}
            }
			if (BreakFlag == 1)
			{
				BreakFlag = 0;
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
            if(DIO_ReadPin(LinesConfig[line]) == VALID_IN)
            {
	            sampler++;
	            if(sampler < 5)
	            {/*Do Nothing*/}
	            else
	            {
		            state = PRESSED;
	            }
            }
            else
            {
	            sampler = 0;
            }
            break;
			
			case PRESSED:
            if(DIO_ReadPin(LinesConfig[line]) == VALID_IN)
            {
                sampler = 0;
            }
            else
            {
                sampler++;
                if(sampler < 5)
                {/*Do Nothing*/}
                else
                {
                    result = CapturedInput;
                    sampler = 0;
                    CapturedInput = 0;
                    row = 0;
                    line = NO_VALID_IN;
                    state = RELEASED;
                }
            }
            break;
        }
    }
    return result;
}
