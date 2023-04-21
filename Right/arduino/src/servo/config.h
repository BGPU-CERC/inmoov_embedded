#pragma once
#include "servo.h"

#define SERVO_AMOUNT 10

extern servo servos[SERVO_AMOUNT];

int servo_index(int pin);

servo *servo_get(int pin);
