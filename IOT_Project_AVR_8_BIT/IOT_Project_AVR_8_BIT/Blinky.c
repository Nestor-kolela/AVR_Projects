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
}