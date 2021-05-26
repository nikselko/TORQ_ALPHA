#pragma once

#include <Arduino.h>

class UltrasonicSensor
{
public:
	UltrasonicSensor(byte m_echo_pin, byte m_trig_pin);
	int get_distance();
	

	void init();

private:
	byte echo_pin;
	byte trig_pin;

	long duration;
	int  distance;
};
