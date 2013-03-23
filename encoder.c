#include <18F45K20.h>

#fuses H4,NOWDT,NOPROTECT,NOLVP
#use delay(crystal=15MHz, clock=60MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use spi(MASTER, DI=PIN_C4, DO=PIN_C5, CLK=PIN_C3, MODE=0,  BAUD=1000000, BITS=16, DATA_HOLD=1)

#define SLAVE_SELECT PIN_A5
#include "as5040.h"

static long leitura;
static int zero;

void main(void) {
	delay_ms(100);
	zero = 0;
	clear_bus();
	delay_ms(100);
	setup_encoder(clockwise | _7_bit_resolution | step_direction_mode, zero);
	clear_bus();
	printf("\n\rProg: 7 bits zero %d", zero);
	delay_ms(1000);
	while (TRUE) {
		output_low(SLAVE_SELECT);
		leitura = spi_xfer(0);
		output_high(SLAVE_SELECT);
		printf(" \n\r%Lu  -  %d", leitura >> 6, (int) (leitura & 0x0006) >> 1);
		delay_ms(500);
	}
}
