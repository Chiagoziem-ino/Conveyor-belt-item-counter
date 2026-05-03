#ifndef GPIO_H
#define GPIO_H

#define PC0 0

#define PCICR_ENABLE_PIN_CHANGE_INTERRUPTS_ON_PCIE1 0x02
#define PCMSK1_ENABLE_PIN_CHANGE_INTERRUPT_ON_PCINT9 0x02 
#define PC1 1
#define PCIFR_PCIE1_INTERRUPT_FLAG 0x02

#define DISPLAY_MASK (unsigned char)0xFE 

#define DISPLAY_0 (unsigned char)0x7E
#define DISPLAY_1 (unsigned char)0x0C
#define DISPLAY_2 (unsigned char)0xB6
#define DISPLAY_3 (unsigned char)0x9E
#define DISPLAY_4 (unsigned char)0xCC
#define DISPLAY_5 (unsigned char)0xDA
#define DISPLAY_6 (unsigned char)0xFA
#define DISPLAY_7 (unsigned char)0x0E
#define DISPLAY_8 (unsigned char)0xFE
#define DISPLAY_9 (unsigned char)0xDE

void IoConfig(void);
void Display(unsigned char displayDigit);

#endif //GPIO_H