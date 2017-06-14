#ifndef MOTOR_H
#define MOTOR_H

void motor_init(int pin);
void run_motor(int pin);
void stop_motor(int pin);
void rovor_motors_init(int leftPin, int rightPin);
void rovor_turn_left(int degrees);
void rovor_turn_right(int degrees);
void rovor_move_forward();
void rovor_stop();

#endif
