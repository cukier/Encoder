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

#define debounce	100

short ctrl, a, b, c;
int cont = 0;
char str[32];

short check_bto(int bto) {
	if (!input(bto)) {
		delay_ms(debounce);
		return !input(bto);
	}
	return FALSE;
}

int main(void) {

	delay_ms(300);

	while (TRUE) {
		a = check_bto(bto_sobe);
		b = check_bto(bto_desce);
		c = check_bto(bto_maual);
		if (a && ctrl) {
			ctrl = FALSE;
			strcpy(str, "Pressionado Bto\nSobe");
		} else if (b && ctrl) {
			ctrl = FALSE;
			strcpy(str, "Pressionado Bto\nDesce");
		} else if (c && ctrl) {
			ctrl = FALSE;
			strcpy(str, "Pressionado Bto\nManual");
		} else if (!(a || b || c) && !ctrl) {
			ctrl = TRUE;
			strcpy(str, "Botoes Soltos\n");
		}
		printf("\f%s %u", str, cont++);
		delay_ms(500);
	}

	return 0;
}
