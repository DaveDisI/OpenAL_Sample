all: source
	g++ -std=c++11 main.cpp *.o -lopenal -lalut

source:
	g++ -std=c++11 -c audio_master.cpp
