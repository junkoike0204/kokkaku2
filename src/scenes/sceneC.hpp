//
//  sceneC.hpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//
#define NUM 1000

#define sceneC_hpp
#pragma once
#include <stdio.h>
#include "ofMain.h"
#include "Basescene.hpp"


class sceneC : public Basescene {
    void setup();
    void update();
    void draw();
    void stopMusic();
    void startMusic();
    void fftUpdate();
    void drawDisc();
    ofSoundPlayer playerC;
    Boolean onoff = false;
    
    float *volume;
    float* fftSmoothed; //っfft解析結果を格納する配列
    int nBandsToGet; //fft解析の制度：このプロジェクトでは四角形の本数の多さに影響。
    
};

