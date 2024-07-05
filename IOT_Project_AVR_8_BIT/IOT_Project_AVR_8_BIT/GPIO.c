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
	
	//Initial the output pins for controlling buffer, SRAM and Ethernet chip. 
	//Turn them off
	PORTA &= ~((1 << PA7) | (1 << PA6) | (1 << PA5) | (1 << PA4) | (1 << PA3) | (1 << PA2) | (1 << PA1) | (1 << PA0)); 
	DDRA |= (1 << DDA7) | (1 << DDA6) | (1 << DDA5) | (1 << DDA4) | (1 << DDA3) | (1 << DDA2) | (1 << DDA2) | (1 << DDA1); //Configure them as output
	
	//More pins for output 
	PORTC &= ~((1 << PC7) | (1 << PC6) | (1 << PC5) | (1 << PC4) | (1 << PC3) | (1 << PC2) | (1 << PC1) | (1 << PC0));
	DDRC |= (1 << DDC7) | (1 << DDC6) | (1 << DDC5) | (1 << DDC4) | (1 << DDC3) | (1 << DDC2) | (1 << DDC1) | (1 << DDC0);
	
	//Configure the ALE PIN which is responsible for latching inputs to output in the D Flip Flop
	
	PORTG |= (1 << PG4) | (1 << PG3) | (1 << PG1) | (1 << PG0); //Start these pins as normally high as they are active low
	PORTG &= ~(1 << PG2); //Start this bit as normally low as it is active high
	
	//Configure the pins for PORT G as output
	DDRG |= (1 << DDG4) | (1 << DDG3) | (1 << DDG2) | (1 << DDG1) | (1 << DDG0);
	
	//Don't Configure PORTB as it has been configured above. PIN0 to PB3 will be configured under the SPI function
	
	//Configure PORTE
	PORTE |= 1 << PE4;
	DDRE &= ~(1 << DDE4); 
	SFIOR &= ~(1 << PUD); 
	
	//External Interrupt control byte
	EIMSK &= ~(1 << INT4); //Stop the interrupts for now. 
	
	EICRB &= ~(1 << ISC40); 
	EICRB |= (1 << ISC41); 
	
	//Enable the interrupts
	EIMSK |= 1 << INT4; 
	 
}