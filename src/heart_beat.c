#include "heart_beat.h"

#include <util/delay.h>

void HB_init(void)
{
	DDRB |= _BV(DDB1);
	
	return;
}

void HB_beat(void)
{
	PORTB |= _BV(PORTB1);
	_delay_ms(200);
	PORTB &= ~_BV(PORTB1);
	
	return;
}