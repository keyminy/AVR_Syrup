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
extern volatile uint16_t S_count;
extern volatile uint16_t O_count;
extern volatile uint16_t S2_count;
extern volatile uint16_t morse_count;

#endif /* TIM_H_ */