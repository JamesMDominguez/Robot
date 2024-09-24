#include <Arduino.h>
#include "MotorControl.h"

// Motor pins (replace with appropriate pins)
int motor1pin1 = 25;
int motor1pin2 = 33;
int motor2pin1 = 32;
int motor2pin2 = 27;
int enablePin = 14;  
int enablePin2 = 26;

void setupMotorPins()
{
    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(enablePin2, OUTPUT);
}

void forward()
{
    int speed = 225;
    Serial.println("Forward");

    // Add code to move the car forward
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    analogWrite(enablePin, speed);
    analogWrite(enablePin2, speed);
}

void backward()
{
    int speed = 225;
    Serial.println("backward");
    // Add code to move the car backward
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    analogWrite(enablePin, speed);
    analogWrite(enablePin2, speed);
}

void right()
{
    int speed = 225;
    Serial.println("right");
    // forward movement
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    // reverse movement
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    analogWrite(enablePin, speed);
    analogWrite(enablePin2, speed);
    // Add code to move the car right
}

void left()
{
    int speed = 225;
    Serial.println("left");
    // Add code to move the car left
    // backward movement
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor1pin1, HIGH);
    // forward movement
    digitalWrite(motor2pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    analogWrite(enablePin, speed);
    analogWrite(enablePin2, speed);
}

void rightForward()
{
    int speed = 225;
    Serial.println("Right Forward");
    // Add code to move the car Right Forward
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    analogWrite(enablePin, speed);
    analogWrite(enablePin2, (speed / 2));
}

void leftForward()
{
    int speed = 225;
    Serial.println("Left Forward");
    // Add code to move the car Left Forward
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    analogWrite(enablePin, (speed / 2));
    analogWrite(enablePin2, speed);
}

void rightBackward()
{
    int speed = 225;
    Serial.println("Right Backward");
    // Add code to move the car Right Backward

    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    analogWrite(enablePin, speed);
    analogWrite(enablePin2, (speed / 2));
}

void leftBackward()
{
    int speed = 225;

    Serial.println("Left Backward");
    // Add code to move the car Left Backward
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    analogWrite(enablePin, (speed / 2));
    analogWrite(enablePin2, speed);
}

void stopCar()
{
    Serial.println("Stop");
    // Add code to move the car Left Backward
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(motor2pin1, LOW);
}