#include <avr/interrupt.h> 
#include "gpio.h"
#include "timer.h"

volatile unsigned char g_itemCounter = 0;
volatile unsigned char g_interruptReady = 0;

int main (void)
{
    //disable global interrupts 
    cli();

    //configure input and output 
    IoConfig();

    //configure timer1 block for buzzer timing
    TimerConfig();

    //enable global interrupts
    sei();


    while (1)
    {
        if (g_interruptReady)
        {
            //display item count
            Display(g_itemCounter);

            //reset interrupt-ready flag
            g_interruptReady = 0;
        }
        
    }
}

//ISR to run upon falling edge of PC1
ISR(PCINT1_vect)
{
  if (!(PINC & (1U<<PC1)))
  {
    //increment item counter
    g_itemCounter++;

    //keep g_itemCounter below 10
    g_itemCounter %= 10;

    //set interrupt-ready flag
    g_interruptReady = 1;

    /*beep buzzer briefly*/
    PORTC |= (1U<<PC0);

    //start counter
    TCCR1B = TCCR1B_NORMAL_MODE_PRESCALER_8;
    //wait for overflow
    while (!(TIFR1 & TIFR1_TIMER1_OVERFLOW_FLAG)) {}
    //clear overflow flag
    TIFR1 |= TIFR1_TIMER1_OVERFLOW_FLAG;
    //stop counter 
    TCCR1B = 0;

    PORTC &= ~(1U<<PC0);
  }

}

