#pragma once

#include "mainMotor.h"
#include "servoMotor.h"
#include <Arduino.h>


class DriveShaft
{
public:
    DriveShaft(byte m_epin, byte m_inapin, byte m_inbpin, byte m_s_pin);

    MainMotor p_mainMotor;          // (byte m_enable_pin, byte m_input_a, byte m_input_b)
    ServoMotor p_servoMotor;        // (byte pin)

    void moveForward();
    void turnLeft();
    void turnRight();
    void powerStart();
    void stopMovement();
};
