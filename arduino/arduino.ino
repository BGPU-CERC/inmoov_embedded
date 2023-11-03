#include "src/modbus/modbus.h"
#include "src/command/command.h"
#include "src/servo/servo.h"

TLV *packet = modbus_tlv();
char print_buffer[4];

void setup()
{
  Serial.begin(115200);
  servo_setup();
}

void loop()
{
  servo_tick();
}

void serialEvent()
{
  while (Serial.available())
  {
    unsigned char c = Serial.read();
    modbus_read(c);

    sprintf(print_buffer, "%02x ", c);
    Serial.print(print_buffer);

    if (modbus_complete())
    {
      command_process(packet);
      modbus_reset();
    }
  }
}