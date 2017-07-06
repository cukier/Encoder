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

#include <Canbus.h>
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

int main(void) {
	tCAN message;
	
	message.id = 0x631; //formatted in HEX
	message.header.rtr = 0;
	message.header.length = 8; //formatted in DEC
	message.data[0] = 0x40;
	message.data[1] = 0x05;
	message.data[2] = 0x30;
	message.data[3] = 0xFF; //formatted in HEX
	message.data[4] = 0x00;
	message.data[5] = 0x40;
	message.data[6] = 0x00;
	message.data[7] = 0x00;
	
	HB_init();
	lcd_init();
	DSF60_init_encoder();
	Canbus.init();
	sei();
	_delay_ms(100);
	mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);

	while (1) {
		mcp2515_send_message(&message);
		_delay_ms(1000);
	}

	return 0;
}
