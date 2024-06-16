/*
 * GPIO.h
 *
 * Created: 2024/06/15 18:00:48
 *  Author: kolel
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#define LED_1_PIN		PB4
#define LED_1_PORT		PORTB
#define LED_1_TOGGLE()	LED_1_PORT ^=	(1 << LED_1_PIN)
#define LED_1_ON()		LED_1_PORT |=	(1 << LED_1_PIN)
#define LED_1_OFF()		LED_1_PORT &=  ~(1 << LED_1_PIN)


#define LED_2_PIN		PB5
#define LED_2_PORT		PORTB
#define LED_2_TOGGLE()	LED_2_PORT ^=	(1 << LED_2_PIN)
#define LED_2_ON()		LED_2_PORT |=	(1 << LED_2_PIN)
#define LED_2_OFF()		LED_2_PORT &=  ~(1 << LED_2_PIN)

#define LED_3_PIN		PB6
#define LED_3_PORT		PORTB
#define LED_3_TOGGLE()	LED_3_PORT ^=	(1 << LED_3_PIN)
#define LED_3_ON()		LED_3_PORT |=	(1 << LED_3_PIN)
#define LED_3_OFF()		LED_3_PORT &=  ~(1 << LED_3_PIN)

#define LED_4_PIN		PB7
#define LED_4_PORT		PORTB
#define LED_4_TOGGLE()	LED_4_PORT ^=	(1 << LED_4_PIN)
#define LED_4_ON()		LED_4_PORT |=	(1 << LED_4_PIN)
#define LED_4_OFF()		LED_4_PORT &=  ~(1 << LED_4_PIN)

void GPIO_Init(void);

#endif /* GPIO_H_ */