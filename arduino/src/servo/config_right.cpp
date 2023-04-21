#include "config.h"

#define SERVO_AMOUNT 10

servo servos[SERVO_AMOUNT] = {
    // Hand
    {2, 0, 50, 500, 2500},  // 2 thumb
    {3, 0, 160, 500, 2500}, // 3 index
    {4, 0, 160, 500, 2500}, // 4 majeure
    {5, 0, 160, 500, 2500}, // 5 ringFinger
    {6, 0, 160, 500, 2500}, // 6 pinky
    {7, 0, 180, 500, 2500}, // 7 wrist

    // Arm
    {8, 20, 95, 544, 2400},   // 8 bicep
    {9, 40, 160, 320, 2700},  // 9 rotate
    {10, 30, 170, 320, 2700}, // 10 shoulder
    {11, 18, 170, 320, 2700}, // 11 omoplate
};
