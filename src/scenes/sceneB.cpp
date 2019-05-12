//
//  sceneB.cpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//

#include "sceneB.hpp"
void sceneB::setup(){
    playerB.load("WasHeSlow.mp3");
    playerB.setVolume(1.0);
    playerB.setMultiPlay(false);
    playerB.setLoop(true); //loop on by "true"
    
    //playerB.play();
    
}

void sceneB::update(){
    
}

void sceneB::draw(){
    ofBackground(0,200,40);
    ofSetColor(247, 242, 215);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
    ofDrawBitmapString("sceneB", 20, 20);
}


void sceneB::stopMusic(){
    playerB.stop();
}

void sceneB::startMusic(){
    playerB.play();
}

