#pragma once
#include "../servo/servo.h"

#define CONFIG_LEFT
// #define CONFIG_RIGHT

#ifdef CONFIG_LEFT
#define SERVO_AMOUNT 15
#endif

#ifdef CONFIG_RIGHT
#define SERVO_AMOUNT 10
#endif

#define SERVO_RELAY 25

extern servo servos[];

int servo_index(int pin);

servo *servo_get(int pin);
