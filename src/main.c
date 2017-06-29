/*
 * master.c
 *
 *  Created on: 18/08/2014
 *      Author: cuki
 */

#include "sys.h"
#include "lcd.h"
#include "uart.h"
#include "modbus.h"

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	uint8_t cont;
	uint8_t req[8];
	uint8_t reqp[25];
	
	//cont = 1;
	DDRB |= _BV(DDB0);
	lcd_init();
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	sei();
	_delay_ms(100);
	make_read_request(1, 0, 10, req);

	while (1) {
		uart_send(req, 8);
		_delay_ms(100);
		uart_get(reqp, 25);
		lcd_printf("\f");
		
		for (cont = 0; cont < 8; ++cont) {
			lcd_printf("%02X", reqp[cont]);
		}
		
		lcd_printf("\n");
		
		for (cont = 0; cont < 8; ++cont) {
			lcd_printf("%02X", reqp[cont + 8]);
		}
		
		PORTB ^= _BV(PB0);
		_delay_ms(3000);
	}

	return 0;
}
