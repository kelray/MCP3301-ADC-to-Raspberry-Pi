/* 
 * File:   main.cpp
 * MCP3301 13-bit ADC interface example
 * Pin connection:
 * Raspberry Pi -> MCP3301
 * SPI_SCLK (pin 23) -> CLK
 * SPI_MISO (pin 21) -> Dout
 * SPI_CE0 (pin 24) -> CS 
 * Other connections:
 * Vref -> 2.5v (use MCP1525)
 * VDD -> 5v
 * License: open, no liability on the the author
 */

#include <cstdlib>
#include <stdio.h>
#include "bcm2835.h"


int main(int argc, char** argv) 
{
	char ADCbuffer[2];
	unsigned int ADCReading = 0;
	
	if (!bcm2835_init())
	{
		printf("BCM2835 Not initializied\n");
	}
	
	bcm2835_spi_begin();
	
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);	// The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);					// The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256);	// 1 MHz
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);					// The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, HIGH);	// the default
	
	while(1)
	{
		bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);
		bcm2835_delay(2);
		bcm2835_spi_transfern(ADCbuffer, 2);		
		ADCReading = ADCbuffer[0];
		ADCReading = ADCReading << 8;
		ADCReading = ADCReading | ADCbuffer[1];
		printf("ADC reading is: %d\n", ADCReading);
		bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, HIGH);
	}
	return 0;
}

