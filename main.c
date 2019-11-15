#include "sense.h"
#include "scroll.h"
#include <linux/input.h>
#include <stdio.h>

int xOffset = 0, yOffset = 0;
int running=8;

void handler(unsigned int code) {
	printf("code: %u\t",code);
	if(code == KEY_UP) {
		printf("up");
		yOffset--;
	}else if(code == KEY_DOWN) {
		printf("down");
		yOffset++;
	}else if(code == KEY_RIGHT) {
		printf("right");
		xOffset++;
	}else if(code == KEY_LEFT) {
		printf("left");
		xOffset--;
	}else if(code == KEY_ENTER) {
		printf("push");
		running--;
		printf("\n");
	}
}

int main(void){
	float x=0,y=0;
	char ini[] ="ZXAWJZYN";
	
	openJoystick();
	openDisplay();

	while(running){
		checkJoystick(handler,10);
		x = x+((float)xOffset)/100.0;
		y = y+((float)yOffset)/100.0;
		char letter = ini[8-running];
		displayLetter(letter,x,y);
	}
	printf("Looks like 'running' is zero!\n");
	closeDisplay();
	closeJoystick();
}

