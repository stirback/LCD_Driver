#include "LCD.h"

void delay(void)
	{
		uint32_t i=0;
		for(i=0; i < 5000000;i++);
}

int main(void)
{
	//INITILIZE START;
	// Enable the GPIO Clock for GPIO
	RCC->AHB1ENR |= (1 << 3);
	RCC->AHB1ENR |= (1 << 0);
	// Set any Control Registers for GPIO pins
	// Moder
	GPIOD->MODER |= 0b0101010101010101010101;
	GPIOA->MODER |= 0b0101010101010101;
	// OTyper
	GPIOD->OTYPER = 0;
	GPIOA->OTYPER = 0;
	// OSpeedr
	GPIOD->OSPEEDR = 0b1010101010101010101010;
	GPIOA->OSPEEDR = 0b1010101010101010;
	// PUPDr
	GPIOD->PUPDR = 0;
	GPIOA->PUPDR = 0;
	//INITILIZE END
	
	// Turn on the LEDs (BSRR)
	GPIOD->BSRR = (1 << 10); //test LED
	
	LCDInit();
	//Writing Letter A (01000001);
	LCDPrintChar('A');
	//GPIOA->BSRR = 0b1111111111; //8 LEDs simulation data input to LCD
while(1)
{

}
}

