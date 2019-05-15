#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //this sentence lies here just to check if this file is updated on github//
    ofSetVerticalSync(true);//ソフトの更新、ディスプレイの更新の頻度を一致させる
    cam.setOrientation(ofPoint(-20,0,0));
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    ofSetFrameRate(30);
    Basescene * sa = new sceneA();
    scenes.push_back(sa);
    Basescene * sb = new sceneB();
    scenes.push_back(sb);
    Basescene * sc = new sceneC();
    scenes.push_back(sc);
    //現在シーンを０に。
    currentScene = 0;
    scenes[currentScene]->setup();
    
    
    string song_path_list[] = { "GetLucky.mp3","WasHeSlow.mp3","Wannabe.mp3","FirstDate.mp3","WhatYouGot.mp3","GoodGirls.mp3" };
//
//    for (int i =0;  i<songNUM; i++) {
//        ofSoundPlayer SoundSetup;
//        SoundSetup.load(song_path_list[i]);
//        SoundSetup.setVolume(0.5);
//        SoundSetup.setMultiPlay(false);
//        SoundSetup.setLoop(true); //loop on by "true"
//        songs.push_back(SoundSetup);
//        PlayOrNot.push_back(false);
//        //配列songsに読み込みとセットアップ
//    }
    for (int i=0; i<3; i++) {
        scenes[i]->setup();
    }
    
   // songs[1].play();
}

//--------------------------------------------------------------
void ofApp::update(){
  scenes[currentScene]->update();
//    //現在表示しているシーンを更新
}
//--------------------------------------------------------------
void ofApp::draw(){
       scenes[currentScene]->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            scenes[currentScene]->stopMusic();
            currentScene++;
            currentScene %=scenes.size();
           // scenes[currentScene]->setup();
          // scenes[currentScene]->setup();
            scenes[currentScene]->startMusic();
            
            break;

        case 'f':
            ofToggleFullscreen();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
