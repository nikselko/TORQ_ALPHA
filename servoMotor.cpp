#include "servoMotor.h"

ServoMotor::ServoMotor(byte m_pin)
{
    pin = m_pin;
    pos = 100;
}

void ServoMotor::init()
{
    servo.attach(pin);
}

void ServoMotor::rotate_left(int r_angle)
{
   servo.write(pos + r_angle);
}

void ServoMotor::rotate_right(int r_angle)
{
    servo.write(pos - r_angle);
}

void ServoMotor::reset()
{
    pos = 120;
    servo.write(pos);
}
