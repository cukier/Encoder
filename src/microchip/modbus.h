/*
 * modbus.h
 *
 *  Created on: 10 de jul de 2017
 *      Author: cuki
 */

#ifndef SRC_MODBUS_H_
#define SRC_MODBUS_H_

#include <stdint.h>
#include <stdbool.h>

#ifndef DELAY_REQUEST
#define DELAY_REQUEST	400
#endif

#ifndef TENTATIVAS
#define TENTATIVAS		3
#endif

void MODBUS_set_address(uint16_t addr);
uint16_t MODBUS_get_register(uint16_t register_address);
bool MODBUS_set_register(uint16_t register_address, uint16_t value);
bool MODBUS_set_registers(uint16_t register_address, uint16_t *data,
		uint16_t len);

#endif /* SRC_MODBUS_H_ */
