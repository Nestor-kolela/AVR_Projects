/*
 * externMemInterface.c
 *
 * Created: 2024/06/28 22:05:59
 *  Author: NK KALAMBAY
 */ 

#include "externMemInterface.h"
#include <avr/io.h>
void External_Mem_Inter_Init(void)
{
	MCUCR |= (1 << SRE) | (1 << SRW10);
	XMCRA |= (1<<SRL2);
}