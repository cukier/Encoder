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

int main(void) {
	bool n;

	delay_ms(1000);
	n = false;
	init_uart();
	MODBUS_set_address(1);
	enable_interrupts(GLOBAL);
	delay_ms(1000);
	n = DSF60_check();
	fprintf(sl1, "Check %u\n", n);

	while (TRUE) {
		if (n) {
			n = DSF60_make_transaction(DSF60_COMMAND_READ_POSITION, 0);
			MODBUS_set_register(0, (uint16_t) dsf60.position);
			delay_ms(100);
		} else {
			n = DSF60_check();
		}
	}

	return 0;
}
