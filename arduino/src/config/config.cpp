#include "config.h"

#ifdef CONFIG_LEFT
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
    {10, 40, 170, 320, 2700}, // 10 shoulder
    {11, 18, 70, 320, 2700},  // 11 omoplate

    // Head
    {12, 0, 180, 320, 2700},  // 12 neck ?
    {13, 30, 100, 320, 2700}, // 13 rothead
    {26, 0, 70, 320, 2700},   // 26 jaw

    // Stom
    {27, 0, 180, 320, 2700}, // 27 topstom
    {28, 0, 180, 320, 2700}, // 28 midstom
};
#endif

#ifdef CONFIG_RIGHT
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