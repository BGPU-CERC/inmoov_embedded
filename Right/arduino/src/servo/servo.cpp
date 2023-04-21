#include "servo.h"
#include "config.h"

uint32_t throttle = 0;
boolean ticking = false;

void servo_setup()
{
  for (int i = 0; i < SERVO_AMOUNT; i++)
  {
    servos[i].handle.setAutoDetach(false);
    servos[i].handle.setAccel(0);
  }
}

void servo_tick()
{
  // тик каждые 20 мс (как в библиотеке)
  if (millis() - throttle >= 20)
  {
    throttle += 20;

    if (!ticking)
    {
      return;
    }

    // двигаем все сервы. Такой вариант эффективнее отдельных тиков
    for (int i = 0; i < SERVO_AMOUNT; i++)
    {
      servos[i].handle.tickManual();
    }
  }
}

void servo_tick_stop()
{
  ticking = false;
}

void servo_target(int pin, int angle, int speed)
{
  servo *s = servo_get(pin);
  s->handle.setTargetDeg(angle);
  s->handle.setSpeed(speed);
  ticking = true;
}

void servo_attach(int pin, int angle)
{
  servo *s = servo_get(pin);
  s->handle.attach(pin, s->angle_min, s->angle_max, s->pwm_min, s->pwm_max, angle);
  s->handle.setTargetDeg(angle);
}

void servo_detach(int pin)
{
  servo *s = servo_get(pin);
  s->handle.detach();
}
