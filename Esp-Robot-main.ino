#include "MotorControl.h"

void setup(){
    Serial.begin(115200);
    setupMotorPins();
}
// Functions to move the car in different directions
// forward(), backward(), right(), left(), rightForward(), leftForward(), rightBackward(), leftBackward(), stopCar()

void loop(){
    forward();
    delay(2000);
    stopCar();
    delay(1000);
    backward();
}