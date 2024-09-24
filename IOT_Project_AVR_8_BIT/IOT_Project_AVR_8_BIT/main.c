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
#include "sysTimer.h"
#include "BlinkyTask.h"
#include "IOT_Library/Ethernet/wizchip_conf.h"
#include "IOT_Library/Ethernet/W5300/w5300.h"
#include "wiznet_driver.h"
#include "staticRam.h"
#include "externMemInterface.h"
#include "IOT_Library/Internet/DHCP/dhcp.h"
#include "IOT_Library/Internet/DNS/dns.h"
#include <stdio.h>

uint8_t txBuffer[8] = {8, 8, 8, 8, 8, 8, 8, 8};
uint8_t rxBuffer[8] = {8, 8, 8, 8, 8, 8, 8, 8};
	
uint8_t ethernetBuffer[2048] = {0,};
	
//Function Prototype. 
static int uart_putchar(char c, FILE *stream);
//Functions for re-directing printf to uart... 
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

static int uart_putchar(char c, FILE *stream)
{
	uint8_t * ptr = (uint8_t *) &c; 
	UART0_write(ptr, 1); 
	return 0;
}


int main(void)
{
    /* Replace with your application code */
	_delay_ms(5);
	GPIO_Init(); 
	UART0_Init(); 
	sysTimerInit();
	External_Mem_Inter_Init(); 
	
	stdout = &mystdout; //Re-direct PRINTF TO UART... 
	
	//1) Define the Exit and Entry for ISR
	reg_wizchip_cris_cbfunc(&disable_global_interrupts, &enable_global_interrupts); 
	
	wizchip_init(txBuffer, rxBuffer); 
	
	sei(); //Interrupt global interrupts. 
	
	Blinky_Init();
	
	//DHCP
	DHCP_init(0, ethernetBuffer);

	//For SRAM the address 0x0000 - 0x7FFF
	//For Ethernet device  0x8000 - 0x83FF

	sysTimerSubModuleInit(1000, DHCP_time_handler);
	
	printf("Starting...\r\n");
	
    while (1) 
    {
		DHCP_run();
    }
}