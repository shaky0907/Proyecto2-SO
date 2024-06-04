#include <Stepper.h>
#include <Servo.h>

Servo myServo;

// Define the number of steps per revolution for your 28BYJ-48 motor
const int stepsPerRevolution = 2048;
int move =50;
// Initialize the stepper library with the pins used on your ULN2003 driver
Stepper myStepper(stepsPerRevolution,8,10,9,11);

void setup() {
  // Set the speed of the stepper motor (RPM)
  myStepper.setSpeed(15); // Set to 15 RPM for smooth operation
  myServo.attach(7);
  myServo.write(105);
}

void loop() {
  // Step forward 1 revolution
  delay(5000);
  delay(1000);
  myServo.write(120);
  delay(1000);
  myStepper.step(move);
  delay(1000);
  myServo.write(105);
  delay(1000);
  myStepper.step(move);
  





}