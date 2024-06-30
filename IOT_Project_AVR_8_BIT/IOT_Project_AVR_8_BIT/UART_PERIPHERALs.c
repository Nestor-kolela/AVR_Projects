/*
 * UART_PERIPHERALs.c
 *
 * Created: 2024/06/14 20:27:53
 *  Author: kolel
 */ 

#include "UART_PERIPHERALs.h"
#include "queue.h"

extern queue_struct queueForUart0;

#define UART0_TX_START()	UCSR0B |=  (1 << UDRIE0) 
#define UART0_TX_STOP()		UCSR0B &= ~((1 << UDRIE0)) 
#define TX_REGISTER			UDR0

ISR(USART0_UDRE_vect)
{
	//Check if there is data pending to be written
	if(queue_availableForTx(&queueForUart0) == 0)
	{
		//No More data to transmit
		UART0_TX_STOP();
	}else
	{
		TX_REGISTER = queue_readForTx(&queueForUart0);
	}
	
}

ISR(USART1_TX_vect)
{
	
}

ISR(USART0_RX_vect)
{
	
	
}

ISR(USART1_RX_vect)
{
	
}

void UART0_Init(void)
{
	/* Set baud rate */
	UBRR0H = (unsigned char)(8>>8); //8 for 115200
	UBRR0L = (unsigned char)8;
	
	UCSR0A = (1 << U2X);
	/* Enable receiver and transmitter */
	UCSR0B = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 1 stop bit */
	UCSR0C = (3<<UCSZ0);
}
void UART0_write(const uint8_t * data, const uint8_t numbOfBytes)
{
	queue_writeforTx(&queueForUart0, data, numbOfBytes); 
	//Generate Interrupt on UDRIEN UDRIEn: USART Data Register Empty Interrupt Enable
	UART0_TX_START(); 
	//At the end of the function, start transmission. 
}