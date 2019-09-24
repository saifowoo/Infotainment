/*******************************************************************************
 * File Name	: SOS_Cfg.h                                                    *
 * Description	: configuration header file for user interface                 *
 * Created on	: 9/15/2019 6:00 PM                                            *
 * Author		: Saif El-Deen Moustafa                                        *
 *******************************************************************************/  


#ifndef SOS_CFG_H_
#define SOS_CFG_H_
/*******************************************************************************
 *                      Configuration Enums                                    *
 *******************************************************************************/

/******************** Task Priority enum ********************/
/*Please enter task name and arrange them based on priority*/
/*Top -> Highest Priority & Bottom -> Lowest Priority*/
typedef enum
{
	/*Start here*/
	tasknum0,
	tasknum1,
	/*Stop here*/
	NumOfTasks
}OS_Enum_PriortyCfg_t;
/*******************************************************************************/


#endif /* SOS_CFG_H_ */