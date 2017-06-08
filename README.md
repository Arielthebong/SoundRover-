PROJECT PROPOSAL: ROVER

Functions:
Mobility 
Able to move, stop, and navigate around obstacles 
Sensors 
Sonar 
To move forwards and backwards; 3 sonar sensors on front, left, and right sides 
Find Music/Party Function 
Find a source a music within a limited range and travel to the source 
Avoid obstacles using a combination of the mics and 


ASSUMPTIONS
2 microphones ~5cm apart can differentiate signals at any degree rotation.
Obstacles will be freestanding walls or simply legs 

MILESTONES
Wednesday - Get electret mics, sonar sensors, and motor running and returning useful values 
Friday - Combine sensors onto chassis to get a compact rover
Monday - Write code to triangulate locations using the mics and sonar sensors 





Wire the MCP3008 to the Raspberry Pi as follows:

MCP3008 VDD to Raspberry Pi 3.3V
MCP3008 VREF to Raspberry Pi 3.3V
MCP3008 AGND to Raspberry Pi GND
MCP3008 DGND to Raspberry Pi GND
MCP3008 CLK to Raspberry Pi SCLK
MCP3008 DOUT to Raspberry Pi MISO
MCP3008 DIN to Raspberry Pi MOSI
MCP3008 CS/SHDN to Raspberry Pi CE0

doc/ contains

- datasheet
- circuit diagram
- spi protocol


# SoundRover-
