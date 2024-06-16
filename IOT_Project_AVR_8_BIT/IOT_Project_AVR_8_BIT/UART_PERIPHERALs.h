/*
 * UART_PERIPHERALs.h
 *
 * Created: 2024/06/14 20:30:42
 *  Author: kolel
 */ 


#ifndef UART_PERIPHERALS_H_
#define UART_PERIPHERALS_H_

#include "queue.h"
#include "avr/interrupt.h"
#include "avr/io.h"
#include <stdint.h>
#include <stdbool.h>

void UART0_Init(void);
void UART0_write(const uint8_t * data, const uint8_t numbOfBytes);


#endif /* UART_PERIPHERALS_H_ */