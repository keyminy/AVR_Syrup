#include "morse.h"
#include "tim.h"

send_dot(volatile uint8_t *port){
	static uint8_t cnt = 0;
	static uint16_t lastTickDot1m = 0;
	lastTickDot1m = tim_dot;
	while(cnt < 2){
		if(TimeElapsed(tim_dot,lastTickDot1m,100)){
			cnt++;
			*port ^= 1<<3;
			lastTickDot1m = g_Tick1m;
		}
	}
	cnt = 0;
}

send_dash(volatile uint8_t *port){
	static uint8_t cnt = 0;
	static uint16_t lastTickDash1m = 0;
	lastTickDash1m = tim_dash;
	while(cnt < 2){
		if(TimeElapsed(tim_dash,lastTickDash1m,300)){
			cnt++;
			*port ^= 1<<3;
			lastTickDash1m = tim_dash;
		}
	}
	cnt = 0;
}

send_S(volatile uint8_t *port){
	for(int i=0; i<3;i++){
		send_dot(port);
	}
}

send_O(volatile uint8_t *port){
	for(int i=0; i<3;i++){
		send_dash(port);
	}
}