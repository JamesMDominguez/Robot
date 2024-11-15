#include "MotorControl.h"

/*
Functions to move the car in different directions
forward(), backward(), right(), left(), stopCar()

Functions to read the distance from the ultrasonic sensor
readDistance() function returns the distance in cm
example: int distance = readDistance();
*/

void setup(){
    setupMotorPins();
}

void turnRight(){
    right();
    delay(2000);
    stopCar();
    delay(2000);
}

void turnLeft(){
    left();
    delay(2000);
    stopCar();
    delay(2000);
}

void loop(){
    int distance = readDistance();

    if(distance > 40){
        forward();
    }else{
        turnRight();
    }   

}