/*Ligacao do Encoder
 * 	MR - A
 * 	VM - B
 * 	LR - Z
 * 	AM - VSS
 * 	VD - VDD
 */

#include <18F45k20.h>

#fuses H4
#use delay(crystal=15MHz, clock=60MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

#define canalA		PIN_A4
#define canalB		PIN_B4
#define canalZ		PIN_B5
#define bto_sobe	PIN_D0
#define bto_desce	PIN_D1

static long aux, cont, cont2;
static short ctrl, sentido;

#INT_TIMER0
void timer0_isr(void) {
	clear_interrupt(INT_TIMER0);
	sentido = input_state(canalB);
}

void main(void) {
	set_timer0(0);
	setup_timer_0(T0_EXT_L_TO_H);
	enable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);
	while (TRUE) {
		if (!input(bto_sobe) && input(bto_desce)) {
			cont = cont2 + get_timer0();
		}
		if (!input(bto_desce) && input(bto_sobe)) {
			cont = cont2 - get_timer0();
		}
		if (input(bto_sobe) && input(bto_desce) && ctrl) {
			set_timer0(0);
			cont2 = cont;
		} else
			ctrl = TRUE;
		if (cont != aux) {
			aux = cont;
			printf("\f%Lu %Lu %d", cont, cont2, sentido);
		}
	}
}
