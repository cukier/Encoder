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
	
	lcd_init();
	uart_init();
	MODBUS_set_address(1);
	sei();
	_delay_ms(100);

	while (1) {
		//MODBUS_get_register(10);
		lcd_printf("\fEndereco 10: %u", MODBUS_get_register(10));
		_delay_ms(1000);
	}

	return 0;
}
