#include "ofApp.h"
#include "ofxLeapMotion2.h"

//シーンの切り替え、全シーンのセットアップ、スワイプの認識はこのクラスで行います。
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    
    leap.open();
    leap.setupGestures();
    LeapCon.enableGesture(Leap::Gesture::TYPE_SWIPE);
      //leapmotionの接続とスワイプに対する準備
    
    float microseconds = gesture.duration();
    float seconds = gesture.durationSeconds();
  //結局使っていないスワイプの長さを収納する変数
   
    Frame frame = LeapCon.frame (); // controller is a Controller object
    Hand hand = frame.hands()[0];
    Vector position = hand.palmPosition();
    velocity = hand.palmVelocity();
    //leaapの教科書等参考
  
    //this sentence lies here just to check if this file is updated on github//
    ofSetVerticalSync(true);//ソフトの更新、ディスプレイの更新の頻度を一致させる
    cam.setOrientation(ofPoint(-20,0,0));
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    Basescene * sa = new sceneA();
    scenes.push_back(sa);
    Basescene * sb = new sceneB();
    scenes.push_back(sb);
    Basescene * sc = new sceneC();
    scenes.push_back(sc);
    //sceneA,B,Cを作り、ベクター配列に収納しておく
  
    currentScene = 0;
    //scenes[currentScene]->setup();
      //現在シーンを０に。セットアップ
    
    
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
    }//右左swipe認識用の配列のリセット。
    
  
    
    
    string sound_path_list[] = {  "Scratch.mp3","Scratch1.mp3","Scratch2.mp3"};
    //三種類のスクラッチ音をテキストで管理します
    
    //scratch sound effect 
    for (int i=0; i<3; i++) {
        Scratch[i].load(sound_path_list[i]);
        Scratch[i].setVolume(1.0);
        Scratch[i].setLoop(false);
    }//それぞれの効果音の準備
  
    
}

//--------------------------------------------------------------
void ofApp::update(){
  scenes[currentScene]->update();
    handJoint();
    swipe();
    //現在表示しているシーンを更新
}

void ofApp::handJoint(){//手の座標を認識、記録するメソッド
    simplehands = leap.getsimplehands();
    if (leap.isFrameNew() &&simplehands.size()) {
        // fingerPos.clear();
        handPos.clear();
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        PrehandPos.push_back(simplehands[0].handPos);
        //leapの教科書参考
    //    ofVec2f velocity = ofVec2f(LeapCon.palmvelocity, -handPos.y);
        
///////////////////////////手の加速度を測定。///////////////////////////////
        for (int i =0; i<simplehands.size(); i++) {//手の数だけ
            handPos.push_back(simplehands[i].handPos);
            newacc = (handPos[0].z-PrehandPos[0].z);
            PrehandPos = handPos;
            cout<<newacc<<endl;
          //  cout<<newacc<<endl;
        }
/////////////////////////////////速度が一定以上の時/////////////////////////
        if ( newacc>30) {
            scratch();
        }
////////////////////////////////////////////////////////////////////////////
    
    }//if (leap.isFrameNew() &&simplehands.size()) にかかる
}

void ofApp::swipe(){
    //leap.hに定義されているスワイプを認識する昨日iGesture key。今回実際に使ったのはright leftのみ。
    //scratchにforward,backwardを使うことを考えていたが、結局z軸方向の加速度をとるかたちで実装した
    /* Leap iGesture Key
     --------------------------------
     1 = Screen Tap
     2 = Key Tap
     3 = Swipe Right
     4 = Swipe Left
     5 = Swipe Down
     6 = Swipe Up
     7 = Swipe Forward
     8 = Swipe Backward (towards yourself)
     9 = Circle Left (counter-clockwise)
     10 = Circle Right (clockwise)
     --------------------------------
     */
  
    
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
        case 5:
        {
            cout<<"swiped down"<<endl;
            //scenes[currentScene]->pauseMusic();
            break;
        }
        case 6:
        {
            cout<<"swiped up"<<endl;
            
            //scenes[currentScene]->pauseMusic();
            break;
        }
        case 7:
        {
            cout<<"swiped forward"<<endl;
              //scenes[currentScene]->pauseMusic();
            break;
        }
            
        case 8:
        {
            cout<<"swiped back"<<endl;
             //scenes[currentScene]->pauseMusic();
            break;
      
        }
        case 10:
        {
            cout<<"clock right"<<endl;
            tsumami+=0.02;
            if (tsumami>1.0) {
                tsumami-=1.0;
            }//volumeUp用に付けたが間に合わず。
            cout<<"tsumami"<<endl;
            break;
            
        }
       
        default:{
           // cout<<".";
        }
    }
    //諏訪イプが認識sされたフレームのところだけtrueを入れる、フレーム数分の配列を作る
    leap.updateGestures();  // check for gesture updates
    RSwipeOnOff[ofGetFrameNum()%30]=false;
    LSwipeOnOff[ofGetFrameNum()%30]=false;
    FSwipeOnOff[ofGetFrameNum()%30]=false;
    BSwipeOnOff[ofGetFrameNum()%30]=false;
    switch (leap.iGestures) {
        case 3:{
            RSwipeOnOff[ofGetFrameNum()%30]=true;
            break;
        }
        case 4:
            LSwipeOnOff[ofGetFrameNum()%30]=true;
            break;
        case 7:
            FSwipeOnOff[ofGetFrameNum()%30]=true;
            break;
        case 8:
            BSwipeOnOff[ofGetFrameNum()%30]=true;
            break;
        default:
            break;
    }
    
