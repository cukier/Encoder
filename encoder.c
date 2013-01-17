#include <18F452.h>
#device high_ints = true

#fuses	H4,NOOSCSEN,NOPUT,NOBROWNOUT,NOWDT,NOSTVREN,NOLVP
#fuses	NODEBUG,NOPROTECT,NOCPB,NOCPD,NOWRT,NOWRTC,NOWRTB
#fuses	NOWRTD,NOEBTR,NOEBTRB

#use delay(clock=32MHz, crystal=8MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use i2c(master, scl=pin_c3, sda=pin_c4, fast, force_hw)

#define canal_b pin_b1

static signed long pulsos, resol, pulsosAux;
static short print = 1;
static float angulo;

#INT_EXT
void ext_isr() {
	!input_state(canal_b) ? pulsos++ : pulsos--;
	print = 1;
}

#INT_EXT2 HIGH
void ext2_isr() {
	pulsosAux = pulsos;
	pulsos = 0;
}

int main(void) {

	enable_interrupts(INT_EXT_L2H);
	enable_interrupts(INT_EXT2_H2L);
	enable_interrupts(global);

	resol = 1024;

	while (true) {
		if (print) {
			print = 0;
			printf("%Ld %Ld\n%f", pulsos, pulsosAux,
					(float) 360 * pulsos / resol);
		}
	}

	return 0;
}
