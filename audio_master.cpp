#include "audio_master.h"

AudioMaster::AudioMaster(){
	totalBuffers = 0;
	totalSources = 0;
}

AudioMaster::~AudioMaster(){

}

void AudioMaster::init(){
	alutInit(0, NULL);
}

void AudioMaster::cleanUp(){
	for(int i = 0; i < totalSources; i++){
		stopSource(sources[i].sourceID);
		alDeleteSources(1, &sources[i].sourceID);
	}

	alutExit();
}	

void AudioMaster::setListenerData(float x, float y, float z){
	alListener3f(AL_POSITION, x, y, z);
	alListener3f(AL_VELOCITY, 0.0f, 0.0f, 0.0f);
}

int AudioMaster::loadSound(std::string file){
	buffers[totalBuffers] = alutCreateBufferFromFile(file.c_str());
	totalBuffers++;
	return buffers[totalBuffers - 1];
}

int AudioMaster::createSource(){
	alGenSources(1, &sources[totalSources].sourceID);
	totalSources++;
	return sources[totalSources - 1].sourceID;
}

void AudioMaster::playSound(ALuint sourceID, ALuint bufferID){
	stopSource(sourceID);
	alSourcei(sourceID, AL_BUFFER, bufferID);
	alSourcePlay(sourceID);
}

