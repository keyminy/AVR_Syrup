#define F_CPU 16000000UL //16MHZ

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "tim.h"

#define TRUE 1
#define De(x) _delay_ms(x)

int main(void)
{
	DDRC = 0xFF;
	uint8_t LED;
	init_timer0();
	LED = 0x01;
    while (1) 
    {
		if(ms_count >= 200){
			ms_count = 0;
			PORTC = LED;
			LED <<= 1;
			if(LED == 0x00)
				LED = 0x01;
	    }
	}
}

