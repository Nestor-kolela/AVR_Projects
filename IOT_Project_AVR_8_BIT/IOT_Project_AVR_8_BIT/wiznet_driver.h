/*
 * wiznet_driver.h
 *
 * Created: 2024/06/20 18:50:55
 *  Author: NK KALAMBAY
 */ 


#ifndef WIZNET_DRIVER_H_
#define WIZNET_DRIVER_H_
#include <stdint.h>

uint8_t wiznet_5300_read(uint32_t addr); 
void	wiznet_5300_write(uint32_t addr, uint8_t wb);
void	wiznet_5300_chip_select(void); 
void	wiznet_5300_chip_DeSelect(void);

void	enable_global_interrupts(void);
void	disable_global_interrupts(void);

#endif /* WIZNET_DRIVER_H_ */