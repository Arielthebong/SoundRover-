/* Simple SPI + MCP3008 ADC test. */

#include "printf.h"
#include "mcp3008.h"
#include "sonar.h"
#include "motor.h"
#include "timer.h"

void main() {
    mcp3008_init();
   sonar_init();
   //int high0 = 0;
   // int high1 = 0;
    int difference = 0;
    while (1) {
	int result0 = mcp3008_read(0);
        int result1 = mcp3008_read(1);
	int result2 = mcp3008_read(2);
	/*if(result0 > 570)
		
	if(result0>result1){
	    difference = result0 - result1;
	} else {
	     difference = result1 - result0;
	}*/
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
	printf("result0 = %d ", result0);
	printf("result1 = %d ", result1);
	printf("result2 = %d\n", result2);

//	printf("%d\n", get_distance());

    }
}
