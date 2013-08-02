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
#use i2c (slave,scl=PIN_C3,sda=PIN_C4,FORCE_HW,FAST=100000)

#define canalA		PIN_A4
#define canalB		PIN_B4
#define canalZ		PIN_B5
#define bto_sobe	PIN_D0
#define bto_desce	PIN_D1

static signed long cont, cont2, aux, pulsosRecebido;
static long sentido, sentido1;
static short ctrl;
static int estado, lido, primeiraLeitura, segundaLeitura, cmd;

#INT_SSP
void ssp_interrupt() {
	estado = i2c_isr_state();
	if (estado < 0x80) {
		lido = i2c_read();
		if (estado == 1) {
			primeiraLeitura = 0;
			primeiraLeitura = lido;
		} else if (estado == 2) {
			segundaLeitura = 0;
			segundaLeitura = lido;
			pulsosRecebido = make16(primeiraLeitura, segundaLeitura);
		} else if (estado == 3) {
			cmd = 0;
			cmd = lido;
		}
	} else if (estado == 0x80) {
		if (primeiraLeitura == 0) {
			i2c_write(make8(cont, 1));
		} else if (primeiraLeitura == 1) {
			i2c_write(make8(cont, 0));
		}
	}
}

#INT_EXT
void ext_isr(void) {
	clear_interrupt(INT_EXT);
	if (input_state(canalB))
		sentido++;
	else
		sentido1++;
}

void main(void) {
	set_timer0(0);
	setup_timer_0(T0_EXT_L_TO_H);
	port_b_pullups(TRUE);
	clear_interrupt(INT_EXT);
	enable_interrupts(INT_EXT_L2H);
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
		if (aux != cont) {
			aux = cont;
			printf("\f%Lu %Lu\n%Ld %Ld", cont, cont2, sentido, sentido1);
		}
	}
}
