#include <Arduino.h>
#include "MotorControl.h"

// Motor pins (replace with appropriate pins)
int motor1pin1 = 14;
int motor1pin2 = 27;
int motor2pin1 = 26;
int motor2pin2 = 25;
int enablePin = 12;  
int enablePin2 = 33;

// ultra sonic sensor pins
int trigPin = 4;  // Trigger Pin of Ultrasonic Sensor
int echoPin = 2;  // Echo Pin of Ultrasonic Sensor

// Speed variables
int leftSpeed = 225; // values from 0 to 255
int rightSpeed = 225; // values from 0 to 255

void setupMotorPins()
{
    Serial.begin(115200);
    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    pinMode(enablePin2, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void forward()
{
    Serial.println("Forward");

    // Add code to move the car forward
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    analogWrite(enablePin, leftSpeed);
    analogWrite(enablePin2, rightSpeed);
}

void backward()
{
    Serial.println("backward");
    // Add code to move the car backward
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    analogWrite(enablePin, leftSpeed);
    analogWrite(enablePin2, rightSpeed);
}

void right()
{
    Serial.println("right");
    // forward movement
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    // reverse movement
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    analogWrite(enablePin, leftSpeed);
    analogWrite(enablePin2, rightSpeed);
    // Add code to move the car right
}

void left()
{
    Serial.println("left");
    // Add code to move the car left
    // backward movement
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor1pin1, HIGH);
    // forward movement
    digitalWrite(motor2pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    analogWrite(enablePin, leftSpeed);
    analogWrite(enablePin2, rightSpeed);
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
