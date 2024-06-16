/*
 * IOT_Project_AVR_8_BIT.c
 *
 * Created: 2024/06/13 21:48:31
 * Author : NK KALAMBAY
 */ 


#define F_CPU 8000000UL


#include <avr/io.h>
#include "GPIO.h"
#include "util/delay.h"
#include "UART_PERIPHERALs.h"
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    /* Replace with your application code */
	
	GPIO_Init(); 
	UART0_Init(); 
	
	//wizchip_init(txBuffer, rxBuffer); 
	
	sei(); //Interrupt global interrupts. 
	
    while (1) 
    {
		_delay_ms(100); 
		LED_1_TOGGLE(); 
		UART0_write((uint8_t *) "Hello World\r\n", 13);
    }
}