#define F_CPU 16000000UL //16MHZ

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "tim.h"

int main(void)
{
	uint8_t cnt = 0;
	PORTC = 0x00;
	DDRC = 0xFF;
	PORTB = 0x00;
	DDRB = 0xFF;
	PORTA = 0x00;
	DDRA = 0xFF;
	uint8_t LED = 0xff;
	init_timer0();
	while (1)
	{
		S_count = 0;
		while(cnt <= 5){
			if(S_count >= 500){
				cnt++;
				S_count = 0;
				PORTC ^= LED;
			}
		}
		cnt = 0;
		O_count = 0;
		while(cnt<=5){
			if(O_count >= 1000){
				cnt++;
				O_count = 0;
				PORTB ^= LED;
			}
		}
		cnt = 0;
		S_count = 0;
		while(cnt <= 5){
			if(S_count >= 500){
				cnt++;
				S_count = 0;
				PORTA ^= LED;
			}
		}		
		cnt = 0;
	}
}

