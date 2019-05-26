//
//  sceneB.cpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//レコードプレーヤーから少し崩して、いろんな方向から回転してみる、楽しさあるクラス。
//緑が鮮やか
//song: what you got
#include "sceneB.hpp"
//-----------------------------------------------------------------------------------------------------
void sceneB::setup(){
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    playerB.load("WhatYouGot.mp3");
    playerB.setVolume(0.2);
    playerB.setMultiPlay(false);
    playerB.setLoop(true); //loop on by "true"
    
    fftSmoothed = new float[NUM];
    for(int i =0; i<NUM; i++){
        fftSmoothed[i]=0;
    }
    nBandsToGet = 80;
    //tips 参考
}
    
//-----------------------------------------------------------------------------------------------------
void sceneB::update(){
ofSetWindowTitle(to_string(ofGetFrameRate()));//window上側にフレーム数を表示
    fftUpdate();
    
}
//-----------------------------------------------------------------------------------------------------
void sceneB::draw(){
     ofDrawBitmapString("sceneB", 20, 20);
    cam.begin();
    cam.setPosition(300*sin(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)), 1000, 1500*cos(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)));
    ofBackground(0,200,40);
    ofSetColor(247, 242, 215);
    ofVec3f disc(100,200,300);
    cam.lookAt(disc);
  
    ofDrawCircle(disc,100);
    ofSetColor(250);
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
//        if (i<30)
//            ofSetColor(250, 0, 0);
//        else
            ofSetColor(250);
        ofDrawCircle(0,0,0, fftSmoothed[i]*400+30);
    }
    ofPopMatrix();
    drawDisc();
    
    cam.end();
     ofDrawBitmapString("What you got /Tofubeats", 20, 20);
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

void sceneB::pauseMusic(){
    //ポーズするか否かを切り替えるスイッチを動かす
    playerB.setPaused(pause);
    if(pause == true)
        pause = false;
    else
        pause = true;
    //切り替えの結果を適用する
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
void sceneB::volumeUp(){
    playerB.play();
}
void sceneB::volumeDown(){
    playerB.play();
}
