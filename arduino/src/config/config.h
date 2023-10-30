#pragma once
#include "../servo/servo.h"
#include "../ultrasonic/ultrasonic.h"

// #define CONFIG_LEFT
#define CONFIG_RIGHT

#ifdef CONFIG_LEFT
#define SERVO_AMOUNT 17 // 16
#define ULTRASONIC_AMOUNT 2
#define MAX_SCAN_DISTANCE 400
#endif

#ifdef CONFIG_RIGHT
#define SERVO_AMOUNT 10
#endif

#define SERVO_RELAY 25

extern servo servos[];
extern ultrasonic utlrasonics[];

int servo_index(int pin);

servo *servo_get(int pin);
