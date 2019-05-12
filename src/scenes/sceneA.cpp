//
//  sceneA.cpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//

#include "sceneA.hpp"
void sceneA::setup(){
    playerA.load("FirstDate.mp3");
    playerA.setVolume(1.0);
    playerA.setMultiPlay(false);
    playerA.setLoop(true); //loop on by "true"
    onoff = true;
   if (onoff==true)
       playerA.play();
    else
        playerA.stop();
}

void sceneA::update(){
    if (onoff==false) {
        playerA.stop();
    }
}

void sceneA::draw(){
    ofSetCircleResolution(40);
    ofBackground(64,182,153);
    ofSetColor(250, 250, 250);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
    ofDrawBitmapString("sceneA", 20, 20);
    
   
}


void sceneA::keyPressed(int key){
    switch (key) {
        case ' ':
            onoff!=onoff;
            if (onoff==false) {
                playerA.stop();
            }
            else
                playerA.play();
            break;
}

}

void sceneA::stopMusic(){
    playerA.unload();
}

void sceneA::startMusic(){
    playerA.play();
}
