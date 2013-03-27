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
#define canalZ		PIN_B5
/////////////////////////////////////////entradas
#define avanco		PIN_B3
#define reversao	PIN_B4
/////////////////////////////////////////tempos
#define voltas_nylon	11.5
#define tempo_elevacao	60

static long pulsos;
static long tm0_config = 159; // resol. enc = 1024, 11.5 voltas nylon, 60 segundos operacao
enum tick_str {
	A, B, C, D
};
enum tick_str tempo;

int main(void) {
	output_low(PIN_B0);
	SETUP_TIMER_0(T0_INTERNAL | T0_DIV_8);
	while (TRUE) {
		if (!input(avanco) || !input(reversao)) {
			set_timer0(0);
			while (get_timer0() < tm0_config)
				;
			switch (tempo++) {
			case A:
				if (!input(avanco) && input(reversao)) {
					output_low(canalA);
					output_high(canalB);
					pulsos++;
					if (pulsos > 1024)
						pulsos = 0;
				} else if (!input(reversao) && input(avanco)) {
					output_high(canalA);
					output_high(canalB);
					pulsos--;
					if (!pulsos)
						pulsos = 1023;
				}
				break;
			case B:
				output_low(canalB);
				break;
			case C:
				if (!input(avanco) && input(reversao))
					output_high(canalA);
				else if (!input(reversao) && input(avanco))
					output_low(canalA);
				break;
			default:
			case D:
				output_high(canalB);
				tempo = A;
				break;
			}
		}
		if (!input_state(canalA) && !input_state(canalB)
				&& !input_state(canalZ) && pulsos == 1024)
			output_high(canalZ);
		else if (input_state(canalZ))
			output_low(canalZ);
	}
}
