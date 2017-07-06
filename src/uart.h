#ifndef UART_H
#define UART_H

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <avr/io.h>

#ifndef UART_TX_BUFFER_SIZE
#define UART_TX_BUFFER_SIZE		32
#endif

#ifndef UART_RX_BUFFER_SIZE
#define UART_RX_BUFFER_SIZE		32
#endif

void uart_init(uint32_t baudrate);
uint16_t uart_get_rx_size(void);
uint16_t uart_get_tx_size(void);
void uart_send(uint8_t *data, uint16_t size);
void uart_printf(char *format, ...);
uint16_t uart_get(uint8_t *data, uint16_t size);

#endif // UART_H 

