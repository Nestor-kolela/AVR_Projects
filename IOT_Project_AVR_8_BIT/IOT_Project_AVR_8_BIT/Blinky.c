/*
 * Blinky.c
 *
 * Created: 2024/06/19 21:36:52
 *  Author: NK KALAMBAY
 */ 
#include "BlinkyTask.h"
#include "GPIO.h"
#include "UART_PERIPHERALs.h"
void Blinky_Init(void)
{
	sysTimerSubModuleStart(&myTimers[0], 50); 
}
void BlinkyTask(void)
{
	if(sysTimerSubModuleExpired(&myTimers[0]) == true)
	{
		sysTimerSubModuleStart(&myTimers[0], 50);
		LED_1_TOGGLE();
	}
	
	#if 0
	if(sysTimerSubModuleExpired(&myTimers[1]) == true)
	{
		sysTimerSubModuleStart(&myTimers[1], 100);
		LED_2_TOGGLE();
	}
	
	if(sysTimerSubModuleExpired(&myTimers[2]) == true)
	{
		sysTimerSubModuleStart(&myTimers[2], 150);
		LED_3_TOGGLE();
	}
	
	if(sysTimerSubModuleExpired(&myTimers[3]) == true)
	{
		sysTimerSubModuleStart(&myTimers[3], 200);
		LED_4_TOGGLE();
	}
	#endif
}