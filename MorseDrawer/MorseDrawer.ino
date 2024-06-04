#include <Stepper.h>

// Define the number of steps per revolution for your 28BYJ-48 motor
const int stepsPerRevolution = 2048;

// Initialize the stepper library with the pins used on your ULN2003 driver
Stepper myStepper(stepsPerRevolution,8,10,9,11);

void setup() {
  // Set the speed of the stepper motor (RPM)
  myStepper.setSpeed(15); // Set to 15 RPM for smooth operation
}

void loop() {
  // Step forward 1 revolution
  myStepper.step(stepsPerRevolution);
  delay(1000); // Wait for 1 second

  // Step backward 1 revolution
  myStepper.step(-stepsPerRevolution);
  delay(1000); // Wait for 1 second
}
