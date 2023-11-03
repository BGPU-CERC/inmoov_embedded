#include "command.h"
#include "../servo/servo.h"
#include <Arduino.h>
#include <HardwareSerial.h>

void cmd_servo_set_angle(TLV *tlv)
{
  int pin = tlv->val[0];
  int angle = *(uint16_t *)&tlv->val[1];
  int speed = *(uint16_t *)&tlv->val[3];
  servo_target(pin, angle, speed);

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
  int speed = *(uint16_t *)&tlv->val[3];

  servo_attach(pin, angle, speed);

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
  switch (tlv->tag)
  {
  case CMD_SERVO_SET_ANGLE:
    cmd_servo_set_angle(tlv);
    break;
  case CMD_SERVO_STOP_ALL:
    cmd_servo_stop_all(tlv);
    break;
  case CMD_SERVO_ATTACH:
    cmd_servo_attach(tlv);
    break;
  case CMD_SERVO_DETACH:
    cmd_servo_detach(tlv);
    break;
  case CMD_SERVO_POWER:
    cmd_servo_power(tlv);
    break;
  default:
    cmd_unknown(tlv);
    break;
  }
}
