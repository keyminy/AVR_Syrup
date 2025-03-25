#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "uart0.h"

FILE OUTPUT = FDEV_SETUP_STREAM(UART0_transmit,NULL, _FDEV_SETUP_WRITE);

ISR(ADC_vect){
	// ADSC가 0일때 ISR루틴 실행(conversion이 다 끝날때)
	unsigned int Buf=(unsigned int)(ADCL | (ADCH<<8));
	printf("%d\n",Buf);
	_delay_ms(500);
	//인터럽트가 끝날 때, 다시 ADSC를 1로 set해야함(변환을 다시 시작하겠다)
	ADCSRA |= 1<<ADSC;
}

int main(void)
{
	  UART0_init();
	  stdout = &OUTPUT;
	  
	  // REFS[1:0] : Voltage Reference Selection -> Avcc
	  // ADLAR=0(right side adjustment)
	  // MUX[4:0] 00101 -> F5
	  ADMUX |= 0<<REFS1 | 1<<REFS0 
			   | 0 << ADLAR |  1 << MUX0 | 1<<MUX2;
			   
	// ADEN : ADC동작을 허용
	// 단일모드 ADC변환을 한 번만 수행(ADFR = 0)
	// ADC Prescaler Selections : 128분주
	ADCSRA |= 1<<ADEN | 1<<ADIE
	          | 1 << ADPS0 | 1 << ADPS1 | 1<< ADPS2;
	sei(); // 전역적으로 인터럽트를 허용하겠다
	
	// 처음에는 AD변환 하도록 신호 보내야됨.
	ADCSRA |= 1<<ADSC;
    while (1) 
    {
    }
}