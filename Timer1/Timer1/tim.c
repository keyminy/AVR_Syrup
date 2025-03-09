/*
 * tim.c
 *
 * Created: 2025-03-06 오후 8:13:37
 *  Author: me
 */ 
#include "tim.h"

volatile uint16_t ms_count = 0;

void init_timer0(void){
	//8bit timer, timer 0번과 2번 사용한다.
	//분주비를 64로 설정한다.
	// 1.분주비 계산
	// 16000000Hz/64 = 250,000Hz
	
	// 2.T(주기) : pulse 1개가 잡아 먹는 시간(주파수의 역수 : 1/f)
	// 1 / 250,000 = 0.000004sec(=4us,0.004ms)
	// 3. 8bit timer overflow : 0.004ms * 256개 카운트 = 0.001024sec = 1.024ms
	// 1ms가 정확히 안되자너... 1ms가 정확히 될려면 어떻게 해야하나?
	// 0.004ms * 250 = 0.001(=1ms)
	
	// 타이머의 각 레지스터들을 초기화한다.
	// 모드를 결정한다(일반모드)
	// 16M/64 = 250,000, 주기는 4us
	TCNT0 = 6; // 6부터 count하는것임, TCNT : 0~256카운트하기때문에, 정확히 1ms마다 TIMER0_OVF_vect로 진입한다.
	TCCR0 |= 1<<CS02 | 0<<CS01 | 0 << CS00; // 64분주
	TIMSK |= 1 << TOIE0; // (2) TIMER0 overflow interrupt허용
	sei(); 
}

// 1ms마다 이 함수가 실행된다.
ISR(TIMER0_OVF_vect){
	/* 인터럽트 루틴을 가능한 짧게 짜라, ms_count만 증가시키고 빠져나오게함 */
	TCNT0=6; // 다시 6부터 세야죠..! 6 ~ 256개의 pulse카운트 --> 1ms를 맞춰주기 위해서 TCNT0을 6으로 설정
	ms_count++;
	//ms_count delay없애는 작업
}