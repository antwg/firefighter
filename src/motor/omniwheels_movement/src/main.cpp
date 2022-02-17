// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include "main.h"

const int PWM_PIN = A0;
const int standStill = 1500; // Controller in middle position
const int BAUD_RATE = 9600;

AF_DCMotor RightFrontWheel(3);
AF_DCMotor LeftBackWheel(2);
AF_DCMotor RightBackWheel(4);
AF_DCMotor LeftFrontWheel(1);

int motor_arr[4];
int speed = 255;

int LFW_SPEED = motor_arr[0];
int LBW_SPEED = motor_arr[1];
int RFW_SPEED = motor_arr[2];
int RBW_SPEED = motor_arr[3];

void setup() {
   Serial.begin(BAUD_RATE);
   Serial.println("Motor test!");

   // turn on motor dont crash code
   RightBackWheel.run(RELEASE);
   LeftBackWheel.run(RELEASE);
   LeftFrontWheel.run(RELEASE);
   RightFrontWheel.run(RELEASE);
}

void loop() {
   // Array order:
   //    Left front
   //    Left back
   //    Right front
   //    Right back

   // Creating a test seq
   moveForward(motor_arr, speed);
   runMotors(motor_arr);
   delay(2000);
   moveSidewaysRight(motor_arr, speed);
   runMotors(motor_arr);
   delay(2000);
   moveBackward(motor_arr, speed);
   runMotors(motor_arr);
   delay(2000);
   moveSidewaysLeft(motor_arr, speed);
   runMotors(motor_arr);
   delay(2000);
}

void runMotor(AF_DCMotor motor, int speed){
   motor.setSpeed(abs(speed));
   if (speed > 0) {
      motor.run(FORWARD);
   }
   else {
      motor.run(BACKWARD);
   }
}

void runMotors(int* motor_arr){
   runMotor(LeftFrontWheel, motor_arr[0]);
   runMotor(LeftBackWheel, motor_arr[1]);
   runMotor(RightFrontWheel, motor_arr[2]);
   runMotor(RightBackWheel, motor_arr[3]);
}

void moveForward(int* motor_arr, int speed)
{
   LFW_SPEED = speed;
   LBW_SPEED = speed;
   RFW_SPEED = speed;
   RBW_SPEED = speed; 
   //LeftFrontWheel.run(FORWARD); 
}
void moveBackward(int* motor_arr, int speed) {
   LFW_SPEED = -speed;
   LBW_SPEED = -speed;
   RFW_SPEED = -speed;
   RBW_SPEED = -speed;
   
}
void moveSidewaysRight(int* motor_arr, int speed) {
   LFW_SPEED = speed;
   LBW_SPEED = -speed;
   RFW_SPEED = -speed;
   RBW_SPEED = speed;
   
}
void moveSidewaysLeft(int* motor_arr, int speed) {
   LFW_SPEED = -speed;
   LBW_SPEED = speed;
   RFW_SPEED = speed;
   RBW_SPEED = -speed;
   
}
void rotateLeft(int* motor_arr, int speed) {
   LFW_SPEED = -speed;
   LBW_SPEED = -speed;
   RFW_SPEED = speed;
   RBW_SPEED = speed;
   
}
void rotateRight(int* motor_arr, int speed) {
   LFW_SPEED = speed;
   LBW_SPEED = speed;
   RFW_SPEED = -speed;
   RBW_SPEED = -speed;
   
}
/*
void moveRightForward() {
  
   LeftFrontWheel.run(FORWARD);
  // LeftBackWheel.run(FORWARD);
   
 //  RightFrontWheel.run(BACKWARD);
   RightBackWheel.run(BACKWARD);
   
}
void moveRightBackward() {
  
  // LeftFrontWheel.run(FORWARD);
   LeftBackWheel.run(BACKWARD);
   
   RightFrontWheel.run(BACKWARD);
 //  RightBackWheel.run(BACKWARD);
   
}
void moveLeftForward() {
  // LeftFrontWheel.run(FORWARD);
   LeftBackWheel.run(FORWARD);
   
   RightFrontWheel.run(FORWARD);
 //  RightBackWheel.run(BACKWARD);
}
void moveLeftBackward() {
  
   LeftFrontWheel.run(BACKWARD);
  // LeftBackWheel.run(FORWARD);
   
 //  RightFrontWheel.run(FORWARD);
   RightBackWheel.run(BACKWARD);
}
void motorStop(){
  
   LeftFrontWheel.run(RELEASE);
   LeftBackWheel.run(RELEASE);
   
   RightFrontWheel.run(RELEASE);
   RightBackWheel.run(RELEASE);
}
*/



