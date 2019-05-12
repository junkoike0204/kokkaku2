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
}

void sceneC::update(){
    
}

void sceneC::draw(){
    ofBackground(40,0,240);
    ofSetColor(218, 78, 109);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
    ofDrawBitmapString("sceneC", 20, 20);
}
void sceneC::stopMusic(){
    playerC.stop();
}
void sceneC::startMusic(){
    playerC.play();
}

