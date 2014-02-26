/*
 * botoes.c
 *
 *  Created on: 26/02/2014
 *      Author: cuki
 */

#define bto_sobe	PIN_D0
#define bto_desce	PIN_D1
#define bto_maual	PIN_A4
#define cmd_sobe	1
#define cmd_desce	2
#define cmd_manual	3
#define cmd_parar	4
#define debounce	100

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
	static short ctrl;

	a = check_bto(bto_sobe);
	b = check_bto(bto_desce);
	c = check_bto(bto_maual);

	if (a && ctrl) {
		ctrl = FALSE;
		ret = cmd_sobe;
	} else if (b && ctrl) {
		ctrl = FALSE;
		ret = cmd_desce;
	} else if (c && ctrl) {
		ctrl = FALSE;
		ret = cmd_manual;
	} else if (!(a | b | c) && !ctrl) {
		ctrl = TRUE;
		ret = cmd_parar;
	}

	return ret;
}
