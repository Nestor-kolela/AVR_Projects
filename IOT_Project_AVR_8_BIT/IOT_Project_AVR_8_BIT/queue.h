#ifndef _UART_H
#define _UART_H
#include <stdint.h>

#define SERIAL_TX_BUFFER_SIZE 64
#define SERIAL_RX_BUFFER_SIZE 64

#if (SERIAL_TX_BUFFER_SIZE > 256)
	typedef uint16_t tx_buffer_index_t;
#else
	typedef uint8_t tx_buffer_index_t;
#endif

#if (SERIAL_RX_BUFFER_SIZE > 256)
	typedef uint16_t rx_buffer_index_t;
#else
	typedef uint8_t rx_buffer_index_t;
#endif


typedef struct _queue_struct
{
	volatile rx_buffer_index_t _rx_head;
	volatile rx_buffer_index_t _rx_tail;
	uint8_t * pRxBuffer;
	
	volatile tx_buffer_index_t _tx_head;
	volatile tx_buffer_index_t _tx_tail;
	uint8_t * pTxBuffer; 
}queue_struct;
 
int8_t	queue_peek(queue_struct * ptr); 
int8_t	queue_available(queue_struct * ptr); 
uint8_t queue_read(queue_struct * ptr); 
void	queue_writeforTx(queue_struct * ptr, uint8_t * pData, const uint8_t length) ;
int8_t	queue_availableForTx(queue_struct * ptr); 
uint8_t queue_readForTx(queue_struct * ptr);


extern queue_struct queueForUart0; 
extern queue_struct queueForUart1;


#endif