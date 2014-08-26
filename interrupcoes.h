/*
 * interrupcoes.h
 *
 *  Created on: 26/08/2014
 *      Author: cuki
 */

#ifndef INTERRUPCOES_H_
#define INTERRUPCOES_H_

#INT_RB
void isr_rb() {
	clear_interrupt(INT_RB);
	short a = (port_b & 0x10) == 0x10;
	short b = (port_b & 0x20) == 0x20;

	if (a && !a_ok && !b) {
		a_ok = TRUE;
		direction = TRUE;
	} else if (a && !a_ok && b) {
		a_ok = TRUE;
		direction = FALSE;
	} else if (!a && !b) {
		a_ok = FALSE;
	}

	if (direction)
		pos++;
	else
		pos--;
}
