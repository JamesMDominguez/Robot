#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

void setupMotorPins();
void forward();
void backward();
void right();
void left();
void stopCar();
int readDistance();

#endif // MOTOR_CONTROL_H