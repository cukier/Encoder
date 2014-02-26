/*Ligacao do Encoder
 * 	MR - A
 * 	VM - B
 * 	LR - Z
 * 	AM - VSS
 * 	VD - VDD
 */

/*Quando encoder não programado:
 * nr maximo de pulsos...
 * no pino T0CLK : 128
 * no pino EXT:	255
 */

#include <18F45k20.h>

#FUSES H4
#use delay(crystal=16MHz, clock=64MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
//#use i2c (slave,scl=PIN_C3,sda=PIN_C4,FORCE_HW,FAST=100000)

#define canalA		PIN_B0
#define canalB		PIN_B4
#define canalZ		PIN_B5
#define tempo0		18660

#include "botoes.c"

short print;
long resolucao = 255;

#INT_TIMER0
void isr_timer0() {
	clear_interrupt(INT_TIMER0);
	set_timer0(tempo0);
	print = TRUE;
}

short r_trig(short clk, int *ctrl) {
	if (clk && !*ctrl) {
		*ctrl = TRUE;
		return TRUE;
	} else if (!clk)
		*ctrl = FALSE;
	return FALSE;
}

int main(void) {

	int cmd = 0, ctrl1, aux = 0, ctrl2;
	long cont_timer1, max;

	set_timer1(0);
	setup_timer_1(T1_EXTERNAL | T1_DIV_BY_1);
	set_timer0(tempo0);
	setup_timer_0(T0_INTERNAL | T0_DIV_256);
	clear_interrupt(INT_TIMER0);
	enable_interrupts(INT_TIMER0 | GLOBAL);
	delay_ms(300);

	while (TRUE) {

		cont_timer1 = get_timer1();
		cmd = controle_btos();

		if (r_trig((cmd == cmd_sobe), &ctrl2)) {
			output_toggle(PIN_A5);
			printf("\fSobre");
			set_timer0(tempo0);
		}

		if (r_trig(!input(canalZ), &ctrl1)) {
			max = cont_timer1;
			set_timer1(0);
			cont_timer1 = 0;
			aux++;
		}

		if (print) {
			print = FALSE;
			printf("\fTimer 1: %lu %d\nAngulo: %.2f", cont_timer1, aux,
					(float) cont_timer1 / resolucao * 360);
		}
	}

	return 0;
}
