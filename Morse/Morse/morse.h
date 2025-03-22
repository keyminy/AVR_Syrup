/*
 * morse.h
 *
 * Created: 2025-03-22 오후 1:13:13
 *  Author: me
 */ 


#ifndef MORSE_H_
#define MORSE_H_
#include <avr/io.h>

send_dot(volatile uint8_t *port);
send_dash(volatile uint8_t *port);
send_S(volatile uint8_t *port);
send_O(volatile uint8_t *port);

#endif /* MORSE_H_ */