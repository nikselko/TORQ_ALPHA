#pragma once

#include <Servo.h>
#include <Arduino.h>

class ServoMotor
{
public:
	ServoMotor(byte m_pin);

	void rotate_left(int r_angle); 
	void rotate_right(int r_angle); 
	void reset();
  Servo servo;

	void init();
	byte pin;
	int pos;
};
