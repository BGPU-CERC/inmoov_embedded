#include "config.h"

#ifdef CONFIG_LEFT
servo servos[SERVO_AMOUNT] = {
    // Hand
    {2, 0, 90, 500, 2500},  // thumb
    {3, 0, 160, 500, 2500}, // index
    {4, 0, 160, 500, 2500}, // majeure
    {5, 0, 160, 500, 2500}, // ringFinger
    {6, 0, 160, 500, 2500}, // pinky
    {7, 0, 180, 570, 2400}, // wrist

    // Arm
    {8, 20, 95, 544, 2400},   // bicep
    {9, 40, 160, 320, 2700},  // rotate
    {10, 40, 170, 320, 2700}, // shoulder
    {11, 18, 65, 320, 2700},  // omoplate

    // Head
    {12, 60, 120, 320, 2700}, // jaw
    {13, 50, 140, 320, 2700}, // neck
    {23, 50, 130, 320, 2500}, // rollneck l
    {29, 50, 130, 320, 2500}, // rollneck r
    {26, 60, 130, 320, 2700}, // rothead

    // Stom
    {27, 53, 93, 320, 2700},  // topstom
    {28, 60, 120, 320, 2700}, // midstom
};

ultrasonic utlrasonics[ULTRASONIC_AMOUNT] = {
    {new NewPing(32, 33, MAX_SCAN_DISTANCE)},
    {new NewPing(34, 35, MAX_SCAN_DISTANCE)},
};

#endif

#ifdef CONFIG_RIGHT
servo servos[SERVO_AMOUNT] = {
    // Hand
    {2, 0, 90, 500, 2500},  // thumb
    {3, 0, 160, 500, 2500}, // index
    {4, 0, 160, 500, 2500}, // majeure
    {5, 0, 160, 500, 2500}, // ringFinger
    {6, 0, 160, 500, 2500}, // pinky
    {7, 0, 180, 570, 2400}, // wrist

    // Arm
    {8, 20, 95, 544, 2400},   // bicep
    {9, 40, 160, 320, 2700},  // rotate
    {10, 30, 170, 320, 2700}, // shoulder
    {11, 18, 65, 320, 2700},  // omoplate

    // Eyes
    {22, 90, 60, 120, 2500}, // eye x
    {24, 90, 60, 120, 2500}, // eye y
};
#endif

int servo_index(int pin)
{
  for (int i = 0; i < SERVO_AMOUNT; i++)
  {
    if (servos[i].pin == pin)
    {
      return i;
    }
  }
}

servo *servo_get(int pin)
{
  return &servos[servo_index(pin)];
}