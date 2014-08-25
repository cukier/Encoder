/*
 * main.c
 *
 *  Created on: 05/03/2014
 *      Author: cuki
 */

#include <18F45k20.h>

#FUSES HS
#use delay(crystal=16MHz, clock=64MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

#define cmd_subir	1
#define cmd_descer	2
#define cmd_parar	3
#define bto_subir	PIN_B0
#define bto_descer	PIN_B1
#define pin_subir	PIN_D0
#define pin_descer	PIN_D1
#define debounce	100
#define	latencia	1000

short ctrl_bto;
short direction;

int m_cmd;

void parar() {
	output_low(pin_subir);
	output_low(pin_descer);
}

void subir() {
	output_low(pin_descer);
	delay_ms(10);
	output_high(pin_subir);
}

void descer() {
	output_low(pin_subir);
	delay_ms(10);
	output_high(pin_descer);
}

int trata_bto(int cmd) {

	short a = !input(bto_subir);
	short b = !input(bto_descer);
	int ret = cmd;

	if (a ^ b) {
		delay_ms(debounce);
		if (a && ctrl_bto) {
			ret = cmd_subir;
		} else if (b && ctrl_bto) {
			ret = cmd_descer;
		}
		ctrl_bto = FALSE;
	} else if (!ctrl_bto) {
		ctrl_bto = TRUE;
		ret = cmd_parar;
	}

	return ret;
}

int trata_cmd(int cmd) {

	int ret = cmd;

	switch (cmd) {
	case cmd_subir:
		subir();
		ret = cmd_subir;
		break;
	case cmd_descer:
		descer();
		ret = cmd_descer;
		break;
	case cmd_parar:
		parar();
		set_timer0(0);
		set_timer1(0);
		ret = cmd_parar;
		break;
	default:
	}

	return ret;
}

int main(void) {

	set_timer0(0);
	set_timer1(0);

	setup_timer_0(T0_EXT_H_TO_L | T0_DIV_1);
	setup_timer_1(T1_EXTERNAL | T1_DIV_BY_1);

	m_cmd = cmd_parar;

	while (TRUE) {

		m_cmd = trata_cmd(trata_bto(m_cmd));

		if (m_cmd == cmd_subir || m_cmd == cmd_descer) {

			long t0 = get_timer0();
			long t1 = get_timer1();

			direction = (t0 > t1);

			printf("Timer 0: %lu\n\r", t0);
			printf("Timer 1: %lu\n\r", t1);
			printf("Direction: %d\n\r", direction);
		}

		delay_ms(latencia);
	}

	return 0;
}
