#pragma once
#include "ServoSmooth.h"

struct servo
{
  int pin;
  int angle_min;
  int angle_max;
  int pwm_min;
  int pwm_max;
  ServoSmooth handle;
};

void servo_setup();

void servo_tick();

void servo_tick_stop();

void servo_power(bool mode);

void servo_target(int pin, int angle, int speed);

void servo_attach(int pin, int angle, int speed);

void servo_detach(int pin);
