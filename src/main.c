/*
* master.c
*
*  Created on: 18/08/2014
*      Author: cuki
*/

#include "sys.h"
#include "uart.h"
#include "modbus.h"
#include "lcd.h"

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	uint16_t cont, var;
	
	cont = 0;
	lcd_init();
	uart_init();
	MODBUS_set_address(1);
	sei();
	_delay_ms(100);

	while (1) {
		var = 0;
		var = MODBUS_get_register(cont);
		lcd_printf("\fEnd %u: %u", cont, var);
		cont++;
		_delay_ms(500);
	}

	return 0;
}
