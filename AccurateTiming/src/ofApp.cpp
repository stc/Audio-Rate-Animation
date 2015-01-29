#include "ofApp.h"

void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(ofColor::white);
    
    stream.setup(this, 2, 0, 44100, 512, 4);
    
    tempo = 0.5;    //  sequencing tempo in Hz
    amplitude = 1;  //  sequencing range (0 - maximum range)
    
    sawWave.setup(44100);
    sawWave.setFrequency(tempo);
    sawWave.setVolume(amplitude);
    sawWave.type = 3;   //  sawtooth
    
    reverseSawWave.setup(44100);
    reverseSawWave.setFrequency(tempo);
    reverseSawWave.setVolume(amplitude);
    reverseSawWave.type = 4;   //  reverse sawtooth
    
    triangleWave.setup(44100);
    triangleWave.setFrequency(tempo);
    triangleWave.setVolume(amplitude);
    triangleWave.type = 2;   //  triangle
}

void ofApp::update(){
    amplitude = ofMap(mouseX,0,ofGetWidth(),0,1);
    tempo = ofMap(mouseY,0,ofGetHeight(),0,10);
    
    sawWave.setFrequency(tempo);
    sawWave.setVolume(amplitude);
    
    reverseSawWave.setFrequency(tempo);
    reverseSawWave.setVolume(amplitude);
    
    triangleWave.setFrequency(tempo);
    triangleWave.setVolume(amplitude);
}

void ofApp::draw(){
    ofSetColor(ofColor::black);
    ofLine(phaseSaw * ofGetWidth(), 0, phaseSaw * ofGetWidth(), ofGetHeight()/ 3);
    ofLine(phaseReverseSaw * ofGetWidth(), ofGetHeight() / 3, phaseReverseSaw * ofGetWidth(), ofGetHeight()- ofGetHeight() / 3);
    ofLine(phaseTriangle * ofGetWidth(), ofGetHeight() - ofGetHeight() / 3, phaseTriangle * ofGetWidth(), ofGetHeight());
    
    ofDrawBitmapString("Saw Tooth", 20, 20);
    ofDrawBitmapString("Reverse Saw Tooth", 20, ofGetHeight() / 3 + 20);
    ofDrawBitmapString("Triangle", 20, ofGetHeight() - ofGetHeight() / 3 + 20);
    
    ofSetColor(ofColor::aliceBlue);
    ofLine(0, ofGetHeight() / 3, ofGetWidth(), ofGetHeight() / 3);
    ofLine(0, ofGetHeight() - ofGetHeight() / 3, ofGetWidth(), ofGetHeight() - ofGetHeight() / 3);
    
    ofSetColor(ofColor::lavender);
    ofLine(mouseX,0,mouseX,ofGetHeight());
    ofLine(0,mouseY,ofGetWidth(),mouseY);
    ofSetColor(ofColor::grey);
    ofDrawBitmapString("Frequency: " + ofToString(tempo) + "\nAmplitude: " + ofToString(amplitude), mouseX + 20, mouseY + 20);
    
}

void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    for (int i = 0; i < bufferSize; i++){
        phaseSaw = sawWave.getSample();
        phaseReverseSaw = reverseSawWave.getSample();
        phaseTriangle = triangleWave.getSample();
    }
}

