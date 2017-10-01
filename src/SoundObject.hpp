#pragma once
#include "ofMain.h"

class SoundObject {
public:
    SoundObject(int midiNum):midi(midiNum){};
    virtual void bang(int velocity){};
    virtual void update(){};
    virtual void drawObj(){};
protected:
    int midi;
    int vel;
};
