#define F_CPU 16000000UL //16MHZ

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "tim.h"

send_mos(volatile uint8_t *port,volatile uint16_t *tCnt, uint16_t delay_ms);

int main(void)
{
	PORTC = 0x00;
	DDRC = 0xFF;
	PORTB = 0x00;
	DDRB = 0xFF;
	PORTA = 0x00;
	DDRA = 0xFF;

	init_timer0();
	while (1)
	{
		send_mos(&PORTC,&S_count,500);
		send_mos(&PORTB,&O_count,1000);
		send_mos(&PORTA,&S_count,500);
	}
}

send_mos(volatile uint8_t *port,volatile uint16_t *tCnt, uint16_t delay_ms){
	static uint8_t cnt = 0;
	uint8_t LED = 0xff;
	*tCnt = 0;
	while(cnt <= 5){
		if(*tCnt >= delay_ms){
			cnt++;
			*tCnt = 0;
			*port ^= LED;
		}
	}
	cnt = 0;
}