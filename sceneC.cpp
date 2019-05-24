//
//  sceneC.cpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//

#include "sceneC.hpp"

void sceneC::setup(){
     ofSetVerticalSync(true);
    playerC.load("Rydeen.mp3");
    playerC.setVolume(0.2);
    playerC.setMultiPlay(false);
    playerC.setLoop(true); //loop on by "true"
    //playerC.play();
    
    fftSmoothed= new float[NUM];
    for(int i =0; i<NUM; i++){
        fftSmoothed[i]=0;
    }
    nBandsToGet = 40;
    
//    for(int i = 0; i<boxNUM; i++){
////        box[i].setPosition(ofRandom(300)*sin(ofRandom(0, 360)),0,ofRandom(300)*cos(ofRandom(0, 360)));
//        box[i].setPosition(ofRandom(1,4)*100*cos(ofMap(10*(i%36),0,360,0,2*PI)),0,
//                           ofRandom(1,4)*100*sin(ofMap(10*(i%36),0,360,0,2*PI)));
    
//                                             }
    ofSetFrameRate(30);
    ofBackground(40,0,240);
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
//      cam.setPosition(600*sin(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)), 3000*sin(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)), 2000*cos(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)));
    cam.setPosition(300*sin(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)), 800, 1000*cos(ofMap(ofGetElapsedTimeMillis(), 0, 10000, 0, 2*PI)));
    
    ofBackground(250,220,60);
//    color.fromHsb(ofGetFrameNum()%255, 250, 250);
//    ofBackground(color);
//   // ofSetColor(color);
//    ofSetColor(0, 0, 0);
     ofSetColor(250,220,60);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    //ofSetColor(218, 78, 109);
    
//    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
//    ofDrawBitmapString("sceneC", 20, 20);
//    for (int i =0; i<nBandsToGet; i+=10) {
//        ofNoFill();
//        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, fftSmoothed[i]*400+30);
    
//    }
    //drawDisc();

//    for (int i =0; i<boxNUM; i++) {
//        box[i].set(ofRandom(3)+volume[i]*100);
//        if (volume[i]>0.7) {
//            ofSetColor(250);
//        }
//        else
//            ofSetColor(218, 78, 109);
//        box[i].draw();
//    }
   
    ofPushMatrix();
    ofRotateXDeg(90);
    ofNoFill();
    ofSetColor(250);
    for (int i =2; i<10; i++) {
        ofDrawCircle(0,0,0, i*40);
    }
  
    ofFill();
//    ofDrawCircle(100, 0,-5, 10);
//     ofDrawCircle(100, 0,5, 10);
    
    //yellow
    ofSetColor(250,220,60);
    
    ofSetColor(0);
    ofDrawCircle(0,0,0, 400);
    ofSetColor(40,0,240);
    //ofDrawCircle(0,0, -5, 60);
    ofPopMatrix();
    cam.end();
    
    int start_x = 0;//一番左端の四角形のx座標
    int base_y = ofGetHeight()*5/8;//四角形のy座標
    float width = (float)(3*ofGetWidth()-100)/nBandsToGet; //四角形の幅
    
    if (fftSmoothed[0]>9.5)
        ofSetColor(ofRandom(250), ofRandom(250), ofRandom(250));
      
    ofSetColor(55, 190, 260);//上向き四角形
    for (int i = 0; i<nBandsToGet; i++) {
        ofDrawRectangle(start_x+i*width, base_y, width, -(fftSmoothed[i]*400));//上むき
    }
    //ofNoFill();
    ofSetColor(55, 190, 260,120);
    if (fftSmoothed[0]<10)
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,fftSmoothed[0]*100);
    
    ofFill();
     ofDrawBitmapString("Rydeen /Yellow Magic Orchestra", 20, 20);
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

void sceneC::pauseMusic(){
    playerC.setPaused(pause);
    //切り替えの結果を適用する
    if(pause == true)
        pause = false;
    else
        pause = true;
    //ポーズするか否かを切り替えるスイッチを動かす
}
void sceneC ::drawDisc(){
//    //draw lines for the disc
//    ofSetColor(250, 250, 250);
//    for (int i =2; i<10; i++) {
//        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, i*40);
//    }
//   // ofDrawBitmapString("sceneA", 20, 20);
//    ofFill();
//    ofSetColor(64, 182, 152);
//    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 50);
//    //draw the disc itself
//    ofSetColor(0, 0, 0);
//    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, ofGetHeight()/2);
}
void sceneC::volumeUp(){
    playerC.play();
}
void sceneC::volumeDown(){
    playerC.play();
}

