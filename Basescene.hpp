//
//  Basescene.hpp
//  kokkaku
//  Created by 小池潤 on 2019/05/11.

#define Basescene_hpp
#include <stdio.h>
#include "ofMain.h"
#pragma once



class Basescene{
    public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    virtual void keyPressed(int key ){};
    virtual void keyReleased(int key ){};
    virtual void mouseMoved(int x, int y ){};
    virtual void mouseDragged(int x, int y, int button){};
    virtual void mousePressed(int x, int y, int button){};
    virtual void mouseReleased(int x, int y, int button){};
    virtual void mouseEntered(int x, int y){};
    virtual void mouseExited(int x, int y){};
    virtual void windowResized(int w, int h){};
    virtual void dragEvent(ofDragInfo dragInfo){};
    virtual void gotMessage(ofMessage msg){};
    virtual void stopMusic(){};
    virtual void startMusic(){};
    virtual void pauseMusic(){};
    virtual void fftUpdate(){};
    virtual void drawDisc(){};
    virtual void scratch(){};
    virtual void volumeUp(){};
    virtual void volumeDown(){};
    
    ofEasyCam cam;
    ofBoxPrimitive box;
};
