//
//  sceneC.cpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//

#include "sceneC.hpp"

void sceneC::setup(){
    playerC.load("GoodGirls.mp3");
    playerC.setVolume(1.0);
    playerC.setMultiPlay(false);
    playerC.setLoop(true); //loop on by "true"
    //playerC.play();
    
    fftSmoothed= new float[NUM];
    for(int i =0; i<NUM; i++){
        fftSmoothed[i]=0;
    }
    nBandsToGet = 80;
}

void sceneC::update(){
    ofSetWindowTitle(to_string(ofGetFrameRate()));
    fftUpdate();
}

void sceneC::draw(){
    ofBackground(40,0,240);
    ofSetColor(218, 78, 109);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
    ofDrawBitmapString("sceneC", 20, 20);
    for (int i =0; i<nBandsToGet; i+=10) {
        ofNoFill();
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, fftSmoothed[i]*400+30);
        
    }
    drawDisc();
}
void sceneC::fftUpdate(){
    ofSoundUpdate();
    volume= ofSoundGetSpectrum(nBandsToGet);
    
    for (int i = 0; i<nBandsToGet; i++) {
        fftSmoothed[i]*=0.96f;
        if (fftSmoothed[i]<volume[i]) {
            fftSmoothed[i]=volume[i];
        }
    }
}
void sceneC::stopMusic(){
    playerC.stop();
     ofSoundStopAll();
}
void sceneC::startMusic(){
    playerC.play();
}
void sceneC ::drawDisc(){
    //draw lines for the disc
    ofSetColor(250, 250, 250);
    for (int i =2; i<10; i++) {
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, i*40);
    }
   // ofDrawBitmapString("sceneA", 20, 20);
    ofFill();
    ofSetColor(64, 182, 152);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 50);
    //draw the disc itself
    ofSetColor(0, 0, 0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2);
}

