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
    
    for(int i = 0; i<boxNUM; i++){
//        box[i].setPosition(ofRandom(300)*sin(ofRandom(0, 360)),0,ofRandom(300)*cos(ofRandom(0, 360)));
        box[i].setPosition(ofRandom(1,4)*100*cos(ofMap(10*(i%36),0,360,0,2*PI)),0,
                           ofRandom(1,4)*100*sin(ofMap(10*(i%36),0,360,0,2*PI)));
       
                                             }
    ofSetFrameRate(30);
}

void sceneC::update(){
    ofSetWindowTitle(to_string(ofGetFrameRate()));
    fftUpdate();
}

void sceneC::draw(){
    cam.begin();
    ofVec3f campoint(0,0,0);
    cam.lookAt(campoint);
//    cam.setPosition(2000*sin(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)), 700, 2000*sin(2*ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)));
      cam.setPosition(2000*sin(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)), 700, 2000*cos(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)));
    ofBackground(40,0,240);
    ofSetColor(218, 78, 109);
//    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
//    ofDrawBitmapString("sceneC", 20, 20);
//    for (int i =0; i<nBandsToGet; i+=10) {
//        ofNoFill();
//        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, fftSmoothed[i]*400+30);
    
//    }
    //drawDisc();

    for (int i =0; i<boxNUM; i++) {
        box[i].set(volume[i]*100);
        if(volume[i]<0.5)
        box[i].draw();
    }
    ofSetColor(0);
    ofPushMatrix();
    ofRotateXDeg(90);
    ofDrawCircle(0,0,0, 400);
    ofPopMatrix();
    cam.end();
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

