/*
 * defines.h
 *
 * Created: 2024/06/18 18:49:02
 *  Author: kolel
 */ 


#ifndef DEFINES_H_
#define DEFINES_H_


#include <avr/io.h>
#include <avr/interrupt.h>

#define DISABLE_GLOBAL_INTERRUPTS()			cli()
#define ENABLE_GLOBAL_INTERRUPTS()			sei()

#define GET_FIRST_BYTE(x)					(uint8_t) ( x & 0x000000FF)
#define GET_SEC_BYTE(x)						(uint8_t) ((x & 0x0000FF00) >> 8)
#define GET_THIRD_BYTE(x)					(uint8_t) ((x & 0x00FF0000) >> 16)
#define GET_FORTH_BYTE(x)					(uint8_t) ((x & 0xFF000000) >> 24)

#endif /* DEFINES_H_ */