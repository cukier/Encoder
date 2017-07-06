#include "uart.h"

#include <avr/interrupt.h>
#include <util/setbaud.h>
#include <stdarg.h>
#include <stdio.h>

static volatile uint8_t UART_TxBuf[UART_TX_BUFFER_SIZE];
static volatile uint8_t UART_RxBuf[UART_RX_BUFFER_SIZE];
static volatile uint16_t UART_TxHead;
static volatile uint16_t UART_TxTail;
static volatile uint16_t UART_RxHead;
static volatile uint16_t UART_RxTail;

ISR (USART_RX_vect)
{
	UART_RxBuf[UART_RxTail++] = UDR0;
	
	UART_RxTail %= UART_RX_BUFFER_SIZE;
	
	if (UART_RxHead == UART_RxTail)
	{
		UART_RxHead = (UART_RxHead + 1) % UART_RX_BUFFER_SIZE;
	}
}


ISR (USART_UDRE_vect)
{
	if (UART_TxHead != UART_TxTail)
	{
		while (UART_TxHead != UART_TxTail)
		{
			UDR0 = UART_TxBuf[UART_TxHead++];
			UART_TxHead %= UART_TX_BUFFER_SIZE;
		}
	}
	else
	{
		UCSR0B &= ~_BV(UDRIE0);
	}
}

void uart_init(void)
{
	UART_TxHead = 0;
	UART_TxTail = 0;
	UART_RxHead = 0;
	UART_RxTail = 0;
	
	#if USE_2X
	UCSR0A |= _BV(U2X0);
	#else
	UCSR0A &= ~(_BV(U2X0));
	#endif
	
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;
	
	UCSR0B = _BV(RXCIE0);
	UCSR0B = _BV(RXEN0);
	UCSR0B = _BV(TXCIE0);
	UCSR0B = _BV(TXEN0);
	
	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
	
	return;
}

uint16_t uart_get_rx_size(void)
{
	return UART_RxTail - UART_RxHead
	+ (UART_RxHead > UART_RxTail ? UART_RX_BUFFER_SIZE : 0);
}

uint16_t uart_get_tx_size(void)
{
	return UART_TxTail - UART_TxHead
	+ (UART_TxHead > UART_TxTail ? UART_TX_BUFFER_SIZE : 0);
}

void uart_send(uint8_t *data, uint16_t size)
{
	if (!data || !size || (size > UART_TX_BUFFER_SIZE))
	{
		return;
	}
	
	while(size--)
	{
		UART_TxBuf[UART_TxHead++] = *data;
		UART_TxHead %= UART_TX_BUFFER_SIZE;
		
		if (UART_TxHead == UART_TxTail)
		{
			UART_TxHead = (UART_TxHead + 1) % UART_TX_BUFFER_SIZE;
		}
		
		++data;
	}
	
	UCSR0B = _BV(UDRIE0);
	
	return;
}

void uart_putc(char c)
{
	uint8_t d;
	
	d = (uint8_t) c;
	uart_send(&d, 1);
	
	return;
}

void uart_puts(const char *s)
{
	while (*s)
	{
		uart_putc(*s++);
	}
	
	return;
}

void uart_printf(char *format, ...)
{
	va_list args;
	char uart_buffer[UART_TX_BUFFER_SIZE];

	va_start(args, format);
	vsnprintf(uart_buffer, UART_TX_BUFFER_SIZE, format, args);
	va_end(args);
	uart_puts(uart_buffer);
	
	return;
}

uint16_t uart_get(uint8_t *data, uint16_t size)
{
	uint16_t count;
	
	if (!data || !size || (size > UART_RX_BUFFER_SIZE))
	{
		return 0;
	}
	
	count = 0;
	
	while (size-- && (UART_RxHead != UART_TxHead))
	{
		data[count++] = UART_RxBuf[UART_RxHead++];
		UART_RxHead %= UART_RX_BUFFER_SIZE;
	}
	
	return count;
}