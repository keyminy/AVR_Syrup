#define F_CPU 16000000UL //16MHZ

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "tim.h"
#include "morse.h"

int main(void)
{
	PORTC = 0x00;
	DDRC = 0xFF;
	PORTB = 0x00;
	DDRB = 0xFF;
	PORTA = 0x00;
	DDRA = 0xFF;
	DDRE = 0xFF;
	PORTE = 0x00;
	
	uint16_t lastTick1m = 0;
	
	init_timer0();
	
	while (1)
	{
		send_S(&PORTA);
		send_O(&PORTC);
		send_S(&PORTE);

		lastTick1m = tim_wait;  // 현재 시간 저장
		while(!(TimeElapsed(tim_wait,lastTick1m,1000)));
	}
}
