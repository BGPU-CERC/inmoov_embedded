#pragma once

void servo_setup();

void servo_tick();

void servo_tick_disable();

void servo_target(int size, int pos[], int speed[], int pins[]);

void servo_attach(int size, int pins[], int target[]);

void servo_detach(int size, int pins[]);

int getIndex(int pin);

int getMinPWM(int pin);

int getMaxPWM(int pin);

int getMinAngle(int pin);

int getMaxAngle(int pin);
