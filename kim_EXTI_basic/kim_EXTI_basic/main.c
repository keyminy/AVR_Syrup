/*
 * kim_EXTI_basic.c
 *
 * Created: 2025-03-09 오후 3:57:33
 * Author : me
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect){
	// TODO
	PORTC ^= (1<<0); // toggle LED0 pin
}

void Init_PORT(void){
	DDRC = 0xFF;	
}

void Init_INT0(void){
	EIMSK |= 1<<INT0;
	EICRA |= ISC01<<0 | ISC00<<0;
	sei();
}

int main(void)
{
	Init_INT0();
	Init_PORT();
    /* Replace with your application code */
    while (1) 
    {
    }
}

