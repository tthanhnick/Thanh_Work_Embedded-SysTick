#include "header.h"

void SetOrClearBit(unsigned int *address, unsigned char position, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (1U<<position);
	}
	else
	{
		*address &= ~(1U<<position);
	}
	return;
}

void SetOrClearMultiBit(unsigned int *address, unsigned char position, unsigned int mask, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (mask<<position);
	}
	else
	{
		*address &= ~(mask<<position);
	}
	return;
}

void LEDConfig (void)
{
	SetOrClearBit((unsigned int*) PCC_PORTD, 30u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) PORT_PCR15, 8u, 1u, SET_BIT);
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 15u, SET_BIT); 
}

void delay(void)
{
	for(int i=0; i< 300000; i++);
}

void LEDToggle (void)
{
	SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, CLEAR_BIT); 
	delay();
	SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT); 
	delay();   
}

void SW3Config (void)
{
	SetOrClearBit((unsigned int*) PCC_PORTC, 30u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) PORT_PCR13, 8u, 1u, SET_BIT);
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 13u, CLEAR_BIT);
	
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 15u, 1u, SET_BIT);
}

void SW3Toggle (void)
{
	unsigned int state = ((*(unsigned int*)GPIOC_PDIR) & (1 << 13));
	if (state)
	{
		SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, CLEAR_BIT); 
	}
	else
	{
		SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT); 
	}
}

void SysTick(void)
{
	SetOrClearBit((unsigned int*) SYSTICK_CTRL, 0, CLEAR_BIT);
	SetOrClearMultiBit((unsigned int*) SYSTICK_VAL, 0, 0, SET_BIT);
	SetOrClearMultiBit((unsigned int*) SYSTICK_LOAD, 0, 4800000-1, SET_BIT); //0.1s
	SetOrClearBit((unsigned int*) SYSTICK_CTRL, 0, SET_BIT);
	SetOrClearBit((unsigned int*) SYSTICK_CTRL, 2, SET_BIT);
	SetOrClearBit((unsigned int*) SYSTICK_CTRL, 1, SET_BIT);
}