MCP3301 Analog-to-Digital Converter for Raspberry Pi 3:
-------------------------------------------------------
This is an example code to interface MCP3301 ADC to Raspberry Pi 2/3 SPI port using bcm2835 GPIO library from AirSpayce (http://www.airspayce.com/mikem/bcm2835/index.html).

The bcm2837 GPIO library used in this example is a simple modification of the original one mentioned previously to fit the new Raspberry Pi 3 boards.

About MCP3301:
--------------
MCP3301 is a 13-bit, 100 KSps Analog-to-Digital converter (ADC) from Microchip Technologies.

Wiring:
------
Raspberry Pi 2/3 side -> MCP3301 side
SPI_SCLK (pin 23)     -> CLK
SPI_MISO (pin 21)     -> Dout
SPI_CE0 (pin 24)      -> CS 

Other connections for MCP3301:
Vref -> 2.5v (use MCP1525 or a two resistor voltage divider).
VDD -> 5v.