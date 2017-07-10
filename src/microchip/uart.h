/*
 * uart.h
 *
 *  Created on: 10 de jul de 2017
 *      Author: cuki
 */

#ifndef SRC_UART_H_
#define SRC_UART_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef MODUBS_USE_SL1
#use rs232(uart1, baud=19200, stream=sl1)
#elif defined ENCODER_USE_SL1
#use rs232(uart2, baud=115200, parity=e, stream=sl1)
#else
#use rs232(uart1, baud=9600, stream=sl1)
#endif

#ifdef ENCODER_USE_SL2
#use rs232(uart2, baud=115200, parity=e, stream=sl2)
#elif defined MODUBS_USE_SL2
#use rs232(uart2, baud=19200, stream=sl2)
#else
#use rs232(uart1, baud=9600, stream=sl2)
#endif

#ifndef RX1_BUFFER_SIZE
#define RX1_BUFFER_SIZE		127
#endif

#ifndef RX2_BUFFER_SIZE
#define RX2_BUFFER_SIZE		127
#endif

void init_uart(void);
void uart1_send(uint8_t *data, uint16_t n);
void uart1_get(uint8_t *data, uint16_t n);
uint16_t uart1_rx_size(void);
void uart1_flush(void);
void uart2_send(uint8_t *data, uint16_t n);
void uart2_get(uint8_t *data, uint16_t n);
uint16_t uart2_rx_size(void);
void uart2_flush(void);

#endif /* SRC_UART_H_ */
