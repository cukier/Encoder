/*
 * uart.c
 *
 *  Created on: 7 de jul de 2017
 *      Author: cuki
 */

#include "uart.h"

#include <STDLIBM.H>

static volatile uint16_t rx1_head, rx1_tail, rx2_head, rx2_tail;

//#define ALOCAMENTO_DINAMICO

#ifdef ALOCAMENTO_DINAMICO
volatile static uint8_t *rx1_buffer;
volatile static uint8_t *rx2_buffer;
#else
volatile static uint8_t rx1_buffer[RX1_BUFFER_SIZE];
volatile static uint8_t rx2_buffer[RX2_BUFFER_SIZE];
#endif

#INT_RDA
void isr_rda() {
	rx1_buffer[rx1_tail++] = fgetc(sl1);
	rx1_tail %= RX1_BUFFER_SIZE;

	if (rx1_head == rx1_tail)
		rx1_head = (rx1_head + 1) % RX1_BUFFER_SIZE;

	clear_interrupt(INT_RDA);
}

#INT_RDA2
void isr_rda2() {
	rx2_buffer[rx2_tail++] = fgetc(sl2);
	rx2_tail %= RX2_BUFFER_SIZE;

	if (rx2_head == rx2_tail)
		rx2_head = (rx2_head + 1) % RX1_BUFFER_SIZE;

	clear_interrupt(INT_RDA2);
}

void init_uart(void) {
	rx1_head = 0;
	rx1_tail = 0;
	rx2_head = 0;
	rx2_tail = 0;

#ifdef ALOCAMENTO_DINAMICO
	rx1_buffer = (uint8_t *) malloc(RX1_BUFFER_SIZE * sizeof(uint8_t));
	rx2_buffer = (uint8_t *) malloc(RX2_BUFFER_SIZE * sizeof(uint8_t));
#endif

	clear_interrupt(INT_RDA);
	enable_interrupts(INT_RDA);
	clear_interrupt(INT_RDA2);
	enable_interrupts(INT_RDA2);
}

void uart1_send(uint8_t *data, uint16_t n) {
	int cont;

	for (cont = 0; cont < n; ++cont) {
		fputc(data[cont], sl1);
	}

	return;
}

void uart1_get(uint8_t *data, uint16_t n) {
	uint16_t cont;

	if (!data || !n || n > RX1_BUFFER_SIZE)
		return;

	cont = 0;
	while (n--) {
		data[cont++] = rx1_buffer[rx1_head++];
	}
}

uint16_t uart1_rx_size(void) {
	return rx1_tail - rx1_head + (rx1_head > rx1_tail ? RX1_BUFFER_SIZE : 0);
}

void uart1_flush(void) {
	rx1_tail = 0;
	rx1_head = 0;

	return;
}

void uart2_send(uint8_t *data, uint16_t n) {
	int cont;

	for (cont = 0; cont < n; ++cont) {
		fputc(data[cont], sl2);
	}

	return;
}

void uart2_get(uint8_t *data, uint16_t n) {
	uint16_t cont;

	if (!data || !n || n > RX1_BUFFER_SIZE)
		return;

	cont = 0;
	while (n--) {
		data[cont++] = rx2_buffer[rx2_head++];
	}
}

uint16_t uart2_rx_size(void) {
	return rx2_tail - rx2_head + (rx2_head > rx2_tail ? RX2_BUFFER_SIZE : 0);
}

void uart2_flush(void) {
	rx2_tail = 0;
	rx2_head = 0;

	return;
}
