//
//  sceneA.hpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//

#ifndef sceneA_hpp
#define sceneA_hpp
#pragma once
#define NUM 1000
#include <stdio.h>
#include "ofMain.h"
#include "Basescene.hpp"
#endif /* sceneA_hpp */


#pragma once
#include "Basescene.hpp"
//Basesceneをもとにしたクラス（継承）
class sceneA : public Basescene {
    void setup();
    void update();
    void draw();
    void keyPressed(int key );
    void stopMusic();
    void startMusic();
    void fftUpdate();
    void drawDisc();
    ofSoundPlayer playerA;
    Boolean onoff = true;
    Boolean pause = true;
    void pauseMusic();
    float *volume;
    float* fftSmoothed; //っfft解析結果を格納する配列
    int nBandsToGet;
    //fft解析の制度：このプロジェクトでは四角形の本数の多さに影響。
    void volumeUp();
    void volumeDown();
    
};

