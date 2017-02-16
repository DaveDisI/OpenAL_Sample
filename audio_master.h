#pragma once

#include <cstddef>
#include <string>
#include <AL/alut.h>

const unsigned int MAX_BUFFERS = 256;
const unsigned int MAX_SOURCES = 256;

struct Source{
	ALuint sourceID;
	float gain;
	float pitch;
	float position[3];
	float velocity[3];
	bool looping;
};

class AudioMaster{
public:
	AudioMaster();
	~AudioMaster();
		
	void init();
	void cleanUp();
	void setListenerData(float x, float y, float z);

	void playSound(ALuint sourceID, ALuint bufferID);

	inline void setSourceGain(ALuint id, float gain){ 
		sources[id].gain = gain; alSourcef(id, AL_GAIN, gain); 
	}
	inline void setSourcePitch(ALuint id, float pitch){ 
		sources[id].pitch = pitch; alSourcef(id, AL_PITCH, pitch);
	}
	inline void setSourcePosition(ALuint id, float x, float y, float z){
		sources[id].position[0] = x; sources[id].position[1] = y; sources[id].position[2] = z;
		alSource3f(id, AL_POSITION, x, y, z);
	}
	inline void setSourceVelocity(ALuint id, float x, float y, float z){
		sources[id].velocity[0] = x; sources[id].velocity[1] = y; sources[id].velocity[2] = z;
		alSource3f(id, AL_VELOCITY, x, y, z);
	}
	inline void setSourceLooping(ALuint id, bool loop){
		sources[id].looping = loop; alSourcei(id, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
	}
	inline void pauseSource(int id){
		alSourcePause(id);
	}
	inline void continueSource(int id){
		alSourcePlay(id);
	}
	inline void stopSource(int id){
		alSourceStop(id);
	}
	inline bool isSourcePlaying(int id){
		int playing; alGetSourcei(id, AL_SOURCE_STATE, &playing);
		return playing;
	}

	int loadSound(std::string file);
	int createSource();
	
private:
	ALuint buffers[MAX_BUFFERS];
	unsigned int totalBuffers;

	Source sources[MAX_SOURCES];
	unsigned int totalSources;
};
