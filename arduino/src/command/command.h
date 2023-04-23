#pragma once

#include "../modbus/modbus.h"

#define CMD_SERVO_SET_ANGLE 10
#define CMD_SERVO_STOP_ALL 11
#define CMD_SERVO_ATTACH 12
#define CMD_SERVO_DETACH 13
#define CMD_SERVO_POWER 14

void command_process(TLV *tlv);
