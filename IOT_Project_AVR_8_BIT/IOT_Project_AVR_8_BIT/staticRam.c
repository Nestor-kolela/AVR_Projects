/*
 * staticRam.c
 *
 * Created: 2024/06/17 14:48:39
 *  Author: NK KALAMBAY
 */ 



#include "staticRam.h"
#include "GPIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stddef.h>

#define OFFSET			0x1100
#define START_ADRESS	0x1100 + 0x0000
#define END_ADRESS		0x7FFF - 0x1100

	
uint8_t * ptr = (uint8_t * ) (OFFSET); 

uint8_t	staticRamRead(const uint32_t address)
{
	return * ((volatile uint8_t *)((ptrdiff_t) address + OFFSET)); 
}
void	staticRamWrite(const uint32_t address, uint8_t data)
{
	*((volatile uint8_t *)((ptrdiff_t)address + OFFSET)) = data;
}
void	staticRamReadBytes(const uint32_t address, uint8_t * ptr, uint16_t size)
{
	
}
void	staticRamWriteBytes(const uint32_t address, uint8_t * ptr, uint16_t size)
{
	
}