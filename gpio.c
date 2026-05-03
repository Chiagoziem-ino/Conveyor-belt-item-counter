#include <avr/io.h> 
#include "gpio.h"

void IoConfig(void)
{
    /*initialize input pin and enable internal pull-up resistor*/
    DDRC &= ~(1U<<PC1);
    PORTC |= (1U<<PC1);

    /*configure buzzer pin as output*/
    DDRC |= (1U<<PC0);
    PORTC &= ~(1U<<PC0);

    /*configure display output*/
    DDRD |= DISPLAY_MASK;
    //display zero
    PORTD &= ~DISPLAY_MASK; 
    PORTD |= DISPLAY_0;

    /*configure pin change interrupts on PCINT9 (PC1)*/
    PCICR |= PCICR_ENABLE_PIN_CHANGE_INTERRUPTS_ON_PCIE1;
    PCMSK1 |= PCMSK1_ENABLE_PIN_CHANGE_INTERRUPT_ON_PCINT9;
    //clear any pendng interrupt on PCIE1 
    PCIFR |= PCIFR_PCIE1_INTERRUPT_FLAG;

}

void Display(unsigned char displayDigit)
{
    switch (displayDigit) 
  {
    case 0: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_0;
    }
    break;
    
    case 1: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_1;
    }
    break;
    
    case 2: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_2;
    }
    break;
    
    case 3: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_3;
    }
    break;
    
    case 4: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_4;
    }
    break;
    
    case 5: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_5;
    }
    break;
    
    case 6: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_6;
    }
    break;
    
    case 7: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_7;
    }
    break;
    
    case 8: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_8;
    }
    break;
    
    case 9: 
    {
            //clear all outputs
            PORTD &= ~DISPLAY_MASK;
            //update pattern 
            PORTD |= DISPLAY_9;
    }
    break;

    default: 
    break;
  }

}
