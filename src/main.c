/*
 * master.c
 *
 *  Created on: 18/08/2014
 *      Author: cuki
 */

#include "sys.h"
#include "lcd.h"
//#include "sick.h"
//#include "uart.h"
//#include "modbus.h"

#define SLV_ADDR		0x01

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	
	DDRB |= _BV(DDB0);
	lcd_init();	
	
	sei();
	_delay_ms(100);

	while (1) {
		lcd_printf("\fAngulo\n%u", MODBUS_get_register(41));		
		PORTB ^= _BV(PB0);
		_delay_ms(500);
	}

	return 0;
}
