/*
 * External_Interrupt.c
 *
 * Created: 2024/06/22 10:03:58
 *  Author: NK KALAMBAY
 */ 

#include "GPIO.h"
#include <avr/interrupt.h>

volatile uint16_t VALUE = 0; 
ISR(INT4_vect)
{
	VALUE++; 
}