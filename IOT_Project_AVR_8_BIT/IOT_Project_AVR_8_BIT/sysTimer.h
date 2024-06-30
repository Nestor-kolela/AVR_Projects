/*
 * sysTimer.h
 *
 * Created: 2024/06/18 18:38:38
 *  Author: NK KALAMBAY
 */ 


#ifndef SYSTIMER_H_
#define SYSTIMER_H_
#include <stdbool.h>
#include <stdint.h>
#include "defines.h"

typedef struct _timer_
{
	uint32_t	count; 
	uint32_t	maxValue; 
	bool 		timerExpired; 
	bool		enable; 
}timer;

//Value to load. 
#define TIMER_VALUE		1000 //for 1000 = 1millisecond
#define TIMER_MAX_SIZE	4


extern timer myTimers[TIMER_MAX_SIZE]; 

//Hardware timer Functions. 
void sysTimerInit(void); 
void sysTimerStart(void);
void sysTimerStop(void); 

//Timer functionality functions. 
void sysTimerSubModuleStart(timer * pTimer, const uint32_t milliSeconds); 
void sysTimerSubModuleStop(timer * pTimer); 
void sysTimerSubModuleResume(timer * pTimer); 
bool sysTimerSubModuleExpired(timer * pTimer); 

#endif /* SYSTIMER_H_ */