/*
 * timer.c
 *
 * Created: 8/18/2019 10:00:25 AM
 *  Author: kingd
 */ 


#include "timer.h"
#include <avr/interrupt.h>


S_TIMER_config timercfg = {	TIMER_CTC,
							TIMER_INT_OCF,
							TIMER_COM_CTC_DISCONNECTED,
							TIMER_COM_FAST_DISCONNECTED,
							TIMER_COM_PHASE_DISCONNECTED,
							OS_LongTermCallBack };

void Timer_Init (void)
{
	TCCR0 = 0x00;

	//mode
	if (timercfg.MODE == TIMER_NORMAL)
	{
		ClrBit(TCCR0,WGM00);
		ClrBit(TCCR0,WGM01);
	}
	
	else if (timercfg.MODE == TIMER_CTC)
	{
		ClrBit(TCCR0,WGM00);
		SetBit(TCCR0,WGM01);
		if (timercfg.COM_CTC == TIMER_COM_CTC_DISCONNECTED)
		{
			ClrBit(TCCR0,COM00);
			ClrBit(TCCR0,COM01);
		}
		else if (timercfg.COM_CTC == TIMER_COM_CTC_TOGGLE)
		{
			SetBit(TCCR0,COM00);
			ClrBit(TCCR0,COM01);
		}
		else if (timercfg.COM_CTC == TIMER_COM_CTC_CLEAR)
		{
			ClrBit(TCCR0,COM00);
			SetBit(TCCR0,COM01);
		}
		else if (timercfg.COM_CTC == TIMER_COM_CTC_SET)
		{
			SetBit(TCCR0,COM00);
			SetBit(TCCR0,COM01);
		}
		DIO_SetPinDirection(OC0,OUTPUT);
		DIO_WritePin(OC0,LOW);
	}
	
	else if (timercfg.MODE == TIMER_FAST_PWM)
	{
		SetBit(TCCR0,WGM00);
		SetBit(TCCR0,WGM01);
		if (timercfg.COM_FAST_PWM == TIMER_COM_FAST_DISCONNECTED)
		{
			ClrBit(TCCR0,COM00);
			ClrBit(TCCR0,COM01);
		}
		else if (timercfg.COM_FAST_PWM == TIMER_COM_FAST_NON_INVERTING)
		{
			ClrBit(TCCR0,COM00);
			SetBit(TCCR0,COM01);
		}
		else if (timercfg.COM_FAST_PWM == TIMER_COM_FAST_INVERTING)
		{
			SetBit(TCCR0,COM00);
			SetBit(TCCR0,COM01);
		}
		DIO_SetPinDirection(OC0,OUTPUT);
		DIO_WritePin(OC0,LOW);
	}
	
	else if (timercfg.MODE == TIMER_PHASE_PWM)
	{
		SetBit(TCCR0,WGM00);
		ClrBit(TCCR0,WGM01);
		if (timercfg.COM_PHASE_PWM == TIMER_COM_PHASE_DISCONNECTED)
		{
			ClrBit(TCCR0,COM00);
			ClrBit(TCCR0,COM01);
		}
		else if (timercfg.COM_PHASE_PWM == TIMER_COM_PHASE_NON_INVERTING)
		{
			ClrBit(TCCR0,COM00);
			SetBit(TCCR0,COM01);
		}
		else if (timercfg.COM_PHASE_PWM == TIMER_COM_PHASE_INVERTING)
		{
			SetBit(TCCR0,COM00);
			SetBit(TCCR0,COM01);
		}
		DIO_SetPinDirection(OC0,OUTPUT);
		DIO_WritePin(OC0,LOW);
	}
}

void Timer_ON (void)
{
	//prescaler
	uint16 prescalervalue = TIMER0_PRESCALER;
	if (prescalervalue == TIMER_PREOFF)
	{
		ClrBit(TCCR0,CS00);
		ClrBit(TCCR0,CS01);
		ClrBit(TCCR0,CS02);
	}
	else if (prescalervalue == TIMER_1OR2_PRE1)
	{
		SetBit(TCCR0,CS00);
		ClrBit(TCCR0,CS01);
		ClrBit(TCCR0,CS02);
	}
	else if (prescalervalue == TIMER_1OR2_PRE8)
	{
		ClrBit(TCCR0,CS00);
		SetBit(TCCR0,CS01);
		ClrBit(TCCR0,CS02);
	}
	else if (prescalervalue == TIMER_PRE64)
	{
		SetBit(TCCR0,CS00);
		SetBit(TCCR0,CS01);
		ClrBit(TCCR0,CS02);
	}
	else if (prescalervalue == TIMER_1OR2_PRE256)
	{
		ClrBit(TCCR0,CS00);
		ClrBit(TCCR0,CS01);
		SetBit(TCCR0,CS02);
	}
	else if (prescalervalue == TIMER_1OR2_PRE1024)
	{
		SetBit(TCCR0,CS00);
		ClrBit(TCCR0,CS01);
		SetBit(TCCR0,CS02);
	}
	else if (prescalervalue == TIMER_1_PRE_FALLING)
	{
		ClrBit(TCCR0,CS00);
		SetBit(TCCR0,CS01);
		SetBit(TCCR0,CS02);
	}
	else if (prescalervalue == TIMER_1_PRE_RISING)
	{
		SetBit(TCCR0,CS00);
		SetBit(TCCR0,CS01);
		SetBit(TCCR0,CS02);
	}
	
	sei();
	//interrupt
	if (timercfg.INT_ENABLE == TIMER_INT_OVF)
	{
		SetBit(TIMSK,TOIE0);
		TCNT0 = 255 - SetCounts(TIME_RESOLUTION,F_CPU,TIMER0_PRESCALER);
	}
	else if (timercfg.INT_ENABLE == TIMER_INT_OCF)
	{
		SetBit(TIMSK,OCIE0);
		OCR0 = SetCounts(TIME_RESOLUTION,F_CPU,TIMER0_PRESCALER);
	}
	else
	{
		
	}
}

void Timer_OFF(void)
{
	ClrBit(TIMSK,TOIE0);
	ClrBit(TIMSK,OCIE0);
}
/*static void Timer_Delay(void)
{
	
	OCR0 = SetCounts(TIME_RESOLUTION,F_CPU,TIMER0_PRESCALER);
	
}*/

void Delay_ms(uint64 msec)
{
	uint64 i;
	TCNT0 = 0;
	OCR0 = 125;
	for (i=0;i<msec;i++)
	{
		while((GetBit(TIFR,OCF0) == LOW));
		SetBit(TIFR,OCF0);
	}
}

ISR(TIMER0_COMP_vect)
{
	timercfg.Timer_CallBackOCF();
}