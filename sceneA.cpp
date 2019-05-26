//
//  sceneA.cpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//レコードプレーヤーを平面的に再現したクラス
//song:Was he slow?

#include "sceneA.hpp"
void sceneA::setup(){
    ofSetVerticalSync(true);
    playerA.load("WasHeSlow.mp3");
    playerA.setVolume(0.4);
    playerA.setMultiPlay(false);
    playerA.setLoop(true); //loop on by "true"
    ofSetCircleResolution(50);
    onoff = true;
   if (onoff==true)
       playerA.play();
    else
        playerA.unload();
    
    
    fftSmoothed= new float[NUM];
    for(int i =0; i<NUM; i++){
        fftSmoothed[i]=0;
    }
    nBandsToGet = 80;
}

void sceneA::update(){
    if (onoff==false)
            playerA.stop();
    
    fftUpdate();
    ofSetWindowTitle(to_string(ofGetFrameRate()));
}

void sceneA::draw(){
//    ofPushMatrix();
//          ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//      ofRotateDeg(0.1*ofGetFrameRate());
//    ofPopMatrix();
  
    ofSetCircleResolution(60);
    ofBackground(64,182,153);
    ofFill();
   
    ofNoFill();
    ofSetColor(250, 250, 250);
//    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, fftSmoothed[20]*400);
    //ofSetColor(250,250,250);
//
//    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, fftSmoothed[40]*400+20);
//      ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, fftSmoothed[70]*400+30);
  //  ofRotateDeg(ofGetSeconds()*6);
    
    ///react with volume
    for (int i =0; i<nBandsToGet; i+=8) {
        ofSetColor(250,0,0);
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, fftSmoothed[i]*300+70);
    }
    
    
    drawDisc();
    
}

void sceneA::fftUpdate(){
    ofSoundUpdate();
    volume= ofSoundGetSpectrum(nBandsToGet);

    for (int i = 0; i<nBandsToGet; i++) {
        fftSmoothed[i]*=0.96f;
        if (fftSmoothed[i]<volume[i]) {
            fftSmoothed[i]=volume[i];
        }
    }
}


void sceneA::keyPressed(int key){
//    switch (key) {
//        case ' ':
//            onoff!=onoff;
//            if (onoff==false) {
//                playerA.stop();
//            }
//            else
//                playerA.play();
//            break;
//}

}

void sceneA::stopMusic(){
    ofSoundStopAll();
}

void sceneA::startMusic(){
    playerA.play();
}

void sceneA::volumeUp(){
    playerA.play();
}
void sceneA::volumeDown(){
    playerA.play();
}

void sceneA::pauseMusic(){
    //ポーズするか否かを切り替えるスイッチを動かす
    playerA.setPaused(pause);
   if(pause == true)
       pause = false;
    else
        pause = true;
   // pause != pause;
    //切り替えの結果を適用する
}

void sceneA::drawDisc(){
    //draw lines for the disc
    ofSetColor(250, 250, 250);
    for (int i =2; i<10; i++) {
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, i*40);
    }
    ofDrawBitmapString("Was He Slow? from Baby Driver Soundtrack", 20, 20);
    ofFill();
    ofSetColor(64, 182, 152);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 50);
    //draw the disc itself
    ofSetColor(0, 0, 0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2);
}
