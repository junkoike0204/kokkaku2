#include "ofApp.h"
#include "ofxLeapMotion2.h"
//--------------------------------------------------------------
void ofApp::setup(){
    leap.open();
    leap.setupGestures();
    ofSetFrameRate(30);
    LeapCon.enableGesture(Leap::Gesture::TYPE_SWIPE);
    float microseconds = gesture.duration();
    float seconds = gesture.durationSeconds();
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
    
    
    string song_path_list[] = { "GetLucky.mp3","WasHeSlow.mp3","Wannabe.mp3","FirstDate.mp3","WhatYouGot.mp3","GoodGirls.mp3","Get Dat.mp3" };
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
    }//それぞれのシーンのセットアップを行う
    
    for (int i=0; i<30; i++) {
        RSwipeOnOff[i]=false;
        LSwipeOnOff[i]=false;
    }//右swipe認識用の配列のリセット。
    
   // songs[1].play();
}

//--------------------------------------------------------------
void ofApp::update(){
  scenes[currentScene]->update();
    handJoint();
     switch (leap.iGestures) {
     case 3:
         {
             cout<<"swiped right"<<endl;
             break;
         }
    case 4:
         {
             cout<<"swiped left"<<endl;
             break;
         }
            
}
    
    leap.updateGestures();  // check for gesture updates
    leap.markFrameAsOld();
    if (leap.iGestures ==3) {
        RSwipeOnOff[ofGetFrameNum()%30]=true;
    }//もしスワイプが確認されたらtrue
    else   RSwipeOnOff[ofGetFrameNum()%30] = false;
//されなければfalseを代入
    
   
    if (RSwipeOnOff[ofGetFrameNum()%30]==false&&RSwipeOnOff[ofGetFrameNum()%30-1]==true) {
        //もし現フレームでスワイプが認識されず、前フレームでスワイプが認識されていたら
        //つまりスワイプが終わった時点で
        scenes[currentScene]->stopMusic();
        currentScene++;
        currentScene %=scenes.size();
        // scenes[currentScene]->setup();
        scenes[currentScene]->setup();
        scenes[currentScene]->startMusic();
        //シーンの切り替え作業を行う
        for (int i =0; i<30; i++) {
            RSwipeOnOff[i]=false;
        }//スワイプ判定は全てリセット
    }
    
    
    //左向きスワイプで曲の一個戻し
    if (LSwipeOnOff[ofGetFrameNum()%30]==false&&LSwipeOnOff[ofGetFrameNum()%30-1]==true) {
        //もし現フレームでスワイプが認識されず、前フレームでスワイプが認識されていたら
        //つまりスワイプが終わった時点で
        scenes[currentScene]->stopMusic();
        currentScene-=currentScene;
        currentScene %=scenes.size();
        // scenes[currentScene]->setup();
        scenes[currentScene]->setup();
        scenes[currentScene]->startMusic();
        //シーンの切り替え作業を行う
        for (int i =0; i<30; i++) {
            LSwipeOnOff[i]=false;
        }//スワイプ判定は全てリセット
    }
//    //現在表示しているシーンを更新
}

void ofApp::handJoint(){
    simplehands = leap.getsimplehands();
    if (leap.isFrameNew() &&simplehands.size()) {
        // fingerPos.clear();
        handPos.clear();
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
    //    ofVec2f velocity = ofVec2f(LeapCon.palmvelocity, -handPos.y);
        for (int i =0; i<simplehands.size(); i++) {//指の本数だけ
            handPos.push_back(simplehands[i].handPos);//手の中心座標をvector配列に追加（手の数だけ行う
        }
        
      
        }
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
            scenes[currentScene]->startMusic();
            //spaceキーで音楽の停止、シーンの切り替え、新しい音楽の再生
            break;

        case 'f':
            ofToggleFullscreen();
            break;
            //fキーでフルスクリーン
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
