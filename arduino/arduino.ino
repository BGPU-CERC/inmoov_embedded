#include "src/modbus/modbus.h"
#include "src/command/command.h"
#include "src/servo/servo.h"
#include "src/ultrasonic/ultrasonic.h"

TLV *packet = modbus_tlv();

unsigned long patternPrevious = 0; // test neopixel
byte patternCurrent = 0;

void setup()
{
  Serial.begin(115200);
  Serial3.begin(115200);
  servo_setup();

  // servo_power(false); // test neopixel
  // patternCurrent = 1;
}

void loop()
{
  servo_tick();
  // ultrasonic_ping();

  if (millis() - patternPrevious >= 10000)
  {
    patternPrevious = millis();
    Serial3.write(patternCurrent);
    patternCurrent++;

    if (patternCurrent > 5)
    {
      patternCurrent = 1;
    }
  }
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