#include "config.h"

#define CONFIG_LEFT
// #define CONFIG_RIGHT

#ifdef CONFIG_LEFT
#include "config_left.cpp"
#endif

#ifdef CONFIG_RIGHT
#include "config_right.cpp"
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