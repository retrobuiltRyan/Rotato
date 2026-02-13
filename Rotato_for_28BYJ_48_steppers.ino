/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board 
Made by Ryan Bates www.retrobuiltgames.com, 2019.
*/

#include <Stepper.h> // Include the Arduino Stepper.h library:
int potValue = A0;
int stepperSpeed = 0;
int reversePin = 11;
int minRPM = 1;
int maxRPM = 20;

// Define number of steps per rotation:
const int stepsPerRevolution = 2048;

// Create object called 'myStepper', note the pin order for these weird motors:
Stepper myStepper = Stepper(stepsPerRevolution, 3, 5, 4, 6);

void setup() {
 myStepper.setSpeed(stepperSpeed);
 pinMode(reversePin, INPUT_PULLUP);  
}

void loop() {
 stepperSpeed = analogRead(potValue);
 stepperSpeed = map(stepperSpeed, 0, 1023, minRPM,maxRPM);
 myStepper.setSpeed(stepperSpeed);
 myStepper.step(1);  

 while (digitalRead(reversePin)== HIGH){
    stepperSpeed = analogRead(potValue);
    stepperSpeed = map(stepperSpeed, 0, 1023, minRPM,maxRPM);
    myStepper.setSpeed(stepperSpeed);
    myStepper.step(-1); }
 
}
