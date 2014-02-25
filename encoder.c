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
#use i2c (slave,scl=PIN_C3,sda=PIN_C4,FORCE_HW,FAST=100000)

#define canalA		PIN_B0
#define canalB		PIN_B4
#define canalZ		PIN_B5
#define bto_sobe	PIN_D0
#define bto_desce	PIN_D1
#define bto_maual	PIN_A4
#define cmd_sobe	1
#define cmd_desce	2
#define cmd_manual	3
#define cmd_parar	4
#define debounce	100

short ctrl;
short trigger = FALSE;
int cont = 0;
char str[32];

short check_bto(int bto) {
	if (!input(bto)) {
		delay_ms(debounce);
		return !input(bto);
	}
	return FALSE;
}

int controle_btos(void) {
	short a, b, c;
	int ret = 0;

	a = check_bto(bto_sobe);
	b = check_bto(bto_desce);
	c = check_bto(bto_maual);

	if (a && ctrl) {
		ctrl = FALSE;
		strcpy(str, "Pressionado Bto\nSobe");
		ret = cmd_sobe;
	} else if (b && ctrl) {
		ctrl = FALSE;
		strcpy(str, "Pressionado Bto\nDesce");
		ret = cmd_desce;
	} else if (c && ctrl) {
		ctrl = FALSE;
		strcpy(str, "Pressionado Bto\nManual");
		ret = cmd_manual;
	} else if (!(a || b || c) && !ctrl) {
		ctrl = TRUE;
		strcpy(str, "Botoes Soltos\n");
		ret = cmd_parar;
	}

	return ret;
}

short f_trig(int pino) {

}

int main(void) {

	int cmd = 0;
	long cont_timer1, aux;

	set_timer1(0);
	setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
	delay_ms(300);

	while (TRUE) {
		cont_timer1 = get_timer1();
		if (!input(canalZ)) {
			set_timer1(0);
			cont_timer1 = 0;
		}
		if (aux != cont_timer1) {
			aux = cont_timer1;
			printf("Timer 1: %lu\r\nAngulo: %.2f\n\r", cont_timer1,
					(float) cont_timer1 / 1024 * 360);
			delay_ms(1000);
		}
	}

	return 0;
}
