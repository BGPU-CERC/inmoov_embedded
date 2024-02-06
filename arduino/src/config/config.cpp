#include "config.h"

#ifdef CONFIG_LEFT
servo servos[SERVO_AMOUNT] = {
    // Hand
    {2, 0, 90, 500, 2500},  // 2 thumb
    {3, 0, 160, 500, 2500}, // 3 index
    {4, 0, 160, 500, 2500}, // 4 majeure
    {5, 0, 160, 500, 2500}, // 5 ringFinger
    {6, 0, 160, 500, 2500}, // 6 pinky
    {7, 0, 180, 570, 2400}, // 7 wrist

    // Arm
    {8, 20, 95, 544, 2400},   // 8 bicep
    {9, 40, 160, 320, 2700},  // 9 rotate
    {10, 40, 170, 320, 2700}, // 10 shoulder
    {11, 18, 65, 320, 2700},  // 11 omoplate

    // Head
    {12, 65, 115, 320, 2700}, // 12 jaw
    {13, 50, 140, 320, 2700}, // 13 neck
    {23, 50, 130, 320, 2500}, // 23 rollneck l
    {29, 50, 130, 320, 2500}, // 29 rollneck r
    {26, 40, 130, 320, 2700}, // 26 rothead

    // Stom
    {27, 53, 93, 320, 2700},  // 27 topstom
    {28, 60, 120, 320, 2700}, // 28 midstom
};

ultrasonic utlrasonics[ULTRASONIC_AMOUNT] = {
    {new NewPing(32, 33, MAX_SCAN_DISTANCE)},
    {new NewPing(34, 35, MAX_SCAN_DISTANCE)},
};

#endif

#ifdef CONFIG_RIGHT
servo servos[SERVO_AMOUNT] = {
    // Hand
    {2, 0, 90, 500, 2500},  // 2 thumb
    {3, 0, 160, 500, 2500}, // 3 index
    {4, 0, 160, 500, 2500}, // 4 majeure
    {5, 0, 160, 500, 2500}, // 5 ringFinger
    {6, 0, 160, 500, 2500}, // 6 pinky
    {7, 0, 180, 570, 2400}, // 7 wrist

    // Arm
    {8, 20, 95, 544, 2400},   // 8 bicep
    {9, 40, 160, 320, 2700},  // 9 rotate
    {10, 30, 170, 320, 2700}, // 10 shoulder
    {11, 18, 65, 320, 2700},  // 11 omoplate

    // Eyes
    {12, 40, 120, 544, 2400}, // 12 eyeX
    {13, 70, 110, 544, 2400}, // 13 eyeY
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