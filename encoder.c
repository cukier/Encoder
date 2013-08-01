#include <18F45K20.h>

#fuses H4,NOWDT,NOPROTECT,NOLVP
#use delay(crystal=15MHz, clock=60MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

#include "as5040.h"

static long leitura;

long readDevice(void) {
	long saida;

	output_low(SLAVE_SELECT);
	saida = spi_xfer(0);
	output_high(SLAVE_SELECT);

	return saida;
}

void main(void) {
	output_high(SLAVE_SELECT);
	while (TRUE) {
		leitura = readDevice();
		printf("\f%Lu  -  %d", leitura >> 6, (int) (leitura & 0x0006) >> 1);
		delay_ms(500);
	}
}
