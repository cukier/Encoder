/*
 * blink.c
 *
 *  Created on: 04/11/2014
 *      Author: cuki
 */

#include <18F25K22.h>
#device ADC=10
#fuses NOWDT, INTRC, NOPLLEN, NOFCMEN, NOIESO, PUT
#fuses BROWNOUT, BORV29, STVREN, NOLVP, NODEBUG, NOCPB
#fuses NOCPD, NOXINST, NOPBADEN, NOPROTECT
#use delay(internal=16MHz)
#use rtos(timer=1,minor_cycle=10ms)

#task(rate=400ms,max=10ms)
void The_first_rtos_task();
#task(rate=300ms,max=10ms)
void The_second_rtos_task();

#include <stdbool.h>
#include <stdint.h>

#include "controle.c"

int8_t sem;
uint16_t pos;

void The_first_rtos_task() {
	rtos_wait(sem);
	check_plc(pos);
	rtos_yield();
	rtos_signal(sem);
}

void The_second_rtos_task() {
	rtos_wait(sem);
	pos = check_encoder();
	rtos_yield();
	rtos_signal(sem);
}

int main(void) {

	pos = 0;
	sem = 1;
	init();

	rtos_run();
//	while (true) {
//		check_plc(pos);
//		pos = check_encoder();
//	}

	return 0;
}
