#include "gpio.h"
#include "timer.h"

int leftMotorPin;
int rightMotorPin;

void motor_init(int pin) {
   gpio_init();
   gpio_set_output(pin);

}

//Assuming transistor setup is sound 
void rovor_motors_init(int leftPin, int rightPin) {
   gpio_init();
   leftMotorPin = leftPin;
   rightMotorPin = rightPin;
   gpio_set_output(leftPin);
   gpio_set_output(rightPin);

}

void run_motor(int pin) {

   gpio_write(pin, 1);

}

void stop_motor(int pin) {

   gpio_write(pin, 0);

}
//Turns to the left a specified number of degrees 
void rovor_turn_left() {


   gpio_write(rightMotorPin, 0);
   gpio_write(leftMotorPin, 1);
   //delay(  );
   gpio_write(leftMotorPin, 0);
		

  gpio_write(rightMotorPin, 0);
  delay_ms(300);
  run_motor(rightMotorPin);
  delay_ms(100);
  gpio_write(rightMotorPin, 0);
  delay_ms(300);

}

//Turns the amount a specified number of degrees 
void rovor_turn_right() {


   gpio_write(leftMotorPin, 0);
   gpio_write(rightMotorPin, 1);
  // delay( );
   gpio_write(rightMotorPin, 0);


  gpio_write(leftMotorPin, 0);
  delay_ms(300);
  run_motor(leftMotorPin);
  delay_ms(100);
  gpio_write(leftMotorPin, 0);
  delay_ms(300);


}

//Moves forward a full rotation
void rovor_move_forward() {

  gpio_write(leftMotorPin, 1);
  gpio_write(rightMotorPin, 1); 


}

//Stops rovor
void rovor_stop() {

 gpio_write(leftMotorPin, 0);
 gpio_write(rightMotorPin, 0);


}
