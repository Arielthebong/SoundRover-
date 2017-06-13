/* Simple SPI + MCP3008 ADC test. */

#include "printf.h"
#include "mcp3008.h"
#include "sonar.h"
#include "motor.h"
#include "timer.h"

const int FRONT_SONAR = 0;
const int LEFT_SONAR = 1;
const int RIGHT_SONAR = 2;

void main() {
//    mcp3008_init();
   sonars_init();
 //  sonar_init(rightSonar, 20, 21);
   //sonar_init(leftSonar, 24, 25);

//   int high0 = 0;
 //  int high1 = 0;
//    int difference = 0;
    while (1) {
//	int result0 = mcp3008_read(0)- 560;
  //      int result1 = mcp3008_read(1)- 500;
//	int result2 = mcp3008_read(2);
	/*if(result0 > 570)
		
	if(result0>result1){
	    difference = result0 - result1;
	} else {
	     difference = result1 - result0;
	}*/
//	int result2 = mcp3008_read(2);
/*	if(result0 < 0) 
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
//	printf("result0 = %d ", result0);
//	printf("result1 = %d\n ", result1);
//	printf("result2 = %d\n", result2);
	printf("front sonar: %d\n", get_sonar_distance(FRONT_SONAR));
        delay_us(1000);
        printf("left sonar: %d\n", get_sonar_distance(LEFT_SONAR));
    	printf("right sonar: %d\n", get_sonar_distance(RIGHT_SONAR));

    }
}
