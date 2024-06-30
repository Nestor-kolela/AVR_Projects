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

static void w5300_write_enable(void);
static void w5300_write_disable(void);

static void wiznet_read_enable(void);
static void wiznet_read_disable(void);

#define WAIT()			//_delay_us(5)

//Global Function... 
uint8_t wiznet_5300_read(uint32_t addr)
{
	//1) CONFIGURE PORTA as output
	//2) Load the lower bits into MCP74AC chip
	//3) Load data into it by toggling the ALE
	//4) Write more address bits into PORTC
	//5) Bring the pin down
	//Configure PORTA as input... 
	//Enable write
	//then read the actual value of PORT A then return it. 
	//Change it to output first...
	PORTA = 0x00; 
	INPUT_OUTPUT_CONTROL_REG = SET_AS_OUTPUT;
	//To Write address to port...
	ADDR_PORT_LOWER = (uint8_t)  (addr & 0x00FF);
		
	//Do the toggle sequence...
	MCP74AC_ON(); //Turn it ON...
	WAIT(); 

	
	ADDR_PORT_UPPER = (uint8_t) ((addr & 0x0300) >> 8);
		
	MCP74AC_OFF(); // Turn it ON so that we can do the reading...
	WAIT();
	
	PORTA = 0x00;
	INPUT_OUTPUT_CONTROL_REG = SET_AS_INPUT;
	
	//Enable read 
	wiznet_read_enable();
	
	
	volatile uint8_t tempValue = INPUT_READ_STATUS_REG; 
	
	wiznet_read_disable(); 
	
	return tempValue; 
	
}

//Global Function
void	wiznet_5300_write(uint32_t addr, uint8_t wb)
{
	//Write enable to address[9:0]
	//wiznet_write_address(); 
	//Write ENABLE
	
	INPUT_OUTPUT_CONTROL_REG = SET_AS_OUTPUT;
	//To Write address to port...
	ADDR_PORT_LOWER = (uint8_t)  (addr & 0x00FF);
		
	//Do the toggle sequence...
	MCP74AC_ON(); //Turn it ON...
	WAIT(); 
	
		
	ADDR_PORT_UPPER = (uint8_t) ((addr & 0x0300) >> 8);
		
	MCP74AC_OFF(); // Turn it ON so that we can do the reading...
	WAIT();
	
	INPUT_OUTPUT_CONFIG_PORT = wb; 
	
	w5300_write_enable();
	
	w5300_write_disable();
}

static void w5300_write_enable(void)
{
	WIZNET_5300_WR_OFF(); 
	WAIT();
}

static void w5300_write_disable(void)
{
	WIZNET_5300_WR_ON(); 
	WAIT();	
}

static void wiznet_read_enable(void)
{
	WIZNET_5300_RD_OFF(); 
	WAIT();
}

static void wiznet_read_disable(void)
{
	WIZNET_5300_RD_ON();
	WAIT();
}

void	wiznet_5300_chip_select(void)
{
	WIZNET_5300_CS_ON(); 
	WAIT();
}
void	wiznet_5300_chip_DeSelect(void)
{
	WIZNET_5300_CS_OFF(); 
	WAIT();
}

void	enable_global_interrupts(void)
{
	sei(); 
}
void	disable_global_interrupts(void)
{
	cli(); 
}