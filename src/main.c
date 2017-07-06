/*
* master.c
*
*  Created on: 18/08/2014
*      Author: cuki
*/

#include "sys.h"
#include "uart.h"

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	uint16_t cont;
	
	cont = 0;
	uart_init();
	sei();
	_delay_ms(100);

	while (1) {
		uart_printf("Count %d\n", cont++);
		_delay_ms(1000);
	}

	return 0;
}
