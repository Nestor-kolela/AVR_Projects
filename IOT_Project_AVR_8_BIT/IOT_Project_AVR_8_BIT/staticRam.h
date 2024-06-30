/*
 * staticRam.h
 *
 * Created: 2024/06/17 14:49:22
 *  Author: NK KALAMBAY 
 */ 


#ifndef STATICRAM_H_
#define STATICRAM_H_


#include <stdio.h>
#include <stdint.h>

void	staticRamInit(void);
uint8_t	staticRamRead(const uint32_t address);
void	staticRamWrite(const uint32_t address, uint8_t data);
void	staticRamReadBytes(const uint32_t address, uint8_t * ptr, uint16_t size);
void	staticRamWriteBytes(const uint32_t address, uint8_t * ptr, uint16_t size);

#endif /* STATICRAM_H_ */