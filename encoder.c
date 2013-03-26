#include <18F45K20.h>

#fuses H4,NOWDT,NOPROTECT,NOLVP
#use delay(crystal=15MHz, clock=60MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use spi(MASTER, DI=PIN_C4, DO=PIN_C5, CLK=PIN_C3, MODE=0,  BAUD=1000000, BITS=16, DATA_HOLD=1)

#define SLAVE_SELECT PIN_A5
#include "as5040.h"

static long leitura;
static int zero;
//static long periodo, aux;

//#INT_CCP1
//void isr_ccp1(void) {
//	clear_interrupt(INT_CCP1);
//	periodo = CCP_1 - aux;
//	aux = CCP_1;
//	CCP_1 = 0;
//}

void main(void) {
	delay_ms(100);
//	output_low(SLAVE_SELECT);
//	setup_ccp1(CCP_CAPTURE_RE);
//	setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
//	enable_interrupts(INT_CCP1);
//	enable_interrupts(GLOBAL);
	zero = 0;
//	clear_bus();
//	delay_ms(100);
	setup_encoder(clockwise | _7_bit_resolution | step_direction_mode, zero);
//	clear_bus();
//	printf("\fProg: 7 bits zero %d", zero);
//	delay_ms(1000);
	while (TRUE) {
		output_low(SLAVE_SELECT);
		leitura = spi_xfer(0);
		output_high(SLAVE_SELECT);
		printf("\f%Lu  -  %d", leitura >> 6, (int) (leitura & 0x0006) >> 1);
//		printf("\nPer: %Lu", periodo);
		delay_ms(500);
//		delay_us(2);
//		delay_cycles(8);
//		output_toggle(PIN_C7);
	}
}
