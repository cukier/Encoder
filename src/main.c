/*
 * master.c
 *
 *  Created on: 18/08/2014
 *      Author: cuki
 */

#define F_CPU 10000000ULL

#include <avr/io.h>
#include <util/delay.h>

int main(int argc, char **argv) {

	DDRB |= _BV(DDB0);

	while (1) {
		PORTB ^= _BV(PB0);
		_delay_ms(500);
	}

	return 0;
}
