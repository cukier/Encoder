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

#define	saida_desce	PIN_B6
#define	saida_sobe	PIN_B7
#define canalA		PIN_B0
#define canalZ		PIN_B1
#define canalB		PIN_B2

static long pulsos, pulsosMax;
static int zeros;

#include "funcoes.h"
#include "lcd_8b.c"

#INT_EXT
void isr_ext(void) {
	clear_interrupt(INT_EXT);
	if (input(canalB))
		pulsos++;
	else {
		if (pulsos > 0)
			pulsos--;
		else
			pulsos = 1023;
	}
	if (pulsos > pulsosMax)
		pulsosMax = pulsos;
}

#INT_EXT1
void isr_ext1(void) {
	clear_interrupt(INT_EXT1);
	pulsos = 0;
	zeros++;
}

void main(void) {
	parar();
	lcd_init();
	port_b_pullups(TRUE);
	delay_ms(100);
	clear_interrupt(INT_EXT);
	clear_interrupt(INT_EXT1);
	enable_interrupts(INT_EXT_L2H);
	enable_interrupts(INT_EXT1_L2H);
	enable_interrupts(GLOBAL);
	subir();
	while (TRUE) {
		printf(lcd, "\fPulsos: %Lu\nZeros:%d Max:%Lu", pulsos, zeros, pulsosMax);
		delay_ms(500);
	}
}
