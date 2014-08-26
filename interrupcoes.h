/*
 * interrupcoes.h
 *
 *  Created on: 26/08/2014
 *      Author: cuki
 */

#ifndef INTERRUPCOES_H_
#define INTERRUPCOES_H_

#INT_EXT
void ext_isr() {
	clear_interrupt(INT_EXT);
	pos++;
}

#INT_EXT1
void ext1_isr() {
	clear_interrupt(INT_EXT1);
	pos++;
}

#endif /* INTERRUPCOES_H_ */
