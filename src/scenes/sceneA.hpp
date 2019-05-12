//
//  sceneA.hpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//

#ifndef sceneA_hpp
#define sceneA_hpp
#pragma once

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
    ofSoundPlayer playerA;
    Boolean onoff = true;
};

