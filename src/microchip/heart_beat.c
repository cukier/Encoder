/*
 * heart_beat.c
 *
 *  Created on: 11 de jul de 2017
 *      Author: cuki
 */

#include "heart_beat.h"

volatile static uint16_t pino;
volatile static uint16_t tempo;

#INT_TIMER0
void isr_timer0() {
	output_toggle(pino);
	set_timer0(tempo);
	clear_interrupt(INT_TIMER0);
}

void HEART_BEAT_set_beat(uint16_t beat) {
	tempo = beat;
	set_timer0(tempo);

	return;
}

void HEART_BEAT_init(uint16_t pin) {
	pino = pin;
	tempo = HEART_BEAT_MEDIO;

	setup_timer_0(T0_INTERNAL | T0_DIV_32);
	set_timer0(tempo);
	clear_interrupt(INT_TIMER0);
	enable_interrupts(INT_TIMER0);

	return;
}

