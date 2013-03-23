/*
 * gerador.c
 *
 *  Created on: 23/03/2013
 *      Author: cuki
 */

#include <18F45K20.h>

#fuses H4,NOWDT,NOPROTECT,NOLVP
#use delay(crystal=15MHz, clock=60MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use spi(MASTER, DI=PIN_C4, DO=PIN_C5, CLK=PIN_C3, MODE=0,  BAUD=1000000, BITS=16, DATA_HOLD=1)

int main(void) {
	while (TRUE) {
		output_toggle(PIN_D0);
		delay_ms(5);
	}
	return 0;
}
