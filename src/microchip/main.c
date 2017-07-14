/*
 * blink.c
 *
 *  Created on: 04/11/2014
 *      Author: cuki
 */

#include <18F45K20.h>
#include <stdbool.h>
#include <stdint.h>

#fuses H4

#use delay(clock=64MHz)
#use rtos(timer=0,minor_cycle=100ms)
// function declarations
#task(rate=1000ms,max=100ms)
void The_first_rtos_task();
#task(rate=500ms,max=100ms)
void The_second_rtos_task();

void The_first_rtos_task() {
	output_toggle(PIN_D0);
}

void The_second_rtos_task() {
	output_toggle(PIN_D1);
}

int main(void) {

	rtos_run();

	return 0;
}
