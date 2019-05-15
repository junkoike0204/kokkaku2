//
//  sceneB.cpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//
#include "sceneB.hpp"
//-----------------------------------------------------------------------------------------------------
void sceneB::setup(){
    
    ofSetVerticalSync(true);
    playerB.load("Wannabe.mp3");
    playerB.setVolume(1.0);
    playerB.setMultiPlay(false);
    playerB.setLoop(true); //loop on by "true"
    
    fftSmoothed = new float[NUM];
    for(int i =0; i<NUM; i++){
        fftSmoothed[i]=0;
    }
    nBandsToGet = 80;
}
    
//-----------------------------------------------------------------------------------------------------
void sceneB::update(){
ofSetWindowTitle(to_string(ofGetFrameRate()));//window上側にフレーム数を表示
    fftUpdate();
    
}
//-----------------------------------------------------------------------------------------------------
void sceneB::draw(){
    ofBackground(0,200,40);
    ofSetColor(247, 242, 215);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
    ofDrawBitmapString("sceneB", 20, 20);
    ofSetColor(250, 0, 0);
    ofNoFill();
    for (int i =0; i<nBandsToGet; i+=10) {
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, fftSmoothed[i]*400+30);
        
    }
    drawDisc();
}
//-----------------------------------------------------------------------------------------------------
void sceneB::fftUpdate(){
    ofSoundUpdate();
    volume= ofSoundGetSpectrum(nBandsToGet);
//
    for (int i = 0; i<nBandsToGet; i++) {
        fftSmoothed[i]*=0.96f;
        if (fftSmoothed[i]<volume[i]) {
            fftSmoothed[i]=volume[i];
        }
    }
}
//-----------------------------------------------------------------------------------------------------
void sceneB::stopMusic(){
    playerB.stop();
     ofSoundStopAll();
}
//-----------------------------------------------------------------------------------------------------
void sceneB::startMusic(){
    playerB.play();
}

void sceneB::drawDisc(){
    //draw lines for the disc
    ofSetColor(250, 250, 250);
    for (int i =2; i<10; i++) {
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, i*40);
    }
    ofDrawBitmapString("sceneA", 20, 20);
    ofFill();
    ofSetColor(64, 182, 152);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 50);
    //draw the disc itself
    ofSetColor(0, 0, 0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2);
}
