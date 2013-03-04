#include <18F452.h>

#fuses	H4,NOOSCSEN,NOPUT,NOBROWNOUT,NOWDT,NOSTVREN
#fuses	NODEBUG,NOPROTECT,NOCPB,NOCPD,NOWRT,NOLVP
#fuses	NOWRTD,NOEBTR,NOEBTRB,NOWRTC,NOWRTB

#use delay(clock=32MHz, crystal=8MHz)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use i2c(master, scl=pin_c3, sda=pin_c4, fast=150000, force_hw)

#include"AM4096.h"

int main(void) {

	delay_ms(500);

	short ack = 1;

	while (true) {
		printf("\fEnviando 0");
		REG51.valor = read_i2c(AM4096ADDR, REG51Addr);
		if (REG51.valor != err)
			printf("\n%u", REG51.bit.Res);
		else
			printf("\nErro");
		delay_ms(3000);
	}
	return 0;
}

