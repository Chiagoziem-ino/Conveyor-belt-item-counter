#include <avr/io.h> 
#include "timer.h"

void TimerConfig(void)
{
    TCCR1A = TCCR1A_NORMAL_MODE_NO_OUTPUT_WAVEFORM;
    TCCR1B = 0; 
    TCCR1C = 0;

    //clear any pending overflow interrupts
    TIFR1 |= TIFR1_TIMER1_OVERFLOW_FLAG;

}