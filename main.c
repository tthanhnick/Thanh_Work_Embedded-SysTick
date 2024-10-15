#include "header.h"

volatile int counter = 0;

int main(void)
{
	//SetOrClearBit((unsigned int*) PCC_PORTD, 30u, SET_BIT);
	LEDConfig();
	//SW3Config();
	SysTick();
	while(1)
	{
		if(counter == 5)
		{
			SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT);
		}
		if (counter == 10)
		{
			SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, CLEAR_BIT); 
			counter = 0;
		}
	}
}

void SysTick_Handler(void) 
{
  counter++;
	SetOrClearBit((unsigned int*) SYSTICK_CTRL, 16, SET_BIT);
}