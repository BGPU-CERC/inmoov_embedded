#pragma once
#include "NewPing.h"

struct ultrasonic
{
    NewPing *sonar;
};

void ultrasonic_ping();

void ultrasonic_ping_mode(bool mode);
