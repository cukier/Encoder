/*
 * master.c
 *
 *  Created on: 18/08/2014
 *      Author: cuki
 */

#include "sys.h"
#include "lcd.h"
#include "heart_beat.h"
//#include "sick.h"
//#include "uart.h"
//#include "modbus.h"

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	
	HB_init();
	lcd_init();	
	
	sei();
	_delay_ms(100);

	while (1) {
		lcd_printf("\fAngulo");		
		HB_beat();
		_delay_ms(500);
	}

	return 0;
}
