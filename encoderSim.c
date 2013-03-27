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

static long pulsos;
static long tm0_config = 159; // resol. enc = 1024, 11.5 voltas nylon, 60 segundos operacao

int main(void) {
	output_low(PIN_B0);
	SETUP_TIMER_0(T0_INTERNAL | T0_DIV_8);
	while (TRUE) {
		if (!input(avanco) || !input(reversao)) {
			set_timer0(0);
			while (get_timer0() < tm0_config)
				;
			pulsos++;
			if (!(pulsos % 4))
				output_high(canalA);
			else if (!(pulsos % 2))
				output_high(canalB);
			else if (!(pulsos % 3))
				output_low(canalB);
			else
				output_low(canalA);
		}
	}
}
