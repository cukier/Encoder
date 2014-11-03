/*
 * master.c
 *
 *  Created on: 18/08/2014
 *      Author: cuki
 */

#include<18F252.h>
#zero_ram

#include<stdlib.h>

#fuses H4
#use delay(clock=32MHz, crystal=8MHz)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)

#define canal_z		PIN_B3
#define canal_a		PIN_B4
#define canal_b		PIN_B5
#define change_a	4
#define change_b	5
#define buff		10

short ctrl_fdc;

int changes, last_b, cont, i;

int ocorrencias[buff];

signed long m_pos, a_pos;
signed long positions[buff];

#INT_RB
void isr_rb() {
	clear_interrupt(INT_RB);
	delay_us(1);

	changes = last_b ^ input_b();
	last_b = input_b();

	if (bit_test(changes, change_a)) {
		if (input(canal_a) != input(canal_b))
			m_pos++;
		else
			m_pos--;
	} else if (bit_test(changes, change_b)) {
		if (input(canal_a) == input(canal_b))
			m_pos++;
		else
			m_pos--;
	}
}

int main(void) {

	last_b = input_b();

	clear_interrupt(INT_RB);
	enable_interrupts(INT_RB);

	enable_interrupts(GLOBAL);

	printf("\fTeste Encoder");
	delay_ms(1000);

	while (TRUE) {

		if (input(canal_z) && !ctrl_fdc) {
			ctrl_fdc = TRUE;
			for (i = 0; i < buff; ++i) {
				if (positions[i] == 0) {
					positions[i] = m_pos;
					ocorrencias[i]++;
					cont = i;
					break;
				} else if (positions[i] == m_pos) {
					ocorrencias[i]++;
					cont = i;
					break;
				}
			}
			m_pos = 0;
			delay_ms(10);
		} else if (ctrl_fdc)
			ctrl_fdc = FALSE;

		if (m_pos != a_pos) {
			a_pos = m_pos;
			printf("\fPos: %4ld\nUlt: %4ld %2d", m_pos, positions[cont],
					ocorrencias[cont]);
			delay_ms(300);
		}

	} //infinite loop
	return 0;
}

