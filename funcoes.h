void parar() {
	output_low(pin_subir);
	output_low(pin_descer);
}

void subir() {
	output_low(pin_descer);
	delay_ms(10);
	output_high(pin_subir);
}

void descer() {
	output_low(pin_subir);
	delay_ms(10);
	output_high(pin_descer);
}

int trata_bto(int cmd) {

	short a = !input(bto_subir);
	short b = !input(bto_descer);
	int ret = cmd;

	if (a ^ b) {
		delay_ms(debounce);
		if (a && ctrl_bto) {
			ret = cmd_subir;
			ctrl_bto = FALSE;
		} else if (b && ctrl_bto) {
			ret = cmd_descer;
			ctrl_bto = FALSE;
		}
	} else if (!ctrl_bto) {
		ctrl_bto = TRUE;
		ret = cmd_parar;
	}

	return ret;
}

int trata_cmd(int cmd) {

	int ret = cmd;

	switch (cmd) {
	case cmd_subir:
		subir();
		ret = cmd_subir;
		break;
	case cmd_descer:
		descer();
		ret = cmd_descer;
		break;
	case cmd_parar:
		parar();
		set_timer0(0);
		set_timer1(0);
		ret = cmd_parar;
		break;
	default:
	}

	return ret;
}

void init_mcu() {
	clear_interrupt(INT_EXT);
	clear_interrupt(INT_EXT1);
	enable_interrupts(INT_EXT);
	enable_interrupts(INT_EXT1);
	enable_interrupts(GLOBAL);

	m_cmd = cmd_parar;
}
