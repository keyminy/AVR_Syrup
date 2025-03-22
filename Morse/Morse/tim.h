/*
 * tim.h
 *
 * Created: 2025-03-06 오후 8:13:56
 *  Author: me
 */ 


#ifndef TIM_H_
#define TIM_H_
#include <avr/io.h>
#include <avr/interrupt.h>

void init_timer0(void);
uint8_t TimeElapsed(uint16_t currentTick1m, uint16_t lastTick1m, uint16_t delayTime);
extern volatile uint16_t tim_dot;
extern volatile uint16_t tim_dash;
extern volatile uint16_t tim_wait;
extern volatile uint16_t g_Tick1m;

#endif /* TIM_H_ */