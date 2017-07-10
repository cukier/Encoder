#ifndef MODBUS_H
#define MODBUS_H

#include "sys.h"

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
void MODBUS_set_register(uint16_t register_address, uint16_t value);


#endif