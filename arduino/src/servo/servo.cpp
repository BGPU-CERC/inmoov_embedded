#include "../servo/ServoSmooth.h"

#define AMOUNT 15 // кол-во серво

ServoSmooth servo[AMOUNT];

int servoPins[AMOUNT] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 26, 27, 28},
    minAngle[AMOUNT] = {
        // Hand
        0, // 2 thumb
        0, // 3 index
        0, // 4 majeure
        0, // 5 ringFinger
        0, // 6 pinky
        0, // 7 wrist
        // Arm
        25,  // 8 bicep
        40,  // 9 rotate
        30,  // 10 shoulder
        120, // 11 omoplate
        // Head
        0,  // 12 neck ?
        30, // 13 rothead
        0,  // 26 jaw
        // Stom
        70, // 27 topstom
        140 // 28 midstom
},
    maxAngle[AMOUNT] = {
        50,  // 2
        160, // 3
        160, // 4
        160, // 5
        160, // 6 ? возможно нужно поменять DIR
        180, // 7
        140, // 8
        180, // 9
        170, // 10
        170, // 11
        180, // 12 ?
        100, // 13
        70,  // 26 ?
        110, // 27
        180, // 28
},

    minPWM[AMOUNT] = {
        500, // 2
        500, // 3
        500, // 4
        500, // 5
        500, // 6
        500, // 7
        544, // 8
        320, // 9
        320, // 10
        320, // 11
        320, // 12
        320, // 13
        320, // 26
        320, // 27
        320, // 28
},

    maxPWM[AMOUNT] = {
        2500, // 2
        2500, // 3
        2500, // 4
        2500, // 5
        2500, // 6
        2500, // 7
        2400, // 8
        2700, // 9
        2700, // 10
        2700, // 11
        2700, // 12
        2700, // 13
        2700, // 26
        2700, // 27
        2700, // 28
};

uint32_t servoTimer;
uint32_t turnTimer;

boolean flag,
    isMoving = false;

void servo_setup()
{
  for (int i = 0; i < AMOUNT; i++)
  {
    servo[i].setAutoDetach(false);
    servo[i].setAccel(0);
  }
}

void servo_tick()
{
  if (isMoving)
  {
    if (millis() - servoTimer >= 20)
    { // взводим таймер на 20 мс (как в библиотеке)
      servoTimer += 20;
      for (byte i = 0; i < AMOUNT; i++)
      {
        servo[i].tickManual(); // двигаем все сервы. Такой вариант эффективнее отдельных тиков
      }
    }
  }
}

int getIndex(int pin)
{
  for (int i = 0; i < AMOUNT; i++)
  {
    if (pin == servoPins[i])
      return i;
  }
}

int getMinPWM(int pin)
{
  for (int i = 0; i < AMOUNT; i++)
  {
    if (pin == servoPins[i])
      return minPWM[i];
  }
}

int getMaxPWM(int pin)
{
  for (int i = 0; i < AMOUNT; i++)
  {
    if (pin == servoPins[i])
      return maxPWM[i];
  }
}

int getMinAngle(int pin)
{
  for (int i = 0; i < AMOUNT; i++)
  {
    if (pin == servoPins[i])
      return minAngle[i];
  }
}

int getMaxAngle(int pin)
{
  for (int i = 0; i < AMOUNT; i++)
  {
    if (pin == servoPins[i])
      return maxAngle[i];
  }
}

void servo_tick_disable()
{
  Serial.println("Disable");
  isMoving = false;
}

void servo_target(int size, int pos[], int speed[], int pins[])
{
  for (int i = 0; i < size; i++)
  {
    servo[getIndex(pins[i])].setSpeed(speed[i]);
    servo[getIndex(pins[i])].setTargetDeg(pos[i]);
  }
  isMoving = true;
}

void servo_attach(int size, int pins[], int target[])
{
  for (int i = 0; i < size; i++)
  {
    // servo[getIndex(pins[i])].attach(pins[i]);
    servo[getIndex(pins[i])].attach(pins[i], getMinAngle(pins[i]), getMaxAngle(pins[i]), getMinPWM(pins[i]), getMaxPWM(pins[i]), target);
  }
}

void servo_detach(int size, int pins[])
{
  for (int i = 0; i < size; i++)
  {
    servo[getIndex(pins[i])].detach();
  }
  isMoving = false;
}