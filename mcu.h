/*
 * mcu.h
 *
 *  Created on: 19/10/2011
 *      Author: cuki
 */

#ifndef MCU_H_
#define MCU_H_

#FUSES NOWDT
#FUSES WDT128
#FUSES H4
//#FUSES HS
#FUSES NOBROWNOUT
#FUSES NOSTVREN
#FUSES NOLVP

//#use delay(clock=8MHz)
#use delay(oscillator=8Mhz, clock=32Mhz)

#define I2C_SCL PIN_C3
#define I2C_SDA PIN_C4
#use i2c(Master,Fast=400000,sda=I2C_SDA,scl=I2C_SCL,force_hw)

#endif /* MCU_H_ */
