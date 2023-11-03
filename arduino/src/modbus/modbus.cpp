#include "modbus.h"
#include <Arduino.h>

struct TLV tlv;

char modbus_state = MODBUS_STATE_TAG;
char modbus_val_index = 0;

void modbus_check_tag(unsigned char data)
{
  tlv.tag = data;
  modbus_state = MODBUS_STATE_LEN;
}

void modbus_check_len(unsigned char data)
{
  tlv.len = data;

  switch (data)
  {
  case 0:
    modbus_state = MODBUS_STATE_COMPLETE;
    break;
  default:
    modbus_state = MODBUS_STATE_VAL;
    break;
  }
}

void modbus_check_val(unsigned char data)
{
  tlv.val[modbus_val_index++] = data;

  if (modbus_val_index >= tlv.len)
  {
    modbus_state = MODBUS_STATE_COMPLETE;
  }
}

char modbus_read(unsigned char data)
{
  switch (modbus_state)
  {
  case MODBUS_STATE_TAG:
    modbus_check_tag(data);
    break;
  case MODBUS_STATE_LEN:
    modbus_check_len(data);
    break;
  case MODBUS_STATE_VAL:
    modbus_check_val(data);
    break;
  default:
    break;
  }

  return modbus_state;
}

bool modbus_complete()
{
  return modbus_state == MODBUS_STATE_COMPLETE;
}

void modbus_reset()
{
  modbus_state = MODBUS_STATE_TAG;
  modbus_val_index = 0;
}

TLV *modbus_tlv()
{
  return &tlv;
}
