#include "command.h"
#include "../servo/servo.h"
#include "../ultrasonic/ultrasonic.h"
#include <Arduino.h>
#include <HardwareSerial.h>

void cmd_servo_set_angle(TLV *tlv)
{
  int pin = tlv->val[0];
  int angle = *(uint16_t *)&tlv->val[1];
  int speed = *(uint16_t *)&tlv->val[3];
  // int currentDeg = servo_get_current_deg(pin); // test
  switch (pin)
  {
  case 77:
    servo_target(23, angle, speed);
    servo_target(29, angle, speed);
    break;

  default:
    servo_target(pin, angle, speed);
  }

  Serial.print("CMD_SERVO_SET_ANGLE:");
  Serial.print(" pin: ");
  Serial.print(pin, DEC);
  Serial.print(" angle: ");
  Serial.print(angle, DEC);
  Serial.print(" speed: ");
  Serial.print(speed, DEC);
  // Serial.print(" currentAngle: ");
  // Serial.print(currentDeg, DEC);
  Serial.print("\n");
}

void cmd_servo_attach(TLV *tlv)
{
  int pin = tlv->val[0];
  int angle = *(uint16_t *)&tlv->val[1];
  int speed = *(uint16_t *)&tlv->val[3];

  switch (pin)
  {
  case 77:
    servo_attach(23, angle, speed);
    servo_attach(29, angle, speed);
    break;

  default:
    servo_attach(pin, angle, speed);
  }

  Serial.print("CMD_SERVO_ATTACH:");
  Serial.print(" pin: ");
  Serial.print(pin, DEC);
  Serial.print(" angle: ");
  Serial.print(angle, DEC);
  Serial.print(" speed: ");
  Serial.print(speed, DEC);
  Serial.print("\n");
}

void cmd_servo_detach(TLV *tlv)
{
  int pin = tlv->val[0];
  servo_detach(pin);

  Serial.print("CMD_SERVO_DETACH:");
  Serial.print(" pin: ");
  Serial.print(pin, DEC);
  Serial.print("\n");
}

void cmd_servo_power(TLV *tlv)
{
  int state = tlv->val[0];
  servo_power(state);
  ultrasonic_ping_mode(state); // test

  Serial.print("CMD_SERVO_POWER:");
  Serial.print(" state: ");
  Serial.print(state, DEC);
  Serial.print("\n");
}

void cmd_servo_stop_all(TLV *tlv)
{
  servo_tick_stop();
  servo_power(0);
}

void cmd_unknown(TLV *tlv)
{
  Serial.print("CMD_UNKNOWN:");
  Serial.print(" tag: ");
  Serial.print(tlv->tag, HEX);
  Serial.print(" len: ");
  Serial.print(tlv->len, HEX);
  Serial.print(" val: ");

  for (char i = 0; i < tlv->len; i++)
  {
    Serial.print(tlv->val[i], HEX);
  }

  Serial.print("\n");
}

void command_process(TLV *tlv)
{
  if (tlv->tag == CMD_SERVO_SET_ANGLE && tlv->len == 5)
  {
    cmd_servo_set_angle(tlv);
  }
  else if (tlv->tag == CMD_SERVO_STOP_ALL && tlv->len == 0)
  {
    cmd_servo_stop_all(tlv);
  }
  else if (tlv->tag == CMD_SERVO_ATTACH && tlv->len == 5)
  {
    cmd_servo_attach(tlv);
  }
  else if (tlv->tag == CMD_SERVO_DETACH && tlv->len == 1)
  {
    cmd_servo_detach(tlv);
  }
  else if (tlv->tag == CMD_SERVO_POWER && tlv->len == 1)
  {
    cmd_servo_power(tlv);
  }
  else
  {
    cmd_unknown(tlv);
  }
}
