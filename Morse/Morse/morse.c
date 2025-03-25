#include "morse.h"
#include "tim.h"

send_dot(volatile uint8_t *port){
	static uint8_t cnt = 0;
	static volatile uint16_t lastTickDot1m = 0;
	lastTickDot1m = tim_dot;
	while(cnt < 2){
		if(TimeElapsed(tim_dot,lastTickDot1m,300)){
			cnt++;
			*port ^= 1<<3;
			lastTickDot1m = g_Tick1m;
		}
	}
	cnt = 0;
}

send_dash(volatile uint8_t *port){
	static uint8_t cnt = 0;
	static volatile uint16_t lastTickDash1m = 0;
	lastTickDash1m = tim_dash;
	while(cnt < 2){
		if(TimeElapsed(tim_dash,lastTickDash1m,900)){
			cnt++;
			*port ^= 1<<3;
			lastTickDash1m = tim_dash;
		}
	}
	cnt = 0;
}

// S : ...
send_S(volatile uint8_t *port){
	for(int i=0; i<3;i++){
		send_dot(port);
	}
}
// O: ---
send_O(volatile uint8_t *port){
	for(int i=0; i<3;i++){
		send_dash(port);
	}
}

// L: .-..
send_L(volatile uint8_t *port){
	send_dot(port);
	send_dash(port);
	for(int i=0; i<2;i++){
		send_dot(port);
	}
}
// A: .-
send_A(volatile uint8_t *port){
	send_dot(port);
	send_dash(port);
}
// N: -.
send_N(volatile uint8_t *port){
	send_dash(port);
	send_dot(port);
}