//    if (leap.iGestures ==3) {
//        RSwipeOnOff[ofGetFrameNum()%30]=true;
//    }//もしスワイプが確認されたらtrue
//    else   RSwipeOnOff[ofGetFrameNum()%30] = false;
//    //されなければfalseを代入
//
//    if (leap.iGestures ==4) {
//        LSwipeOnOff[ofGetFrameNum()%30]=true;
//    }//もしスワイプが確認されたらtrue
//    else   LSwipeOnOff[ofGetFrameNum()%30] = false;
//    if (leap.iGestures ==7) {
//        FSwipeOnOff[ofGetFrameNum()%30]=true;
//    }//もしスワイプが確認されたらtrue
//    else   FSwipeOnOff[ofGetFrameNum()%30] = false;
//    if (leap.iGestures ==8) {
//        BSwipeOnOff[ofGetFrameNum()%30]=true;
//    }//もしスワイプが確認されたらtrue
//    else   BSwipeOnOff[ofGetFrameNum()%30] = false;
//
    //右スワイプでシーンとばし
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
    if (LSwipeOnOff[ofGetFrameNum()%30]==true&&LSwipeOnOff[ofGetFrameNum()%30-1]==true) {
        //もし現フレームでスワイプが認識されず、前フレームでスワイプが認識されていたら
        //つまりスワイプが終わった時点で
        scenes[currentScene]->stopMusic();
        currentScene-=1;
        if (currentScene<0) {
            currentScene =2;
        }
        currentScene %=scenes.size();
        // scenes[currentScene]->setup();
        scenes[currentScene]->setup();
        scenes[currentScene]->startMusic();
        //シーンの切り替え作業を行う
        for (int i =0; i<30; i++) {
            LSwipeOnOff[i]=false;
        }//スワイプ判定は全てリセット
    }
        
//        if  (FSwipeOnOff[ofGetFrameNum()%30]==false&&FSwipeOnOff[ofGetFrameNum()%30-1]==true) {
          if  (FSwipeOnOff[ofGetFrameNum()%30]==false&&FSwipeOnOff[ofGetFrameNum()%30]==true) {
            scenes[currentScene]->pauseMusic();
            cout<<"scratch detected"<<endl;
            //シーンの切り替え作業を行う
            for (int i =0; i<30; i++) {
                BSwipeOnOff[i]=false;
                FSwipeOnOff[i]=false;
            }//スワイプ判定は全てリセット
    }

    leap.markFrameAsOld();
}
//--------------------------------------------------------------
void ofApp::draw(){
       scenes[currentScene]->draw();
    //指定されたシーンの描画
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
            
        case 'p':
            scenes[currentScene]->pauseMusic();
            break;
        case 'o':{
            int que = ofRandom(4);
            Scratch[que].play();
            break;}
        case 's':
            scenes[currentScene]->startMusic();
            break;

        case 'f':
            ofToggleFullscreen();
            break;
            //fキーでフルスクリーン
    }
}
    
//--------------------------------------------------------------------------------------
void ofApp::scratch(){
        cout<<"superspeed:"<<abs(newacc)<<endl;
        int que = ofRandom(2);
        Scratch[que].play();
    
}
////--------------------------------------------------------------

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
