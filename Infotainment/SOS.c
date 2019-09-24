/*******************************************************************************
 * File Name	: SOS.c                                                        *
 * Description	: Source file for OS                                           *
 * Created on	: 9/15/2019 6:00 PM                                            *
 * Author		: Saif El-Deen Moustafa                                        *
 *******************************************************************************/ 

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "SOS.h"
/*******************************************************************************/



/*******************************************************************************
 *                       	Global Variables                                   *
 *******************************************************************************/
/*Array of task Info structure*/
static OS_Struct_TaskInfo_t StrArrTasks[NumOfTasks];
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Implementation                               *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	OS_Init
 * Description: 	used to initialize OS tick time & tasks buffer
 * parameters:
 *		Inputs:			None
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
void OS_Init (void)
{
	uint8 InitLoopIndex = 0;
	/*Initialize timer configuration structure*/
	Timer_Init();
	/*Initialize task buffer*/
	for(InitLoopIndex = 0 ; InitLoopIndex < NumOfTasks ; InitLoopIndex++)
	{
		StrArrTasks[InitLoopIndex].TaskPeriod = EMPTY_PERIOD;
		StrArrTasks[InitLoopIndex].TaskPtrToFun = NULL;
		StrArrTasks[InitLoopIndex].TaskState = DELETED;
		StrArrTasks[InitLoopIndex].TaskRemainingTime = DEFAULT_TIME;
	}
}
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	OS_CreateTask
 * Description: 	used to create new task and assign it in the buffer
 * parameters:
 *		Inputs:			1- pointer to task function
						2- enum of task priority
						3- task period in msec
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
 void OS_CreateTask (OS_PtrToFun_t a_TaskPtrToFun,OS_Enum_PriortyCfg_t a_TaskPriority,uint16 a_TaskPeriodms)
 {
	 StrArrTasks[a_TaskPriority].TaskPeriod = a_TaskPeriodms;
	 StrArrTasks[a_TaskPriority].TaskPtrToFun = a_TaskPtrToFun;
	 StrArrTasks[a_TaskPriority].TaskState = READY;
	 StrArrTasks[a_TaskPriority].TaskRemainingTime = a_TaskPeriodms;
 }
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	OS_DeletTask
 * Description: 	used to delete existing task
 * parameters:
 *		Inputs:			1- enum of task priority
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
 void OS_DeletTask (OS_Enum_PriortyCfg_t a_TaskPriority)
 {
	 StrArrTasks[a_TaskPriority].TaskPeriod = EMPTY_PERIOD;
	 StrArrTasks[a_TaskPriority].TaskPtrToFun = NULL;
	 StrArrTasks[a_TaskPriority].TaskState = DELETED;
	 StrArrTasks[a_TaskPriority].TaskRemainingTime = DEFAULT_TIME;	 
 }
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	OS_Run
 * Description: 	Used to change state from ready to running
					or from running to wait.
 * parameters:
 *		Inputs:			None
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
 void OS_Run (void)
 {
	 uint8 RunLoopIndex = EMPTY;
	 Timer_ON();
	 while(1)
	 {
		 for (RunLoopIndex = 0 ; RunLoopIndex <NumOfTasks ; RunLoopIndex++)
		 {
			 if (StrArrTasks[RunLoopIndex].TaskPtrToFun != NULL)
			 {
				 switch(StrArrTasks[RunLoopIndex].TaskState)
				 {
					 case DELETED:
					 case WAIT:
					 case RUNNING:
					 /*DO NOTHING*/
					 break;
					 
					 case READY:
					 StrArrTasks[RunLoopIndex].TaskPtrToFun();
					 StrArrTasks[RunLoopIndex].TaskState = WAIT;
					 break;
				 }
			 }
			 else
			 {/*Do Nothing*/} 
		 }
		 /*SLEEP*/
	 }
 }
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	OS_LongTerm
 * Description:		Used to Check task remaining time to change state
					from wait to ready in timer ISR.  
 * parameters:
 *		Inputs:			None
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
 void OS_LongTermCallBack (void)
 {
	 uint8 ISRLoopIndex = EMPTY;
	 for (ISRLoopIndex = 0 ; ISRLoopIndex <NumOfTasks ; ISRLoopIndex++)
	 {
		 switch(StrArrTasks[ISRLoopIndex].TaskState)
		 {
			 case DELETED:
				/*Do Nothing*/
				break;
				
			default:
				/*Decrement task remaining time every tick*/
				StrArrTasks[ISRLoopIndex].TaskRemainingTime--;
				/*Check if task remaining time to run = 0*/
				if (StrArrTasks[ISRLoopIndex].TaskRemainingTime == 0)
				{
					/*Change task state to Ready*/
					StrArrTasks[ISRLoopIndex].TaskState = READY;
					/*Reset remaining time*/
					StrArrTasks[ISRLoopIndex].TaskRemainingTime = StrArrTasks[ISRLoopIndex].TaskPeriod;
				}
				else
				{/*Do Nothing*/}
				break;
		 }
	 } 
 }
/*******************************************************************************/