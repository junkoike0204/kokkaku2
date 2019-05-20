//
//  sceneB.hpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//
#define sceneB_hpp
#pragma once

#define NUM 1000
#include <stdio.h>
#include "ofMain.h"
#include "Basescene.hpp"


class sceneB : public Basescene {
    void setup();
    void update();
    void draw();
    void stopMusic();
    void startMusic();
    void pauseMusic();

     void fftUpdate();
    void drawDisc();
    ofSoundPlayer playerB;
    Boolean onoff = false;
    Boolean pause = false;
    float *volume;
    float* fftSmoothed; //っfft解析結果を格納する配列
    int nBandsToGet;
    ofEasyCam cam;
};

