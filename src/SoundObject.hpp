#pragma once
#include "ofMain.h"

class SoundObject {
public:
    SoundObject(int midiNum):midi(midiNum){};
    virtual void bang(int velocity) = 0;
    virtual void update() = 0;
    virtual void drawObj() = 0;
protected:
    int midi;
    int vel;
};
