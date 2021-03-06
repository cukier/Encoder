/*
 * controle.c
 *
 *  Created on: 14 de jul de 2017
 *      Author: cuki
 */

/*
 * blink.c
 *
 *  Created on: 04/11/2014
 *      Author: cuki
 */

#include "uart.c"
#include "modbus.c"
#include "sick.c"
#include "heart_beat.c"

#include <stdbool.h>
#include <stdint.h>

static volatile bool n, change_beat, encOk, plcOk;
static volatile uint8_t leituras;
static volatile uint16_t resolucao, resAux;

void get_plc_resolution(void) {
	resAux = MODBUS_get_register(47);
	n = (resAux != 0xFFFF);
	plcOk = n;

	return;
}

void set_plc_resolution(void) {
	n = MODBUS_set_register(47, resolucao);
	plcOk = n;
	resAux = resolucao;

	return;
}

void get_enc_resolution(void) {
	n = DSF60_make_transaction(DSF60_COMMAND_READ_ENCODER_TYPE, 0);
	encOk = n;

	if (n) {
		resolucao = (uint16_t) dsf60.resolution;
	} else {
		resolucao = 0;
	}

	return;
}

bool set_enc_resolution(void) {
	n = DSF60_make_transaction(DSF60_COMMAND_SET_NUMBER_OF_LINES,
			(uint32_t) resolucao);
	encOk = n;

	return n;
}

void init(void) {
	uint16_t m_res;

	leituras = 0;
	resolucao = 0;
	resAux = 0;
	change_beat = true;
	n = false;
	HEART_BEAT_init(PIN_C2);
	init_uart();
	MODBUS_set_address(1);
	enable_interrupts(GLOBAL);
	delay_ms(1000);
	n = DSF60_check();

	if (n)
		get_enc_resolution();

	if (n)
		set_plc_resolution();

	return;
}

uint16_t check_encoder(void) {
	n = DSF60_make_transaction(DSF60_COMMAND_READ_POSITION, 0);
	encOk = n;

	if (n)
		return dsf60.position;
	else
		return 0xFFFF;
}

bool check_plc(uint16_t pos) {
	n = MODBUS_set_register(7, pos);
	plcOk = n;

	return n;
}

int pooling(void) {
	uint16_t m_pos;

	m_pos = 0;

	while (TRUE) {
		if (n) {
			if (change_beat) {
				change_beat = false;
				HEART_BEAT_set_beat(HEART_BEAT_LENTO);
			}

			m_pos = check_encoder();

			if (n) {
				check_plc(m_pos);
			}

			if (n) {
				leituras++;

				if (leituras == 5) {
					leituras = 0;
					get_enc_resolution();

					if (n) {
						get_plc_resolution();

						if (n) {
							if (resAux != resolucao) {
								resolucao = resAux;
								set_enc_resolution();
								n = DSF60_check();
							}
						}
					}
				}
			}

			delay_ms(10);
		} else {
			if (!change_beat) {
				change_beat = true;
				HEART_BEAT_set_beat(HEART_BEAT_RAPIDO);
			}

			if (!encOk) {
				n = DSF60_check();
				encOk = n;
			}

			if (!plcOk) {
				m_pos = check_encoder();

				if (n) {
					check_plc(m_pos);
				}
			}
		}
	}

	return 0;
}
