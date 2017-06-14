/* Simple SPI + MCP3008 ADC test. */
#include "gpio.h"
#include "printf.h"
#include "mcp3008.h"
#include "sonar.h"
#include "motor.h"
#include "timer.h"

const int FRONT_SONAR = 0;
const int LEFT_SONAR = 1;
const int RIGHT_SONAR = 2;

void main() {
  //   mcp3008_init();
    gpio_init();
    sonars_init();
   	  //  int result0 = mcp3008_read(0);
     //  int result1 = mcp3008_read(1);
	//int result2 = mcp3008_read(2);
	//  total1 += result1;
//   int high0 = 0;
 //  int high1 = 0;
//    int difference = 0;
//	int result0 = mcp3008_read(0)- 560;
  //      int result1 = mcp3008_read(1)- 500;
//	int result2 = mcp3008_read(2);
	/*if(result0 > 570);
		
	  //	if(result0>result1){
	  //    difference = result0 - result1;
	  //} else {
	  //   difference = result1 - result0;
	  //}
//	int result2 = mcp3008_read(2);
	if(result0 < 0) 
		result0 = 0;
	 if (result1 < 0)
		result1 = 0;
*/
//	if(result0 > high0) 
//        	high0 = result0;
//	if(result1 > high1)
//		high1 = result1;
//	printf("dif = %d\n", difference);
//	printf("high1 = %d\n", high1);
      //  printf("result1 = %d \n", result1);
	//printf("result2 = %d\n", result2);

	//	printf("%d\n", get_distance());
    rovor_motors_init(GPIO_PIN24, GPIO_PIN25);
      unsigned distance = 1996;
  //printf("start = %d",distance);
  volatile int i = 0;


  while(distance > 5 ){
    rovor_stop();
    distance = 0;
    i = 0;
    while(i<10){
   unsigned temp_distance = get_sonar_distance(FRONT_SONAR);
   distance+= temp_distance;
   i++;
   //run_motor(GPIO_PIN25);
   //run_motor(GPIO_PIN24);
    }
    distance /= 10;
    rovor_turn_left(i);
    printf("Left");
    delay_ms(5000);
    rovor_stop();
    delay_ms(500);
    rovor_turn_right(i);
    printf("right");
    delay_ms(5000);
    //run_motor(GPIO_PIN25);
    //run_motor(GPIO_PIN24); 
   // printf('Nothing');
    //printf("distance = %d \n", distance);
//	printf("result0 = %d ", result0);
//	printf("result1 = %d\n ", result1);
//	printf("result2 = %d\n", result2);
//   printf("front sonar: %d\n", get_sonar_distance(FRONT_SONAR));
         
// printf("left sonar: %d\n", get_sonar_distance(LEFT_SONAR));
      //	printf("right sonar: %d\n", get_sonar_distance(RIGHT_SONAR));
  }
         
   stop_motor(GPIO_PIN25);
   stop_motor(GPIO_PIN24);

}
