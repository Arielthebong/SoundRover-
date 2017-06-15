#include "spi.h"
#include "mcp3008.h"
#include "printf.h"

void mcp3008_init() {
    spi_init(SPI_CE0, 1024); /* 250KHz */
}


unsigned mcp3008_read( unsigned channel ) {
    unsigned char tx[3];
    unsigned char rx[3];

    // "Start bit", wakes up the ADC chip. 
    tx[0] = 1;
    // "Configuration byte", single mode + channel
    tx[1] = 0x80 | ((channel & 0x7) << 4);
    tx[2] = 0;

    spi_transfer(tx, rx, 3);
    return ((rx[1] & 0x3) << 8) + rx[2];
}

//Returns average value of a mic with 500 iterations 
unsigned average_mic(unsigned channel) {
   int sum = 0;
   int cycles = 300;
   for(int i = 0; i < cycles; i++) {
	sum += mcp3008_read(channel);
   }

   return sum/cycles;
}

/*Returns 0 if channel one is louder, Returns 1 if channel two is louder, Returns 999 if neither. One is louder than other if greater than one*/
unsigned compare_mics(unsigned channel_one, unsigned channel_two, int avg_one, int avg_two) {
   int cycles = 300;
   int diff_one = 0;
   int diff_two = 0;
   for(int i = 0; i < cycles; i++) {
	int read_one = mcp3008_read(channel_one);
	int read_two = mcp3008_read(channel_two);

	read_one -= avg_one;
	read_two -= avg_two;
	if(read_one < 0) //Take absolute value 
		read_one = -read_one;
	if(read_two < 0) 
		read_two = -read_two;

	diff_one += read_one;
	diff_two += read_two;
   }
   
   diff_one /= cycles;
   diff_two /= cycles;
   printf("diff_one = %d ", diff_one);
   printf("diff_two = %d\n", diff_two);   
   if(diff_one - diff_two >= 20)
	return 0;
   else if(diff_two - diff_one >= 20)
	return 1;
   else 
	return 999;
}

