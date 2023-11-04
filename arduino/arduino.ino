#include "src/modbus/modbus.h"
#include "src/command/command.h"
#include "src/servo/servo.h"
#include "src/ultrasonic/ultrasonic.h"

TLV *packet = modbus_tlv();

void setup()
{
  Serial.begin(115200);
  servo_setup();
}

void loop()
{
  servo_tick();
  // ultrasonic_ping();
}

void serialEvent()
{
  while (Serial.available())
  {
    unsigned char c = Serial.read();
    modbus_read(c);

    if (modbus_complete())
    {
      command_process(packet);
      modbus_reset();
    }
  }
}