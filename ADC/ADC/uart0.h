/*
 * uart0.h
 *
 * Created: 2025-03-25 오후 8:09:36
 *  Author: me
 */ 


#ifndef UART0_H_
#define UART0_H_
#include <avr/io.h>

void UART0_init(void);
void UART0_transmit(uint8_t data);
unsigned char UART0_receive();



#endif /* UART0_H_ */