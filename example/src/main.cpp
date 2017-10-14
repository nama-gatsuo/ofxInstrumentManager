#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLWindowSettings settings;
    settings.setGLVersion(3, 2); // now we use OpenGL 3.2
    settings.width = 768;
    settings.height = 768;
    
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
}
