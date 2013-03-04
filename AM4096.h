/*
 * AM4096.h
 *
 *  Created on: 17/01/2013
 *      Author: cuki
 */

#ifndef AM4096_H_
#define AM4096_H_

#define AM4096ADDR 0
#define err 0xFFFF
#define REG51Addr  51

union {
	long valor;
	struct {
		unsigned Res : 3;
		unsigned UVW : 3;
		unsigned STH : 3;
		unsigned : 2;
		unsigned SSIcfg : 2;
		unsigned Dac : 2;
		unsigned Dact : 1;
	}bit;
}REG51;

short handshake(int addr) {
	short ack = 1;
	i2c_start();
	ack = i2c_write(addr);
	i2c_stop();
	delay_ms(10);
	return ack;
}

long write_i2c(int addr, int mem, int data) {
	if (handshake(addr))
		return err;
	else {
		i2c_start();
		i2c_write(addr);
		i2c_write(mem);
		i2c_start();
		i2c_write(addr + 1);
		i2c_write(data);
		i2c_stop();
		return 0;
	}
}

long read_i2c(int addr, int mem) {
	int msb = 0, lsb = 0;
	if (handshake(addr))
		return err;
	else {
		i2c_start();
		i2c_write(addr);
		i2c_write(mem);
		i2c_start();
		i2c_write(addr + 1);
		msb = i2c_read(1);
		lsb = i2c_read(1);
		i2c_stop();
		return make16(msb, lsb);
	}
}

#endif /* AM4096_H_ */
