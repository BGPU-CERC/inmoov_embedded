#include "command.h"
#include "../servo/servo.h"
#include <Arduino.h>
#include <HardwareSerial.h>

int _pins[1] = {};
int _targets[1] = {};
int _speeds[1] = {};

void cmd_servo_set_angle(TLV *tlv)
{
  int pin = tlv->val[0];
  int angle = *(uint16_t *)&tlv->val[1];
  int speed = *(uint16_t *)&tlv->val[3];

  _pins[0] = pin;
  _targets[0] = angle;
  _speeds[0] = speed;

  servo_target(1, _targets, _speeds, _pins);

  Serial.print("CMD_SERVO_SET_ANGLE:");
  Serial.print(" pin: ");
  Serial.print(pin, DEC);
  Serial.print(" angle: ");
  Serial.print(angle, DEC);
  Serial.print(" speed: ");
  Serial.print(speed, DEC);
  Serial.print("\n");
}

void cmd_servo_attach(TLV *tlv)
{
  int pin = tlv->val[0];
  int angle = *(uint16_t *)&tlv->val[1];

  _pins[0] = pin;
  _targets[0] = angle;

  servo_attach(1, _pins, _targets);

  Serial.print("CMD_SERVO_ATTACH:");
  Serial.print(" pin: ");
  Serial.print(pin, DEC);
  Serial.print(" angle: ");
  Serial.print(angle, DEC);
  Serial.print("\n");
}

void cmd_servo_detach(TLV *tlv)
{
  int pin = tlv->val[0];

  _pins[0] = pin;

  servo_detach(1, _pins);

  Serial.print("CMD_SERVO_DETACH:");
  Serial.print(" pin: ");
  Serial.print(pin, DEC);
  Serial.print("\n");
}

void cmd_servo_stop_all(TLV *tlv)
{
  servo_tick_disable();
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
  else if (tlv->tag == CMD_SERVO_ATTACH && tlv->len == 3)
  {
    cmd_servo_attach(tlv);
  }
  else if (tlv->tag == CMD_SERVO_DETACH && tlv->len == 1)
  {
    cmd_servo_detach(tlv);
  }
  else
  {
    cmd_unknown(tlv);
  }
}
