/*
 * encoderSim.c
 *
 *  Created on: 26/03/2013
 *      Author: cuki
 */
#include<12C508A.h>

#fuses NOWDT, NOPROTECT, INTRC, NOMCLR
#use delay(clock=4MHz)

/////////////////////////////////////////saidas
#define canalA		PIN_B0
#define canalB		PIN_B1
#define canalZ		PIN_B2
/////////////////////////////////////////entradas
#define avanco		PIN_B3
#define reversao	PIN_B4
/////////////////////////////////////////tempos
#define voltas_nylon	11.5
#define tempo_elevacao	60

static float per_elevacao;
static int pre;
//static long long Xtal;
static long tmr0_reg;

int main(void) {
	per_elevacao = (float) voltas_nylon / tempo_elevacao;
//	Xtal = getenv("CLOCK");
	pre = 1;
	do {
		tmr0_reg = (float) 4000000 * per_elevacao / (4 * pre);
		if (tmr0_reg > 0xFFFF) {
			pre *= 2;
			if (pre == 256 && tmr0_reg > 0xFFFF) {
				tmr0_reg = 0xFFFF;
				pre = 256;
			}
		}
	} while (tmr0_reg > 0xFFFF);
}
