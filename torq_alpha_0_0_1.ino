/*#include "hardwareInterface.h"*/
#include "driveShaft.h"
#include "sensorPanel.h"

DriveShaft test_shaft(6, 5, 4, 3); // MOTOR(6, 5, 4) : SERVO(3)

SensorPanel test_panel(
        13, A3, //Ultrasonic_LEFT
        8, 12, //Ultrasonic_RIGHT
        A1, 0, //Infrared_LEFT
        A5, 0, //Infrared_RIGHT
        A4, 0 //INfrared_FRONT
        );

const int threshold = 5;

int last_condition = FRONT;
/*
const int treshold = 15;

const byte left_ultrasonic_echo_pin = 13;
const byte left_ultrasonic_trigger_pin = A3;
const byte right_ultrasonic_echo_pin = 8;
const byte right_ultrasonic_trigger_pin = 12;
const byte left_infrared_pin = A1;
const byte left_infrared_led_pin = 0;
const byte right_infrared_pin = A5;
const byte right_infrared_led_pin = 0;
const byte front_infrared_pin = 0;
const byte front_infrared_led_pin = A4;
const byte motor_enable_pin = 6;
const byte motor_input_a_pin =5;
const byte motor_input_b_pin = 4;
const byte servo_pin = 3;

HardwareInterface hardwareInterface(
    left_ultrasonic_echo_pin, left_ultrasonic_trigger_pin,
    right_ultrasonic_echo_pin, right_ultrasonic_trigger_pin,
    left_infrared_pin, right_infrared_led_pin,
    right_infrared_pin, right_infrared_led_pin,
    front_infrared_pin, front_infrared_led_pin,
    motor_enable_pin, motor_input_a_pin,
    motor_input_b_pin, servo_pin
);


bool avoid_obstacle_handler()
{
    if (hardwareInterface.sensorPanel->outputSequence[0] < hardwareInterface.sensorPanel->outputSequence[1])
    {
        hardwareInterface.driveShaft->turnLeft();
        delay(2000);
        hardwareInterface.driveShaft->turnRight();
        delay(2000);
        return true;
    }
    else
    {
        hardwareInterface.driveShaft->turnRight();
        delay(2000);
        hardwareInterface.driveShaft->turnLeft();
        delay(2000);
        return true;
    }

    return false;
}
*/

void setup()
{ 
  test_shaft.p_mainMotor.init(); // debuged 25-5
  test_shaft.p_servoMotor.init(); // debuged 25-5
  
  test_panel.Ultrasonic_LEFT.init();
  test_panel.Ultrasonic_RIGHT.init();

  test_panel.Infrared_LEFT.init();
  test_panel.Infrared_RIGHT.init();
  test_panel.Infrared_FRONT.init();
  
  Serial.begin(9600);
}

void loop()
{
  if (test_panel.Ultrasonic_LEFT.get_distance() <= threshold && test_panel.Ultrasonic_RIGHT.get_distance() <= threshold) // Ultrasonic distance check if its less or equals than we should avoid obstacle
  {
    test_shaft.stopMovement(); //Implement avoid obstacle instead of stopping :P
  }
  else
  {
    if (last_condition == FRONT)
    {
      if (test_panel.Infrared_FRONT.read_pin() == HIGH)
      {
        test_shaft.moveForward();
      }
      else
      {
        if(test_panel.Infrared_LEFT.read_pin() == HIGH)
        {
          last_condition = LEFT;
          test_shaft.turnLeft();
        }
        else if(test_panel.Infrared_RIGHT.read_pin() == HIGH)
        {
          last_condition = RIGHT;
          test_shaft.turnRight();
        }
      }
    }
    else
    {
      if (last_condition == LEFT) // exeption for long left turning condition
      {
        test_shaft.turnLeft();
        
        if(test_panel.Infrared_RIGHT.read_pin() == HIGH)
          last_condition = FRONT;
      }
      else if(last_condition == RIGHT) // exeption for long right turning condition
      {
        test_shaft.turnRight();
        
        if(test_panel.Infrared_LEFT.read_pin() == HIGH)
          last_condition = FRONT;
      }
    }
  }
}
