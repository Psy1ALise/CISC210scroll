#include "sense.h"
#include "scroll.h"
#include <linux/input.h>
#include <stdio.h>

pi_joystick_t *joystick = NULL;

void openJoystick(void){
	if(joystick==NULL) { 
		joystick=getJoystickDevice();
	}
}

void closeJoystick(void){
	if(joystick) {
		freeJoystick(joystick);
		joystick=NULL;
	}
}

void checkJoystick(void (*callback)(unsigned int code), int delay){
	pollJoystick(joystick,callback,delay);
}
