/*
 * funcoes.h
 *
 *  Created on: 28/03/2013
 *      Author: cuki
 */

#ifndef FUNCOES_H_
#define FUNCOES_H_

void parar(void) {
	output_high(saida_sobe);
	output_high(saida_desce);
}

void descer(void) {
	output_high(saida_sobe);
	delay_ms(50);
	output_low(saida_desce);
}

void subir(void) {
	output_high(saida_desce);
	delay_ms(50);
	output_low(saida_sobe);
}

#endif /* FUNCOES_H_ */
