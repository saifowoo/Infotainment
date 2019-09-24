/*******************************************************************************
 * File Name	: SOS.h                                                        *
 * Description	: Header file for OS                                           *
 * Created on	: 9/15/2019 6:00 PM                                            *
 * Author		: Saif El-Deen Moustafa                                        *
 *******************************************************************************/


#ifndef SOS_H_
#define SOS_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "timer.h"
#include "SOS_Cfg.h"
/*******************************************************************************/



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define NULL			((void *)0)
#define EMPTY_PERIOD		0
#define DEFAULT_TIME		0xFF
#define EMPTY				0
/*******************************************************************************/



/*******************************************************************************
 *                       	TyPe Defines                                       *
 *******************************************************************************/
typedef void(* OS_PtrToFun_t)(void);
/*******************************************************************************/



/*******************************************************************************
 *                      Configuration Enums                                    *
 *******************************************************************************/

/******************** Function Status enum ********************/
typedef enum
{
	OS_NotOk = 0U,
	OS_OK = 1U,
}OS_Enum_Status_t;

/******************** Task State enum ********************/
typedef enum
{
	DELETED = 0U,
	READY = 1U,
	RUNNING = 2U,
	WAIT = 3U
}OS_Enum_TaskState_t;
/*******************************************************************************/



/*******************************************************************************
 * Task Info Structure = {		Pointer To Task Function,
 *								Task State (Ready,Running,Waiting),
 *								Task Periodicity(msec),
 *								Task Remaining time to be ready,
 *						};							
 *******************************************************************************/
typedef struct{
	OS_PtrToFun_t	TaskPtrToFun;
	OS_Enum_TaskState_t TaskState;
	uint16 TaskPeriod;
	uint16 TaskRemainingTime;
}OS_Struct_TaskInfo_t;
/*******************************************************************************/



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	OS_Init
 * Description: 	used to initialize OS tick time & tasks buffer
 * parameters:
 *		Inputs:			None
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
extern void OS_Init (void);
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
 extern void OS_CreateTask (OS_PtrToFun_t a_TaskPtrToFun,OS_Enum_PriortyCfg_t a_TaskPriority,uint16 a_TaskPeriodms);
/*******************************************************************************/

/*******************************************************************************
 * Function Name:	OS_DeletTask
 * Description: 	used to delete existing task
 * parameters:
 *		Inputs:			1- enum of task priority
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
 extern void OS_DeletTask (OS_Enum_PriortyCfg_t a_TaskPriority);
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
 extern void OS_Run (void);
 /*******************************************************************************/

/*******************************************************************************
 * Function Name:	OS_LongTerm
 * Description:		Used to Check task remaining time to change state
					from wait to ready.  
 * parameters:
 *		Inputs:			None
 *		Outputs:		None
 * Return:			None
 *******************************************************************************/
 extern void OS_LongTermCallBack (void);
/*******************************************************************************/

#endif /* SOS_H_ */