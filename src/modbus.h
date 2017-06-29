#ifndef MODBUS_H
#define MODBUS_H

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>

void make_read_request(uint8_t addr, uint16_t s_addr, uint16_t nb, uint8_t *request);
void make_write_request(uint8_t addr, uint16_t s_addr, uint16_t nb, uint8_t *request);

#endif