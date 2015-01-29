#pragma once
#include "ofMain.h"
#include "oscillator.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
        void audioOut(float * input, int bufferSize, int nChannels);
        ofSoundStream stream;
    
        float tempo, amplitude;
        float phaseSaw, phaseTriangle, phaseReverseSaw;
        oscillator sawWave, triangleWave, reverseSawWave;
};
