/*
 * queue.c
 *
 * Created: 2024/06/14 19:13:20
 *  Author: NK KALAMBAY
 */ 

#include "queue.h"

unsigned char _uart0_rx_buffer[SERIAL_RX_BUFFER_SIZE];
unsigned char _uart0_tx_buffer[SERIAL_TX_BUFFER_SIZE];

unsigned char _uart1_rx_buffer[SERIAL_RX_BUFFER_SIZE];
unsigned char _uart1_tx_buffer[SERIAL_TX_BUFFER_SIZE];

queue_struct queueForUart0 = 
{
	._rx_head = 0,
	._rx_tail = 0,
	._tx_head = 0,
	._tx_tail = 0,
	.pRxBuffer	= &_uart0_rx_buffer[0],
	.pTxBuffer	= &_uart0_tx_buffer[0], 
};
queue_struct queueForUart1 =
{
	._rx_head = 0,
	._rx_tail = 0,
	._tx_head = 0,
	._tx_tail = 0,
	.pRxBuffer	= &_uart1_rx_buffer[0],
	.pTxBuffer	= &_uart1_tx_buffer[0],
};


int8_t	queue_available(queue_struct * ptr)
{
	return ((int8_t) (SERIAL_RX_BUFFER_SIZE + ptr->_rx_head - ptr->_rx_tail)) % SERIAL_RX_BUFFER_SIZE;
}
int8_t queue_peek(queue_struct * ptr)
{
	if (ptr->_rx_head == ptr->_rx_tail) 
	{
		return -1;
	} else 
	{
		return (int8_t) *(ptr->pRxBuffer  + ptr->_rx_tail);
	}
	
}
uint8_t queue_read(queue_struct * ptr) 
{
	// if the head isn't ahead of the tail, we don't have any characters
	if (ptr->_rx_head == ptr->_rx_tail) 
	{
		return -1;
	} else 
	{
		unsigned char c = *(ptr->pRxBuffer  + ptr->_rx_tail);
		ptr->_rx_tail = (rx_buffer_index_t) (ptr->_rx_tail + 1) % SERIAL_RX_BUFFER_SIZE;
		return (int8_t)c;
	}

}

void queue_writeforTx(queue_struct * ptr, uint8_t * pData, const uint8_t length) 
{
	for(uint8_t cnt = 0; cnt < length; cnt++)
	{
		tx_buffer_index_t i = (ptr->_tx_head + 1) % SERIAL_TX_BUFFER_SIZE;
		if(i == ptr->_tx_tail)
		{
			return; 
		}
		*(ptr->pTxBuffer + ptr->_tx_head) = *pData++;
		ptr->_tx_head = i;
		
	}
	return; 
}

int8_t	queue_availableForTx(queue_struct * ptr)
{
	return ((int8_t) (SERIAL_RX_BUFFER_SIZE + ptr->_tx_head - ptr->_tx_tail)) % SERIAL_RX_BUFFER_SIZE;
}

uint8_t queue_readForTx(queue_struct * ptr)
{
	// if the head isn't ahead of the tail, we don't have any characters
	if (ptr->_tx_head == ptr->_tx_tail)
	{
		return -1;
	} else
	{
		unsigned char c = *(ptr->pTxBuffer  + ptr->_tx_tail);
		ptr->_tx_tail = (tx_buffer_index_t) (ptr->_tx_tail + 1) % SERIAL_RX_BUFFER_SIZE;
		return (int8_t)c;
	}
}