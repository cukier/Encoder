/*Ligacao do Encoder
 * 	MR - A
 * 	VM - B
 * 	LR - Z
 * 	AM - VSS
 * 	VD - VDD
 */

#include <18F45K20.h>

#fuses H4,NOWDT,NOPROTECT,NOLVP
#use delay(crystal=15MHz, clock=60MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use spi(MASTER, DI=PIN_C4, DO=PIN_C5, CLK=PIN_C3, MODE=0,  BAUD=500000, BITS=16, DATA_HOLD=1)

static long pulsos;
static int zeros;

#INT_EXT
void isr_ext(void){
	clear_interrupt(INT_EXT);
	pulsos++;
}

#INT_EXT1
void isr_ext1(void){
	clear_interrupt(INT_EXT1);
	zeros++
}

void main(void) {
	clear_interrupt(INT_EXT);
	clear_interrupt(INT_EXT1);
	enable_iterrupts(INT_EXT_H2L);
	enable_iterrupts(INT_EXT1_H2L);
	enable_interrpts(GLOBAL);
	while(TRUE){
		printf()
		delay_ms(500);
	}
}
