/*
 * sysTimer.c
 *
 * Created: 2024/06/18 18:37:21
 *  Author: NK KALAMBAY
 */ 

#include "sysTimer.h"

volatile uint8_t value = 0; 
timer myTimers[TIMER_MAX_SIZE] =
{
	{.count = 0, .enable = false, .maxValue = 0, .timerExpired = false},
	{.count = 0, .enable = false, .maxValue = 0, .timerExpired = false},
	{.count = 0, .enable = false, .maxValue = 0, .timerExpired = false},
	{.count = 0, .enable = false, .maxValue = 0, .timerExpired = false}
}; 
ISR(TIMER1_COMPA_vect)
{
	//Check the timers here. 
	for(uint8_t cnt = 0; cnt < TIMER_MAX_SIZE; cnt++)
	{
		timer * pTimer = &myTimers[cnt];
		if(pTimer->timerExpired == false || pTimer->enable == false)
		{
			if(pTimer->enable == true)
			{
				if(++pTimer->count >= pTimer->maxValue)
				{
					pTimer->count			= pTimer->maxValue;
					pTimer->timerExpired	= true;
				}
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
void sysTimerSubModuleStart(timer * pTimer, const uint32_t milliSeconds)
{
	DISABLE_GLOBAL_INTERRUPTS();
	pTimer->maxValue		= milliSeconds; 
	pTimer->count			= 0u; 
	pTimer->enable			= true; 
	pTimer->timerExpired	= false;
	ENABLE_GLOBAL_INTERRUPTS(); 
}
void sysTimerSubModuleStop(timer * pTimer)
{
	DISABLE_GLOBAL_INTERRUPTS();
	pTimer->enable			= false; 
	ENABLE_GLOBAL_INTERRUPTS(); 
}
void sysTimerSubModuleResume(timer * pTimer)
{
	DISABLE_GLOBAL_INTERRUPTS();
	pTimer->enable			= true;
	ENABLE_GLOBAL_INTERRUPTS();
}

bool sysTimerSubModuleExpired(timer * pTimer)
{
	return pTimer->timerExpired; 
}