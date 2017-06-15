/* Simple SPI + MCP3008 ADC test. */
#include "gpio.h"
#include "printf.h"
#include "mcp3008.h"
#include "sonar.h"
#include "motor.h"
#include "timer.h"


const int FRONT_SONAR = 0;
//const int LEFT_SONAR = 1;
//const int RIGHT_SONAR = 2;
const int LEFT_MIC = 0;
const int RIGHT_MIC = 1;


void main() {

    mcp3008_init();
   sonars_init();
  rovor_motors_init(GPIO_PIN24, GPIO_PIN25);
//     unsigned distance = 1996;
     unsigned avg_one = average_mic(LEFT_MIC);
     unsigned avg_two = average_mic(RIGHT_MIC);


//   int high0 = 0;
 //  int high1 = 0;
//    int difference = 0;
    while (1) {
	//int result0 = mcp3008_read(LEFT_MIC);
        //:int result1 = mcp3008_read(RIGHT_MIC);
  //   mcp3008_init();
//    delay(10);
   
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

//CALIBRATE TOWARDS SOUND THEN STOP ADJUSTING AFTERWARDS 
       
	int compare = compare_mics(LEFT_MIC, RIGHT_MIC, avg_one, avg_two);
	int mic_count = 0;
	int mic_curr = 0;
	while(1) {
		compare = compare_mics(LEFT_MIC, RIGHT_MIC, avg_one, avg_two);
		printf("TURN: %d\n", compare);

		if( compare == mic_curr) 
			mic_count++;
		else {
			mic_curr = compare;
			mic_count = 0;

		}
		
		if(mic_count == 5 && mic_curr == 999)
			break;
		else if(mic_count == 3 && mic_curr == 0) {
		rovor_turn_left();
			mic_count = 0;
		}
		else if(mic_count == 3 && mic_curr == 1) {

			rovor_turn_right();
                        mic_count = 0;

		}
			

	}

		
			
		
	
  //printf("start = %d",distance);
  //volatile int i = 0;


//  while(distance > 5 ){
/*    rovor_stop();
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
	//printf("louder mic: = %d\n", compare_mics(LEFT_MIC, RIGHT_MIC, average_mic(LEFT_MIC), average_mic(RIGHT_MIC)));
    //    printf("average0 = %d ", average_mic(0));
      //  printf("average1 = %d\n ", average_mic(1));

//MEASURES DIFFERNT STATISTICS SUCH AS AVERAGE OF MIC, AVERAGE UPPER DIFFERENCE, AND AVERAGE LOWER DIFFERENCE 
 	int cycles = 250;
	int average0 = average_mic(LEFT_MIC);
	int average1 = average_mic(RIGHT_MIC);
	int high_diff0 = 0;
	int high_diff1 = 0;
	int low_diff0 = 0;
	int low_diff1 = 0;
	int i = 0;
	while(i < cycles) {
		int temp0 = mcp3008_read(LEFT_MIC);
		int temp1 = mcp3008_read(RIGHT_MIC);
		if(temp0 > average0 && temp1 > average1) {
			temp0 -= average0;
			temp1 -= average1;
			high_diff0 += temp0;
			high_diff1 += temp1;
			i++;
		}
	}

	i = 0;
	while(i < cycles) {
		int temp0 = mcp3008_read(LEFT_MIC);
                int temp1 = mcp3008_read(RIGHT_MIC);
		if(temp0 < average0 && temp1 < average1) {

                        temp0 -= average0;
                        temp1 -= average1;
                        low_diff0 += temp0;
                        low_diff1 += temp1;
                        i++;

                }

	}
	high_diff0 /= cycles;
	high_diff1 /= cycles;
	low_diff0 /= cycles;
	low_diff1 /= cycles;
	int avg_diff0 = (-1*low_diff0 + high_diff0)/2;
	int avg_diff1 = (-1*low_diff1 + high_diff1)/2;
	printf("average0  = %d, high_diff = %d, low_diff0 = %d, avg_dist0 = %d\n", average0, high_diff0, low_diff0, avg_diff0);
	printf("average1  = %d, high_diff1 = %d, low_diff1 = %d, avg_dist1 = %d\n", average1, high_diff1, low_diff1, avg_diff1);

*/
	
	int distance = get_sonar_distance(FRONT_SONAR);
	rovor_move_forward();
	while(distance > 13 && distance < 900) { //Would get random 
		distance = get_sonar_distance(FRONT_SONAR);
	//printf("%d \n",distance);
	}
	rovor_stop(); 
	int result0 = mcp3008_read(LEFT_MIC);
        int result1 = mcp3008_read(RIGHT_MIC);
	int stopCount = 0;
/*	for(int i = 0; i < 5; i++) {

		if(result0 > 700 || result0 == 0)
			stopCount++;
		else if(result1 > 700 || result1 == 0)
			stopCount++;

		

	}
	if(stopCount >= 5)
		break;
	 result0 = mcp3008_read(LEFT_MIC);
         result1 = mcp3008_read(RIGHT_MIC);

	  printf("result0 = %d \n", result0);
        printf("result1 = %d\n", result1);

*/

//	printf("result2 = %d\n", result2);

//	printf("front sonar: %d\n", get_sonar_distance(FRONT_SONAR));
  //      delay_us(1000);
    //    printf("left sonar: %d\n", get_sonar_distance(LEFT_SONAR));
    //	printf("right sonar: %d\n", get_sonar_distance(RIGHT_SONAR));

//   printf("front sonar: %d\n", get_sonar_distance(FRONT_SONAR));
         
// printf("left sonar: %d\n", get_sonar_distance(LEFT_SONAR));
      //	printf("right sonar: %d\n", get_sonar_distance(RIGHT_SONAR));
  }
         
  // stop_motor(GPIO_PIN25);
  // stop_motor(GPIO_PIN24);


}
