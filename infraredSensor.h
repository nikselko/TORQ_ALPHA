#pragma once

#include <Arduino.h>

class InfraredSensor
{
public:
	InfraredSensor(byte m_pin, byte m_led_pin);

	void display_led();
	int get_state();
  int read_pin();
	
	void init();

private:
	byte pin;
	byte led_pin;
	int state;
};
