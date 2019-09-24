/*
 * timer_cfg.h
 *
 * Created: 9/7/2019 3:51:17 PM
 *  Author: kingd
 */ 


#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/*******************************************************************************
 *                       	TyPe Defines                                       *
 *******************************************************************************/
typedef void(* Timer_PtrToFun_t)(void);
/*******************************************************************************/



/*******************************************************************************
 *                      Configuration Enums                                    *
 *******************************************************************************/
enum TIMER_MODE
{
	TIMER_NORMAL = 0b00000000,
	TIMER_CTC = 0b00001000,
	TIMER_FAST_PWM = 0b01000000,
	TIMER_PHASE_PWM = 0b01001000
};

enum TIMER_COM_CTC
{
	TIMER_COM_CTC_DISCONNECTED = 0b00000000,
	TIMER_COM_CTC_TOGGLE = 0b00010000,
	TIMER_COM_CTC_CLEAR = 0b00100000,
	TIMER_COM_CTC_SET = 0b00110000
};

enum TIMER_COM_FAST_PWM
{
	TIMER_COM_FAST_DISCONNECTED = 0b00000000,
	TIMER_COM_FAST_NON_INVERTING = 0b00100000,
	TIMER_COM_FAST_INVERTING = 0b00110000
};

enum TIMER_COM_PHASE_PWM
{
	TIMER_COM_PHASE_DISCONNECTED = 0b00000000,
	TIMER_COM_PHASE_NON_INVERTING = 0b00100000,
	TIMER_COM_PHASE_INVERTING = 0b00110000
};

enum TIMER_INT_ENABLE
{
	TIMER_INT_OFF = 0b00000000,
	TIMER_INT_OVF = 0b00000001,
	TIMER_INT_OCF = 0b00000010
};

enum TIMER_ENABLE_PRESCALAR
{
	TIMER_PREOFF = 0b00000000,
	TIMER_1OR2_PRE1 = 0b00000001,
	TIMER_1OR2_PRE8 = 0b00000010,
	TIMER_1OR2_PRE64 = 0b00000011,
	TIMER_1OR2_PRE256 = 0b00000100,
	TIMER_1OR2_PRE1024 = 0b00000101,
	TIMER_1_PRE_FALLING = 0b00000110,
	TIMER_1_PRE_RISING = 0b00000111,
	TIMER_2_PRE32 = 0b00001000,
	TIMER_2_PRE128 = 0b000001001
};
/*******************************************************************************/



/*******************************************************************************
 * Configuration Structure = {	,
 *								,
 *								,
 *								,
 *								,
 *								
 *								};							
 *******************************************************************************/
typedef struct
{
	enum TIMER_MODE						MODE ;
	/*enum TIMER_ENABLE_PRESCALAR			ENABLE_PRESCALER ;*/
	enum TIMER_INT_ENABLE				INT_ENABLE;
	enum TIMER_COM_CTC					COM_CTC;
	enum TIMER_COM_FAST_PWM				COM_FAST_PWM;
	enum TIMER_COM_PHASE_PWM			COM_PHASE_PWM;
	Timer_PtrToFun_t					Timer_CallBackOCF;
}S_TIMER_config;
/*******************************************************************************/



 extern void OS_LongTermCallBack (void);


#endif /* TIMER_CFG_H_ */