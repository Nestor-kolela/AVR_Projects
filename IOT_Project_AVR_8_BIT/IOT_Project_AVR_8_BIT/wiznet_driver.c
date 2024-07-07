/*
 * wiznet_driver.c
 *
 * Created: 2024/06/20 18:50:22
 *  Author: NK KALAMBAY
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "wiznet_driver.h"
#include "GPIO.h"

void	enable_global_interrupts(void)
{
	sei(); 
}
void	disable_global_interrupts(void)
{
	cli(); 
}