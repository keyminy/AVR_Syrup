#include "tim_ctc.h"

volatile uint16_t ms_10 = 0;

void init_CTC_timer(void){
	//8bit timer, timer 0번과 2번 사용한다.	
	TCCR0 |= 1<<WGM01 | 1<<CS02 | 1<<CS01 | 1 << CS00; // WGM01,WGM00 : 10이 CTC모드 , 1024분주
	TIMSK |= 1 << OCIE0; // 비교일치 interrupt허용,없어도 프로그램 문제없네
	TIFR |= 1<<OCF0; // output compare match시 interrupt프로그램 실행하라
	OCR0 = 157;
	sei();
}

//CTC모드에서 OCR0=157넣으면 0.01초 마다 이 프로그램 실행
ISR(TIMER0_COMP_vect){
	ms_10++;
}