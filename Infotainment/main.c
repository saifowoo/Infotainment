 /*******************************************************************************
 * File Name	: main.c                                                       *
 * Description	: Source file for OS                                           *
 * Created on	: 9/23/2019 6:00 PM                                            *
 * Author		: Nancy & Saif El-Deen                                         *
 *******************************************************************************/ 

#include "SOS.h"
#include "Infortainment.h"
#include <util/delay.h>
#include "keypad.h"

 
int main(void)
{
    /* Replace with your application code */
	Keypad_Init();
	OS_Init();
    OS_CreateTask (LCD_FSM,tasknum0,1000);
	OS_CreateTask (Get_Key,tasknum1,1);
	OS_Run();
}

