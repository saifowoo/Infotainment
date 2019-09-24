/*
 * timer.h
 *
 * Created: 8/18/2019 10:00:46 AM
 *  Author: kingd
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "DIO.h"
#include "timer_cfg.h"
/*******************************************************************************/



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define 	F_CPU			8000000UL
#define		TIME_RESOLUTION			0.001

typedef uint32 prescaler;
#define		TIMER_PREOFF			(prescaler)0
#define		TIMER_PRE1				(prescaler)1
#define		TIMER_PRE8				(prescaler)8
#define		TIMER_PRE64				(prescaler)64
#define		TIMER_PRE256			(prescaler)256
#define		TIMER_PRE1024			(prescaler)1024
#define		TIMER_PRE32				(prescaler)32
#define		TIMER_PRE128			(prescaler)128

#define		TIMER0_PRESCALER		TIMER_PRE64

#define		SetCounts(TIME,FCPU,PSCLER)			((TIME*FCPU)/PSCLER)
/*******************************************************************************/




#define		OC0				11
#define		ICP1			30

/******************** Timer/Counter Control Register (Timer0) ********************/
#define		TCCR0				(*((volatile uint8 *)0x53))
/********** Pin Description **********/ 
#define		CS00			0
#define		CS01			1
#define		CS02			2
#define		WGM01			3
#define		COM00			4
#define		COM01			5
#define		WGM00			6
#define		FOC0			7

/******************** Timer/Counter Register (Timer0) ********************/
#define		TCNT0				(*((volatile uint8 *)0x52))

/******************** Output Compare Register (Timer0) ********************/
#define		OCR0				(*((volatile uint8 *)0x5c))

/******************** Timer/Counter Interrupt Mask Register ********************/
#define		TIMSK				(*((volatile uint8 *)0x59))
/********** Pin Description **********/
#define		TOIE0			0
#define		OCIE0			1
#define		TOIE1			2
#define		OCIE1B			3
#define		OCIE1A			4
#define		TICIE1			5
#define		TOIE2			6
#define		OCIE2			7

/******************** Timer/Counter Interrupt Flag Register ********************/
#define		TIFR				(*((volatile uint8 *)0x58))
/********** Pin Description **********/
#define		TOV0			0
#define		OCF0			1
#define		TOV1			2
#define		OCF1B			3
#define		OCF1A			4
#define		ICF1			5
#define		TOV2			6
#define		OCF2			7

/******************** Timer/Counter Control Register (Timer2) ********************/
#define		TCCR2				(*((volatile uint8 *)0x45))
/********** Pin Description **********/
#define		CS20			0
#define		CS21			1
#define		CS22			2
#define		WGM21			3
#define		COM20			4
#define		COM21			5
#define		WGM20			6
#define		FOC2			7

/******************** Timer/Counter Register (Timer2) ********************/
#define		TCNT2				(*((volatile uint8 *)0x44))

/******************** Output Compare Register (Timer2) ********************/
#define		OCR2				(*((volatile uint8 *)0x43))

/******************** Timer/Counter1 Control Register A (Timer1) ********************/
#define		TCCR1A				(*((volatile uint8 *)0x4F))
/********** Pin Description **********/
#define		WGM10			0
#define		WGM11			1
#define		FOC1B			2
#define		FOC1A			3
#define		COM1B0			4
#define		COM1B1			5
#define		COM1A0			6
#define		COM1A1			7

/******************** Timer/Counter Control Register (Timer1) ********************/
#define		TCCR1B				(*((volatile uint8 *)0x4E))
/********** Pin Description **********/
#define		CS10			0
#define		CS11			1
#define		CS12			2
#define		WGM12			3
#define		WGM13			4
#define		ICES1			6
#define		ICNC1			7

/******************** Timer/Counter Register (Timer1) ********************/
#define		TCNT1H				(*((volatile uint8 *)0x4D))
#define		TCNT1L				(*((volatile uint8 *)0x4C))

/******************** Output Compare Register 1 A (Timer1) ********************/
#define		OCR1AH				(*((volatile uint8 *)0x4B))
#define		OCR1AL				(*((volatile uint8 *)0x4A))

/******************** Output Compare Register 1 B (Timer1) ********************/
#define		OCR1BH				(*((volatile uint8 *)0x49))
#define		OCR1BL				(*((volatile uint8 *)0x48))

/******************** Input Capture Register 1 (Timer1) ********************/
#define		ICR1H				(*((volatile uint8 *)0x47))
#define		ICR1L				(*((volatile uint8 *)0x46))





void Timer_Init (void);
void Timer_ON(void);
void Timer_OFF(void);
void Delay_ms(uint64 msec);
void Timer_Delay(uint64 tms);





#endif /* TIMER_H_ */