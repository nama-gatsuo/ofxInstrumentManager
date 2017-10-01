#pragma once
#include "ofMain.h"
#include "ofxOsc.h"
#include "InstrumentObject.hpp"

class ofxInstrumentManager {
public:
    ofxInstrumentManager();
    void update();
    void draw();
    void add(InstrumentObject instrument);
private:
    void check(int id);
    ofxOscReceiver receiver;
    vector<InstrumentObject> instruments;
};
