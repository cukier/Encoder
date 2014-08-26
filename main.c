/*
 * main.c
 *
 *  Created on: 05/03/2014
 *      Author: cuki
 */

#include <18F45k20.h>

#FUSES HS
#use delay(crystal=16MHz, clock=64MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

#include "variaveis.h"
#include "interrupcoes.h"
#include "funcoes.h"

int main(void) {

	init_mcu();

	while (TRUE) {

		m_cmd = trata_cmd(trata_bto(m_cmd));

		if (posAux != pos) {
			posAux = pos;
			printf("Pos: %lu\n\r", pos);
			printf("Dir: %u\n\r", (int) direction);
			delay_ms(latencia);
		}

	}

	return 0;
}
