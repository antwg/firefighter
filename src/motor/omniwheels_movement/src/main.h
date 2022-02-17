#ifndef MAIN_H
#define MAIN_H

#include <AFMotor.h>
#include <Arduino.h>

void setup();

//Runs a given motor in the correct direction
void runMotors(int* motor_arr);

// Runs all four motors
void runMotor(AF_DCMotor motor, int speed);

void moveForward(int* motor_arr, int speed);
void moveBackward(int* motor_arr, int speed);
void moveSidewaysRight(int* motor_arr, int speed);
void moveSidewaysLeft(int* motor_arr, int speed);

void rotateLeft();
void rotateRight();

void moveRightForward();
void moveRightBackward();
void moveLeftForward();
void moveLeftBackward();

void motorStop();

#endif