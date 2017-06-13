/*
 * HC-SR04


   http://www.modmypi.com/blog/hc-sr04-ultrasonic-range-sensor-on-the-raspberry-pi
   IMPORTANT. The sensor output signal (ECHO) on the HC-SR04 is rated
   at 5V. However, the input pin on the Raspberry Pi GPIO is rated at
   3.3V. Sending a 5V signal into that unprotected 3.3V input port could
   damage your GPIO pins, which is something we want to avoid! We’ll
   need to use a small voltage divider circuit, consisting of two
   resistors, to lower the sensor output voltage to something our
   Raspberry Pi can handle.

   http://www.bytecreation.com/blog/2013/10/13/raspberry-pi-ultrasonic-sensor-hc-sr04
 */
#include "timer.h"
#include "gpio.h"
#include "gpioextra.h"
#include "printf.h"

//const unsigned trigger;
//const unsigned echo;

typedef struct {
   int frontTrig;
   int frontEcho;

   int leftTrig;
   int leftEcho;

   int rightTrig;
   int rightEcho;


} sonar_config_t;

static sonar_config_t sonars;

void sonars_init() {

   printf_init();
   sonars.frontTrig = 20;
   sonars.frontEcho = 21;

   sonars.rightTrig = 3;
   sonars.rightEcho = 2;

   sonars.leftTrig = 22; 
   sonars.leftEcho = 23;
 
   gpio_set_output(sonars.frontTrig);
   gpio_set_input(sonars.frontEcho);
   gpio_set_pulldown(sonars.frontEcho);

   gpio_set_output(sonars.leftTrig);
   gpio_set_input(sonars.leftEcho);
   gpio_set_pulldown(sonars.leftEcho);

   gpio_set_output(sonars.rightTrig);
   gpio_set_input(sonars.rightEcho);
   gpio_set_pulldown(sonars.rightEcho);

}

unsigned get_distance(int trigPin, int echoPin) {
   // write hi for 10usec
   gpio_write(trigPin, 1);
   delay_us(10);
   gpio_write(trigPin, 0);

   unsigned start = timer_get_time();
   delay_us(149); // wait til device settles: 148 = time to go one inch
   while(!gpio_read(echoPin))
		;

   unsigned end;
   while(gpio_read(echoPin) == 1)
		;
   end = timer_get_time();

   // ((340M/S / 2) * 39.37inch / meter) / 10^6 = inch/usec
   return (end - start) / 149;
}

//Intended for three sonars; 0, 1, and 2, front, left, and right 
unsigned get_sonar_distance(int sonar) {
    if(sonar == 0) 
	return get_distance(sonars.frontTrig, sonars.frontEcho);
    else if(sonar == 1)
	return get_distance(sonars.leftTrig, sonars.leftEcho);
    else if(sonar == 2) 
	return get_distance(sonars.rightTrig, sonars.rightEcho);
   
    return 0;

}
