#define SET_BIT 1
#define CLEAR_BIT 0

#define PCC_PORTD (0x40065000u + 0x130u) //PORTD PIN 15
#define PORT_PCR15 (0x4004C000u + 0x3Cu)
#define GPIOD_PDDR (0x400FF0C0u + 0x14u)
#define GPIOD_PDOR (0x400FF0C0u + 0x0u)

#define PCC_PORTC (0x40065000u + 0x12Cu) //PORTC PIN 13 
#define PORT_PCR13 (0x4004B000u + 0x34u)
#define GPIOC_PDDR (0x400FF080u + 0x14u)
#define GPIOC_PDIR (0x400FF080u + 0x10u)

#define SYSTICK_CTRL (0xE000E010)
#define SYSTICK_LOAD (0xE000E014)
#define SYSTICK_VAL (0xE000E018)

void SetOrClearBit(unsigned int *address, unsigned char position, unsigned char action);
void SetOrClearMultiBit(unsigned int *address, unsigned char position, unsigned int mask, unsigned char action);
void LEDConfig (void);
void delay(void);
void LEDToggle (void);
void SW3Config (void);
void SW3Toggle (void);
void SysTick(void);