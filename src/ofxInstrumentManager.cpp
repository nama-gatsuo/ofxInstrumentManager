#include "ofxInstrumentManager.hpp"

ofxInstrumentManager::ofxInstrumentManager(){
    receiver.setup(7401);
}
void ofxInstrumentManager::update(){
    while (receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        vector<string> path = ofSplitString(m.getAddress(), "/");
        
        unsigned int slot = ofToInt(path[0]);
        unsigned int midi = ofToInt(path[1]);
        int vel = m.getArgAsInt(0);
        
        instruments[slot].bang(midi, vel);        
    }
    for (int i = 0; i < instruments.size(); i++) {
        instruments[i].update();
    }
    
}
void ofxInstrumentManager::draw(){
    for (int i = 0; i < instruments.size(); i++) {
        instruments[i].draw();
    }
}
void ofxInstrumentManager::add(InstrumentObject instrument){
    instruments.push_back(instrument);
}


