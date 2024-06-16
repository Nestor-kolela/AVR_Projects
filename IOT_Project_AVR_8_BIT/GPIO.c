#include <avr/io.h>
#include "GPIO.h"

void GPIO_Init(void)
{
	//LED 1 LED 2 LED 3 AND LED4 ON PB4, PB5, PB6, PB7 respectively
	DDRB = (1 << DDB4) | (1 << DDB5) | (1 << DDB6) | (1 << DDB7);
	
	PORTB &= ~((1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PB7)); 
	
}