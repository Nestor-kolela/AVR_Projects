/*
 * sysTimer.c
 *
 * Created: 2024/06/18 18:37:21
 *  Author: NK KALAMBAY
 */ 

#include "sysTimer.h"
#include <stdio.h>


static uint8_t timeIndex = 0; 
timer myTimers[TIMER_MAX_SIZE] =
{
	{.count = 0, .enable = false, .maxValue = 0, .ptrFunc = NULL},
	{.count = 0, .enable = false, .maxValue = 0, .ptrFunc = NULL},
	{.count = 0, .enable = false, .maxValue = 0, .ptrFunc = NULL},
	{.count = 0, .enable = false, .maxValue = 0, .ptrFunc = NULL}
}; 
ISR(TIMER1_COMPA_vect)
{
	//Check the timers here. 
	for(uint8_t cnt = 0; cnt < timeIndex; cnt++)
	{
		timer * pTimer = &myTimers[cnt];
		if(pTimer->enable == true)
		{
			if(++pTimer->count >= pTimer->maxValue)
			{
				pTimer->count			= 0;
				pTimer->ptrFunc();
			}
		}
	}
}

void sysTimerInit(void)
{
	//Hardware timer initialize
	//No Output compare... 
	//Interrupt on count up to Mode CTC

	TCCR1A &= ~((1 << WGM11) | (1 << WGM10));
	TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10) | (1 << WGM13));
	TCCR1B |= (1 << CS11) | (1 << WGM12); 
	TCCR1C &= ~(0x1F); 
	
	//For a 1 millisecond interrupt
	//We divide 8MHz by 8 = 1000000 MHz
	OCR1AH = GET_SEC_BYTE(TIMER_VALUE);
	OCR1AL = GET_FIRST_BYTE(TIMER_VALUE);
	
	
	TCNT1 = 0x0000;
	//But clear the flag first... 
	TIFR &= ~(1 <<	OCF1A); 
	
	sysTimerStart(); 
	
}


void sysTimerStart(void)
{
	//Hardware timer start
	TIMSK |= (1 << OCIE1A);
}

void sysTimerStop(void)
{
	//Hardware timer stop
	TIMSK &= ~(1 << OCIE1A); 
}
void sysTimerSubModuleStart(const uint8_t timerIndex, const uint32_t milliSeconds)
{
	DISABLE_GLOBAL_INTERRUPTS();
	myTimers[timerIndex].maxValue		= milliSeconds; 
	myTimers[timerIndex].count			= 0u; 
	myTimers[timerIndex].enable			= true; 
	ENABLE_GLOBAL_INTERRUPTS(); 
}

void sysTimerSubModuleInit(const uint32_t milliSeconds, void (*ptrFunction)(void))
{
	DISABLE_GLOBAL_INTERRUPTS();
	myTimers[timeIndex].maxValue		= milliSeconds;
	myTimers[timeIndex].count			= 0u;
	myTimers[timeIndex].enable			= true;
	myTimers[timeIndex].ptrFunc			= ptrFunction;
	timeIndex++;
	ENABLE_GLOBAL_INTERRUPTS();
}
void sysTimerSubModuleStop(const uint8_t timerIndex)
{
	DISABLE_GLOBAL_INTERRUPTS();
	myTimers[timerIndex].enable			= false; 
	ENABLE_GLOBAL_INTERRUPTS(); 
}
void sysTimerSubModuleResume(const uint8_t timerIndex)
{
	DISABLE_GLOBAL_INTERRUPTS();
	myTimers[timerIndex].enable			= true;
	ENABLE_GLOBAL_INTERRUPTS();
}