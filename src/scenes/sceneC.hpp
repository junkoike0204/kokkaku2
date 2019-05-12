//
//  sceneC.hpp
//  kokkaku
//
//  Created by 小池潤 on 2019/05/11.
//


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
      ofSoundPlayer playerC;
     Boolean onoff;
};

