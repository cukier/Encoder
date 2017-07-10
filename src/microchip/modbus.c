/*
 * modbus.c
 *
 *  Created on: 7 de jul de 2017
 *      Author: cuki
 */

#include "modbus.h"
#include "uart.h"

static volatile uint16_t slv_addr;

void MODBUS_set_address(uint16_t addr) {
	slv_addr = addr;

	return;
}

uint16_t make_16(uint8_t var_h, uint8_t var_l) {
	uint16_t ret;

	ret = 0;
	ret = var_h << 8;
	ret |= var_l;

	return ret;
}

uint8_t l_byte(uint16_t m_word) {
	uint8_t ret;

	ret = 0;
	ret = m_word & 0xFF;

	return ret;
}

uint8_t h_byte(uint16_t m_word) {
	uint8_t ret;

	ret = 0;
	ret = ((m_word & 0xFF00) >> 8) & 0xFF;

	return ret;
}

uint16_t ModRTU_CRC(uint8_t *buf, uint16_t len) {
	uint16_t crc = 0xFFFF;

	for (int pos = 0; pos < len; pos++) {
		crc ^= (uint16_t) buf[pos];

		for (int i = 8; i != 0; i--) {
			if ((crc & 0x0001) != 0) {
				crc >>= 1;
				crc ^= 0xA001;
			} else {
				crc >>= 1;
			}
		}
	}

	return crc;
}

void make_read_request(uint16_t s_addr, uint16_t nb, uint8_t *request) {
	uint16_t crc;

	crc = 0;

	request[0] = slv_addr;
	request[1] = 0x03;
	request[2] = h_byte(s_addr);
	request[3] = l_byte(s_addr);
	request[4] = h_byte(nb);
	request[5] = l_byte(nb);

	crc = ModRTU_CRC(request, 6);

	request[6] = l_byte(crc);
	request[7] = h_byte(crc);

	return;
}

void make_write_request(uint16_t s_addr, uint16_t value, uint8_t *request) {
	uint16_t crc;

	crc = 0;

	request[0] = slv_addr;
	request[1] = 0x06;
	request[2] = h_byte(s_addr);
	request[3] = l_byte(s_addr);
	request[4] = h_byte(value);
	request[5] = l_byte(value);

	crc = ModRTU_CRC(request, 6);

	request[6] = l_byte(crc);
	request[7] = h_byte(crc);

	return;
}

void make_multile_write_request(uint16_t s_addr, uint16_t *data, uint16_t size,
		uint8_t *request) {
	uint16_t crc, cont;

	crc = 0;

	request[0] = slv_addr;
	request[1] = 0x10;
	request[2] = h_byte(s_addr);
	request[3] = l_byte(s_addr);
	request[4] = h_byte(size);
	request[5] = l_byte(size);
	request[6] = (uint8_t) ((uint8_t) size * 2);

	for (cont = 0; cont < size; ++cont) {
		request[7 + 2 * cont] = h_byte(data[cont]);
		request[7 + (2 * cont + 1)] = l_byte(data[cont]);
	}

	crc = ModRTU_CRC(request, (uint16_t) (7 + request[6]));

	request[request[6] + 7] = l_byte(crc);
	request[request[6] + 8] = h_byte(crc);

	return;
}

uint16_t MODBUS_get_register(uint16_t register_address) {
	uint16_t ret = 0, n = 0;
	uint8_t request[8];
	uint8_t response[7];
	uint8_t tries;

	tries = TENTATIVAS;

	do {
		make_read_request(register_address, 1, request);
		uart1_flush();
		uart1_send(request, 8);
		delay_ms(DELAY_REQUEST);
		n = uart1_rx_size();

		if (n == 7) {
			tries = 0;
		} else {
			uart1_flush();
			delay_ms(1000);
		}
	} while (tries--);

	uart1_get(response, 7);
	ret = make_16(response[3], response[4]);

	return ret;
}

bool MODBUS_set_register(uint16_t register_address, uint16_t value) {
	uint8_t request[8];
	uint16_t n;

	n = 0;
	make_write_request(register_address, value, request);

#ifdef MODUBS_USE_SL1
	uart1_flush();
	uart1_send(request, 8);
	delay_ms(DELAY_REQUEST);
	n = uart1_rx_size();
	uart1_flush();
#endif

#ifdef MODUBS_USE_SL2
	uart2_flush();
	uart2_send(request, 8);
	delay_ms(DELAY_REQUEST);
	n = uart2_rx_size();
	uart2_flush();
#endif

	return (n == 8);
}

bool MODBUS_set_registers(uint16_t register_address, uint16_t *data,
		uint16_t len) {
	uint16_t m_size, n;
	uint8_t *request;

	n = 0;
	m_size = 9 + (len * 2);
	request = (uint8_t) malloc(m_size * sizeof(uint8_t));

	make_multile_write_request(register_address, data, len, request);

#ifdef MODUBS_USE_SL1
	uart1_flush();
	uart1_send(request, m_size);
	free(request);
	delay_ms(DELAY_REQUEST);
	n = uart1_rx_size();
	uart1_flush();
#endif

#ifdef MODUBS_USE_SL2
	uart2_flush();
	uart2_send(request, m_size);
	free(request);
	delay_ms(DELAY_REQUEST);
	n = uart2_rx_size();
	uart2_flush();
#endif

	return (n == 8);
}
