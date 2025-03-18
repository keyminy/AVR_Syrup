/*
 * tim_ctc.h
 *
 * Created: 2025-03-18 오후 8:52:37
 *  Author: me
 */ 


#ifndef TIM_CTC_H_
#define TIM_CTC_H_
#include <avr/io.h>
#include <avr/interrupt.h>

void init_CTC_timer(void);
extern volatile uint16_t ms_10;

#endif /* TIM_CTC_H_ */