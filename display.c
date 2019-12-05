#include "scroll.h"
#include <stddef.h>
#include <stdio.h>
#include "sense.h"

#define BLACK 0x0000
#define WHITE 0xFFFF
pi_framebuffer_t *fb = NULL;

void openDisplay(void){
	if(fb==NULL) { 
		fb=getFrameBuffer();
	}
}

void closeDisplay(void){
	if(fb) {
		clearFrameBuffer(fb,BLACK);
		freeFrameBuffer(fb);
		fb=NULL;
	}
}

void displayLetter(char letter, int xOffset, int yOffset) {
	if(fb == NULL) {
		fprintf(stderr,"Tried to draw (%d,%d) to a non-existent frame buffer!\n",xOffset,yOffset);
		return;
	}
	sense_fb_bitmap_t *bm=fb->bitmap;
	clearFrameBuffer(fb,BLACK);

	xOffset=(xOffset%8+8)%8;
	yOffset=(yOffset%8+8)%8;

	if(letter == 'Y'){
		bm->pixel[(1+yOffset)%8][(1+xOffset)%8]=WHITE;
		bm->pixel[(1+yOffset)%8][(2+xOffset)%8]=WHITE;
		bm->pixel[(1+yOffset)%8][(3+xOffset)%8]=WHITE;
		bm->pixel[(2+yOffset)%8][(4+xOffset)%8]=WHITE;
		bm->pixel[(3+yOffset)%8][(5+xOffset)%8]=WHITE;
		bm->pixel[(3+yOffset)%8][(6+xOffset)%8]=WHITE;
		bm->pixel[(3+yOffset)%8][(7+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(1+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(2+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(3+xOffset)%8]=WHITE;
		bm->pixel[(5+yOffset)%8][(4+xOffset)%8]=WHITE;
		bm->pixel[(4+yOffset)%8][(5+xOffset)%8]=WHITE;
		bm->pixel[(4+yOffset)%8][(6+xOffset)%8]=WHITE;
		bm->pixel[(4+yOffset)%8][(7+xOffset)%8]=WHITE;
	}

	else if(letter == 'N'){
		bm->pixel[(1+yOffset)%8][(1+xOffset)%8]=WHITE;
		bm->pixel[(1+yOffset)%8][(2+xOffset)%8]=WHITE;
		bm->pixel[(1+yOffset)%8][(3+xOffset)%8]=WHITE;
		bm->pixel[(1+yOffset)%8][(4+xOffset)%8]=WHITE;
		bm->pixel[(1+yOffset)%8][(5+xOffset)%8]=WHITE;
		bm->pixel[(1+yOffset)%8][(6+xOffset)%8]=WHITE;
		bm->pixel[(1+yOffset)%8][(7+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(1+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(2+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(3+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(4+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(5+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(6+xOffset)%8]=WHITE;
		bm->pixel[(6+yOffset)%8][(7+xOffset)%8]=WHITE;
		bm->pixel[(5+yOffset)%8][(2+xOffset)%8]=WHITE;
		bm->pixel[(5+yOffset)%8][(3+xOffset)%8]=WHITE;
		bm->pixel[(4+yOffset)%8][(3+xOffset)%8]=WHITE;
		bm->pixel[(4+yOffset)%8][(4+xOffset)%8]=WHITE;
		bm->pixel[(3+yOffset)%8][(4+xOffset)%8]=WHITE;
		bm->pixel[(3+yOffset)%8][(5+xOffset)%8]=WHITE;
		bm->pixel[(2+yOffset)%8][(5+xOffset)%8]=WHITE;
		bm->pixel[(2+yOffset)%8][(6+xOffset)%8]=WHITE;
	}
}

void clearDisplay(void){
	if(fb) {
		clearFrameBuffer(fb,BLACK);
	}
}


