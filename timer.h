#ifndef TIMER_H
#define TIMER_H

#define TCCR1B_NORMAL_MODE_PRESCALER_8 0x02
#define TCCR1A_NORMAL_MODE_NO_OUTPUT_WAVEFORM 0
#define TIFR1_TIMER1_OVERFLOW_FLAG 0x01

void TimerConfig(void);

#endif //TIMER_H