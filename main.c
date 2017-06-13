/* Simple SPI + MCP3008 ADC test. */
#include "gpio.h"
#include "printf.h"
#include "mcp3008.h"
#include "sonar.h"
#include "motor.h"
#include "timer.h"

void main() {
   mcp3008_init();
     gpio_init();
  //sonar_init();
   int total1 = 0;
volatile   int count1= 0;
     //       int difference = 0;
        while (count1 < 500) {
	  count1++;
	  //  int result0 = mcp3008_read(0);
	  int result1 = mcp3008_read(1);
	//int result2 = mcp3008_read(2);
	  total1 += result1;
		
	  //	if(result0>result1){
	  //    difference = result0 - result1;
	  //} else {
	  //   difference = result1 - result0;
	  //}
//	int result2 = mcp3008_read(2);
/*	if(result0 > 800) {
		printf("HIGH\n");
	} else if (result0 < 550) {
s
		printf("---------------\n");
	} else if (result0 < 650 && result0 > 550)
		printf("NORMAL\n");*/
//	if(result0 > high0) 
//        	high0 = result0;
//	if(result1 > high1)
//		high1 = result1;
//	printf("dif = %d\n", difference);
//	printf("high1 = %d\n", high1);
   printf("result1 = %d \n", result1);
	//printf("result2 = %d\n", result2);

	//	printf("%d\n", get_distance());
   /* motor_init(GPIO_PIN20);
   motor_init(GPIO_PIN21);
   motor_init(GPIO_PIN24);
   motor_init(GPIO_PIN25);
   while(1){   
run_motor(GPIO_PIN24);
   run_motor(GPIO_PIN25);
   run_motor(GPIO_PIN20);
   run_motor(GPIO_PIN21);
  volatile int count = 10000;
   while(count != 0) count--;
   stop_motor(GPIO_PIN21);
   */

   //unsigned distance = get_distance();
   // printf('Nothing');
     //printf("distance = %d \n", distance);

    }
	int av1 = total1/50;
	printf("Average = %d", av1);

}
