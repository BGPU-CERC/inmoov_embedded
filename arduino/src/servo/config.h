#pragma once
#include "servo.h"

#define servoRelay 25

extern servo servos[];

int servo_index(int pin);

servo *servo_get(int pin);
