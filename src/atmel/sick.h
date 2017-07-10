/*
* sick.h
*
*  Created on: 27 de jan de 2016
*      Author: cuki
*/

#ifndef SICK_H_
#define SICK_H_

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>

#define EXIT_SUCESS		0
#define EXIT_ERROR		0xFF
#define DSF60_ADDRESS	0x40
#define BUFFER_MAX		0x80
#define ENCODER_EN

typedef enum electrical_interface_e
{
	DSF60_TTL, DSF60_HTL
}electrical_interface_t;

typedef enum pulse_width_electrical_e
{
	DSF60_90_DEGREES,
	DSF60_180_DEGREES_CHANNEL_B,
	DSF60_180_DEGREES_CHANNEL_A,
	DSF60_270_DEGREES
} pulse_width_electrical_t;

typedef enum pulse_width_mechanical_e
{
	DSF60_45_DEGREES_MECHANICAL, DSF60_270_DEGREES_MECHANICAL,
} pulse_width_mechanical_t;

typedef struct dsf60_str
{
	pulse_width_electrical_t pulse_width_electrical;
	char serial_number[10];
	char firmware_version[11];
	char firmware_date[9];
	char part_number[17];
	char encoder_type[8];
	char date_code[9];
	uint32_t position;
	uint32_t resolution;
	uint16_t pulse_width_mechanical;
} dsf60_t;

typedef enum dsf60_command_e
{
	DSF60_COMMAND_ENCODER_RESET = 0x53,
	DSF60_COMMAND_READ_SERIAL_NUMBER = 0x56,
	DSF60_COMMAND_READ_POSITION = 0x92,
	DSF60_COMMAND_SET_NUMBER_OF_LINES = 0x96,
	DSF60_COMMAND_SET_ELECTRICAL_INTERFACE,
	DSF60_COMMAND_SET_ZERO_PULSE_WIDTH_ELECTRICAL,
	DSF60_COMMAND_ZERO_SET,
	DSF60_COMMAND_READ_ENCODER_TYPE,
	DSF60_COMMAND_SET_ZERO_PULSE_WIDTH_MECHANICAL,
	DSF60_COMMAND_READ_ZERO_PULSE_WIDTH_ELECTRIAL_MECHANICAL,
	DSF60_COMMAND_READ_ELECTRICAL_INTERFACE
} DSF60_command_t;

dsf60_t *dsf60;

void DSF60_init_encoder(void);
bool DSF60_check(void);
bool DSF60_make_transaction(DSF60_command_t command, uint32_t arg);

#endif /* SICK_H_ */
