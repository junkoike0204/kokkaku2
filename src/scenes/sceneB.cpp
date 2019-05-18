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
    cam.begin();
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 200);
//    ofRotateDeg(ofGetElapsedTimeMillis());
    cam.setPosition(300*sin(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)), 1000, 1500*cos(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)));
    ofBackground(0,200,40);
    ofSetColor(247, 242, 215);
    ofVec3f disc(100,200,300);
    cam.lookAt(disc);
    ofDrawBitmapString("sceneB", 20, 20);
    ofDrawCircle(disc,100);
    ofSetColor(250, 0, 0);
    ofNoFill();
    for (int i =0; i<nBandsToGet; i+=10) {
        ofDrawCircle(100,200,300, fftSmoothed[i]*400+30);
        
    }
    ofPushMatrix();
   ofTranslate(100,200,300);
    ofRotateYDeg(50*ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI));
    for (int i =0; i<nBandsToGet; i+=10) {
        ofDrawCircle(0,0,0, fftSmoothed[i]*400+30);
        
    }
  //  ofRotateYDeg(180+50*ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI));
    ofRotateXDeg(90);
    for (int i =0; i<nBandsToGet; i+=10) {
        ofDrawCircle(0,0,0, fftSmoothed[i]*400+30);
        
    }
    ofPopMatrix();
    drawDisc();
//    ofPopMatrix();
    
    cam.end();
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
        ofDrawCircle(100,200,300, i*40);
    }
    
    ofFill();
    ofSetColor(64, 182, 152);
    ofDrawCircle(100,200,300, 50);
    //draw the disc itself
    ofSetColor(0, 0, 0);
    ofDrawCircle(100,200,300, ofGetHeight()/2);
}
