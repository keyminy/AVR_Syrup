#define F_CPU 16000000UL //16MHZ

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "tim_ctc.h"

#define TRUE 1
#define De(x) _delay_ms(x)

int main(void)
{
	PORTC =0x00;
	DDRC = 0xFF;
	uint8_t LED = 0xff;
	init_CTC_timer();
	while (1)
	{
		if(ms_10 >= 100){
			ms_10 = 0;
			PORTC ^= LED;
		}
	}
}