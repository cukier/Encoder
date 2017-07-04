/*
 * master.c
 *
 *  Created on: 18/08/2014
 *      Author: cuki
 */

#include "sys.h"
#include "lcd.h"
#include "heart_beat.h"
#include "sick.h"

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	
	HB_init();
	lcd_init();
	DSF60_init_encoder();
	sei();
	_delay_ms(100);
	DSF60_check();

	while (1) {
		DSF60_make_transaction(DSF60_COMMAND_READ_POSITION, 0);
		lcd_printf("\fAngulo %f", dsf60->position);		
		HB_beat();
		_delay_ms(500);
	}

	return 0;
}
