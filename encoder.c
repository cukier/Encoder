/*Ligacao do Encoder
 * 	MR - A
 * 	VM - B
 * 	LR - Z
 * 	AM - VSS
 * 	VD - VDD
 */

#include <18F452.h>

#fuses H4,NOWDT,NOPROTECT,NOLVP
#use delay(crystal=10MHz, clock=40MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use spi(MASTER, DI=PIN_C4, DO=PIN_C5, CLK=PIN_C3, MODE=0,  BAUD=500000, BITS=16, DATA_HOLD=1)

static long pulsos, pulsosMax;
static int zeros;

#INT_EXT
void isr_ext(void) {
	clear_interrupt(INT_EXT);
	pulsos++;
	if(pulsos > pulsosMax)
		pulsosMax = pulsos;
}

#INT_EXT1
void isr_ext1(void) {
	clear_interrupt(INT_EXT1);
	pulsos = 0;
	zeros++;
}

void main(void) {
	clear_interrupt(INT_EXT);
	clear_interrupt(INT_EXT1);
	enable_interrupts(INT_EXT_H2L);
	enable_interrupts(INT_EXT1_H2L);
	enable_interrupts(GLOBAL);
	while (TRUE) {
		printf("\n\rPulsos: %Lu, Zeros:%d Max:%Lu", pulsos, zeros, pulsosMax);
		delay_ms(500);
	}
}
