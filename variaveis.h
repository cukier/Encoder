/*
 * variaveis.h
 *
 *  Created on: 26/08/2014
 *      Author: cuki
 */

#define cmd_subir	1
#define cmd_descer	2
#define cmd_parar	3
#define pin_subir	PIN_D0
#define pin_descer	PIN_D1
#define bto_subir	PIN_D2
#define bto_descer	PIN_D3
#define debounce	100
#define	latencia	1000

#byte port_b=0xF81

short ctrl_bto;
short direction;
short a_ok;
short b_ok;

int m_cmd;
int last_b;

long pos;
long posAux;
