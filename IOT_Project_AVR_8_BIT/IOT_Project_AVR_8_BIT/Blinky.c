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
	sysTimerSubModuleInit(50, BlinkyTask); 
}
void BlinkyTask(void)
{
	LED_1_TOGGLE();	
}