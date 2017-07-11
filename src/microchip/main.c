/*
 * blink.c
 *
 *  Created on: 04/11/2014
 *      Author: cuki
 */

#include <18F25K22.h>
#device ADC=10
#fuses NOWDT, INTRC, NOPLLEN, NOFCMEN, NOIESO, PUT
#fuses BROWNOUT, BORV29, STVREN, NOLVP, NODEBUG, NOCPB
#fuses NOCPD, NOXINST, NOPBADEN, NOPROTECT

#use delay(internal=16MHz)

#include "uart.c"
#include "modbus.c"
#include "sick.c"
#include "heart_beat.c"

static volatile bool n, change_beat;
static volatile bool encOk, plcOk;

void init(void) {
	change_beat = true;
	n = false;
	HEART_BEAT_init(PIN_C2);
	init_uart();
	MODBUS_set_address(1);
	enable_interrupts(GLOBAL);
	delay_ms(1000);
	n = DSF60_check();

	return;
}

void check_encoder(void) {
	n = DSF60_make_transaction(DSF60_COMMAND_READ_POSITION, 0);
	encOk = n;

	return;
}

void check_plc(void) {
	n = MODBUS_set_register(0, (uint16_t) dsf60.position);
	plcOk = n;

	return;
}

int main(void) {

	init();

	while (TRUE) {
		if (n) {
			if (change_beat) {
				change_beat = false;
				HEART_BEAT_set_beat(HEART_BEAT_LENTO);
			}

			check_encoder();

			if (n) {
				check_plc();
			}

			delay_ms(100);
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
				check_encoder();

				if (n) {
					check_plc();
				}
			}
		}
	}

	return 0;
}
