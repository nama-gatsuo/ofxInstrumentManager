#pragma once
#include "ofMain.h"
#include "SoundObject.hpp"
#include "CommonUtil.hpp"

class InstrumentObject {
public:
    InstrumentObject(int addr){
        address = addr;
    };
    void update(){
        for (int i = 0; i < activeMidiNums.size(); i++) {
            soundObjects[i]->update();
        }
    };
    void bang(int midiNum, int velocity){
        for (int i = 0; i < activeMidiNums.size(); i++) {
            if (activeMidiNums[i] == midiNum) {
                soundObjects[i]->bang(velocity);
            }
        }
    };
    
    void draw(){
        for (int i = 0; i < activeMidiNums.size(); i++) {
            soundObjects[i]->drawObj();
        }
    };
    void add(shared_ptr<SoundObject> sound, int midiNum){
        soundObjects.push_back(sound);
        activeMidiNums.push_back(midiNum);
    };

private:
    vector<shared_ptr<SoundObject>> soundObjects; // 0 - 127
    vector<int> activeMidiNums;
    int address;
};
