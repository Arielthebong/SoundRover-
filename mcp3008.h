#ifndef MCP3008_H
#define MCP3008_H

void mcp3008_init();

unsigned mcp3008_read( unsigned channel );
unsigned average_mic(unsigned channel);
unsigned compare_mics(unsigned channel_one, unsigned channel_two, int avg_one, int avg_two);
 
#endif
