#include <iostream>
#include <stdio.h>

#include <AL/alut.h>

#include "audio_master.h"

int main(int argc, char **argv){
	AudioMaster am;	
	
	am.init();
	am.setListenerData(0.0f, 0.0f, 0.0f);

	int buffer = am.loadSound("horn.wav");
	int source = am.createSource();

	am.setSourceLooping(source, true);	
	am.playSound(source, buffer);	

	float x = 8.0f;
	am.setSourcePosition(source, x, 0.0f, 2.0f);
	am.setSourceVelocity(source, x, 0.0f, 2.0f);
	char c = ' ';
	while(c != 'q'){
		x -= 0.3f;
		am.setSourcePosition(source, 0.0, 0.0f, x);
		alutSleep(0.1);
	}
	
	am.cleanUp();
	return 0;
}


