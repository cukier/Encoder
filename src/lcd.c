
#include "lcd.h"

#include <util/delay.h>
#include <stdio.h>

char lcd_buffer[17];

void lcd_rs_set(void) {
	RS_PORT |= _BV(RS);
	
	return;
}

void lcd_rs_reset(void) {
	RS_PORT &= ~_BV(RS);
	
	return;
}

void lcd_en_set(void) {
	EN_PORT |= _BV(EN);
	
	return;
}

void lcd_en_reset(void) {
	EN_PORT &= ~_BV(EN);
	
	return;
}

void lcd_output_bit(uint8_t bit, bool value) {
	if (value) {
		LCD_PORT |= _BV(bit);
		} else {
		LCD_PORT &= ~_BV(bit);
	}
	
	return;
}

bool lcd_bit_test(uint8_t value, uint8_t index) {
	uint8_t mask = 1;
	
	mask <<= index;
	
	return (value & mask) == mask;
}

void lcd_cmd(uint8_t cmd) {
	lcd_output_bit(D4, lcd_bit_test(cmd, 0));
	lcd_output_bit(D5, lcd_bit_test(cmd, 1));
	lcd_output_bit(D6, lcd_bit_test(cmd, 2));
	lcd_output_bit(D7, lcd_bit_test(cmd, 3));
	lcd_en_set();
	_delay_us(10);
	lcd_en_reset();
	
	return;
}

void lcd_envia_byte(bool endereco, int dado) {
	lcd_rs_reset();
	
	if (endereco)
	lcd_rs_set();
	else
	lcd_rs_reset();
	
	_delay_us(100);
	lcd_en_reset();
	lcd_cmd(dado >> 4);
	lcd_cmd(dado & 0x0f);
	_delay_ms(1);
	
	return;
}

void lcd_pos_xy(uint8_t x, uint8_t y) {
	uint8_t endereco;
	
	if (y != 1)
	endereco = 0xc0;
	else
	endereco = 0x80;
	
	endereco += x - 1;
	lcd_envia_byte(0, endereco);
	
	return;
}

void lcd_puts(char *str) {
	while (*str) {
		lcd_putc(*str++);
	}
	
	return;
}

void lcd_putc(char c) {
	switch (c) {
		case '\f':
		lcd_envia_byte(0, 1);     // 0,1
		_delay_ms(2);
		break;
		case '\n':
		case '\r':
		lcd_pos_xy(1, 2);      // 1,2  COLUNA,LINHA
		break;
		case '\b':
		lcd_envia_byte(0, 0x10);
		break;
		default:
		lcd_envia_byte(1, c);
		break;
	}
	
	return;
}



void lcd_printf(char *format, ...) {
	va_list args;

	va_start(args, format);
	vsnprintf(lcd_buffer, 17, format, args);
	va_end(args);

	lcd_puts(lcd_buffer);
	
	return;
}

void lcd_init() {
	int conta;
	
	RS_DDR |= _BV(RS);
	EN_DDR |= _BV(EN);
	LCD_DDR |= _BV(D4);
	LCD_DDR |= _BV(D5);
	LCD_DDR |= _BV(D6);
	LCD_DDR |= _BV(D7);

	lcd_rs_reset();
	lcd_en_reset();
	lcd_output_bit(D4, false);
	lcd_output_bit(D5, false);
	lcd_output_bit(D6, false);
	lcd_output_bit(D7, false);

	_delay_ms(15);

	for (conta = 1; conta <= 3; conta++) {
		lcd_cmd(0x03);
		_delay_ms(5);
	}
	
	lcd_cmd(0x02);           //escreve comando para interface de 4 vias de dados
	lcd_envia_byte(0, 0x28); //escreve comando informando lcd de 2 linhas (5x7) em 4bits
	lcd_envia_byte(0, 0x0c); //escreve comando para limpar todo o display
	lcd_envia_byte(0, 0x01); //escreve comando para ligar o display **com cursor piscante
	lcd_envia_byte(0, 0x06); //escreve comando para incrementar automaticamente á direita
	_delay_ms(5);
	
	return;
}