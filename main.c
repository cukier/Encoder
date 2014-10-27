/*
 * master.c
 *
 *  Created on: 18/08/2014
 *      Author: cuki
 */

#include<18F25K22.h>
#zero_ram

#include<stdlib.h>

#fuses PLLEN,HSH
#use delay(clock=60MHz, crystal=15MHz)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)

#define canal_z		PIN_B3
#define canal_a		PIN_B4
#define canal_b		PIN_B5
#define change_a	4
#define change_b	5

short dir;
int changes, last_b;
signed long m_pos, a_pos;

#INT_EXT2
void isr_ext2() {
	clear_interrupt(INT_EXT2);
	m_pos = 0;
}

#INT_RB
void isr_rb() {
	clear_interrupt(INT_RB);
	delay_us(1);

	changes = last_b ^ input_b();
	last_b = input_b();

	if (bit_test(changes, change_a))
		dir = (input(canal_a) != input(canal_b));
	else if (bit_test(changes, change_b))
		dir = (input(canal_a) == input(canal_b));

	if (dir)
		m_pos++;
	else
		m_pos--;
}

int main(void) {

	setup_timer_0(T0_INTERNAL | T0_DIV_64);

	clear_interrupt(INT_RB);
	enable_interrupts(INT_RB);

	clear_interrupt(INT_EXT2);
	enable_interrupts(INT_EXT2_H2L);

	enable_interrupts(GLOBAL);

	last_b = input_b();

	printf("Teste Encoder\n\r");
	delay_ms(1000);

	while (TRUE) {

		if (m_pos != a_pos) {
			a_pos = m_pos;
			printf("Pos: %4ld - Ang: %3.2f\n\r", m_pos,
					(float) m_pos * 360 / 4092);
			delay_ms(300);
		}

	}
	return 0;
}

