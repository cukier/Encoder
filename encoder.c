#include <18F452.h>

#fuses	H4,NOOSCSEN,NOPUT,NOBROWNOUT,NOWDT,NOSTVREN,NOLVP
#fuses	NODEBUG,NOPROTECT,NOCPB,NOCPD,NOWRT,NOWRTC,NOWRTB
#fuses	NOWRTD,NOEBTR,NOEBTRB

#use delay(clock=32MHz, crystal=8MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use spi(MASTER, DI=PIN_C4, DO=PIN_C5, CLK=PIN_C3, MODE=3,  BAUD=2000000, BITS=12, DATA_HOLD=1)

static long aux, resol;

int main(void) {

	setup_timer_0(T0_DIV_1);

	while (true) {
		delay_ms(500);
		aux = spi_xfer(0);
		if (aux >= resol)
			resol = aux + 1;
		printf("%Lu %Lu\n%.5f", aux, resol, (float) aux * 360 / resol);
	}
	return 0;
}
