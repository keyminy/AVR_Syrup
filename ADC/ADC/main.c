#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include "uart0.h"

FILE OUTPUT = FDEV_SETUP_STREAM(UART0_transmit,NULL, _FDEV_SETUP_WRITE);


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
	ADCSRA |= 1<<ADEN | 1 << ADPS0 | 1 << ADPS1 | 1<< ADPS2;
	
	unsigned int Buf = 0; // AD변환할 데이터
		sei(); // 전역적으로 인터럽트를 허용하겠다
    while (1) 
    {
		ADCSRA |= 1 << ADSC; // Single Conversion의 경우 ADSC가 1이여야 변환 시작함.
		while(ADCSRA & (1<<ADSC)); // ADCSRA의 ADSC는 변환이 끝나면 0으로 리턴됨
		Buf = (unsigned int)(ADCL | (ADCH<<8));
		printf("%d\n",Buf);
		_delay_ms(1000);
    }
}

