/*
 * GPIO.c
 *
 * Created: 2024/06/15 18:01:02
 *  Author: NK KALAMBAY
 */ 

#include "GPIO.h"
#include <avr/io.h>
void GPIO_Init(void)
{
	//Configure the LEDS
	PORTB &= ~(( 1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PB7)); 
	DDRB |= (( 1 << DDB4) | (1 << DDB5) | (1 << DDB6) | (1 << DDB7)); 
}