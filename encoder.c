#include <18F452.h>
#device adc=16
#fuses HS
//#use delay(clock=4Mhz)

//#include "lcd_8b.c"


#INT_EXT
void isr_INT_EXT() {
	if (!input(pin_b1)) {
		output_c(1);
	} else {
		output_c(2);
	}
}

void main(void) {

	output_c(0);

	clear_interrupt(int_ext);
	enable_interrupts(INT_EXT);
	enable_interrupts(global);

	while (true) {

	} //Infinite Loop
} //Main
