#include "ultrasonic.h"
#include "../config/config.h"

unsigned long previousMillis = 0;
byte pollingTime = 100;
boolean pinging = false;

void ultrasonic_ping()
{
    if (millis() - previousMillis > pollingTime)
    {

        if (!pinging)
        {
            return;
        }

        previousMillis = millis();

        int leftDistance = utlrasonics[0].sonar->ping_cm();
        int rightDistance = utlrasonics[1].sonar->ping_cm();

        // Отправить на frontend

        // Serial.print("Distance left: ");
        // Serial.println(leftDistance);
        // Serial.print("Distance right: ");
        // Serial.println(rightDistance);
    }
}

void ultrasonic_ping_mode(bool mode)
{
    pinging = !mode;
}
