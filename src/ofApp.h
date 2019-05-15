#pragma once

#include "ofMain.h"
#include "Basescene.hpp"
#include "sceneA.hpp"
#include "sceneB.hpp"
#include "sceneC.hpp"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        vector <Basescene *> scenes;//sceneA,B,C のインスタンス、ポインタを収納する
        int currentScene;//現在のシーン番号
    
        vector <Boolean> PlayOrNot;
    //再生する、しないを格納する配列
      //  vector <ofSoundPlayer> songs ;
    
        ofLight light;//陰影を加える
        ofEasyCam cam; //EasyCamのインスタンス化
        ofTrueTypeFont font;//文字表示用のインスタンス
    
    int songNUM = 6;//収納されている曲の合計数
    int songID = 0;//曲の通し番号
    
    
    
    
		
};
