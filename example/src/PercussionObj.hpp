#pragma once
#include "ofMain.h"
#include "SoundObject.hpp"
#include "CommonUtil.hpp"

class BassDrumObj : public SoundObject, public ofNode {
public:
    BassDrumObj():SoundObject(36){
        ofNode::setPosition(0, -150, 0);
        mesh = ofMesh::sphere(5., 10);
        
        radius = PhysicValue(4.2, 0.25, 4.); // mass, gravity, velocityLimit
        radius.enableLowerLimit();
        radius.setLowerLimit(10.);
        radius.enableUpperLimit();
        radius.setUpperLimit(20.);
        
    };
    void update(){
        radius.update();
    };
    void bang(int velocity){
        radius.addForce(velocity * 0.08);
    };
    void drawObj(){
        ofNode::draw();
    };
    void customDraw(){
        float r = radius.get();
        ofScale(r, r, r);
        mesh.draw();
    };
    
private:
    ofVboMesh mesh;
    PhysicValue radius;
};

class SnareDrumObj : public SoundObject, public ofNode {
public:
    SnareDrumObj():SoundObject(38){
        create(50.);
        
        offset = PhysicValue(1., 0.01, 0.2);
        offset.enableLowerLimit();
        offset.setLowerLimit(1.);
        offset.enableUpperLimit();
        offset.setUpperLimit(2.);
    };
    void update(){
        offset.update();
    };
    void bang(int velocity){
        offset.addForce(velocity * 0.004);
    };
    void drawObj(){
        ofNode::draw();
    };
    void customDraw(){
        for (int i = 0; i < 12; i++) {
            ofPushMatrix();
            ofTranslate(vecs[i] * offset.get());
            boxes[i].draw();
            ofPopMatrix();
        }
    };
    
    void create(float boxSize){
        
        float w = boxSize;
        float h = boxSize;
        float d = boxSize;
        
        float t = boxSize * 0.1;
        w += t;
        h += t;
        d += t;
        
        vecs[0] = ofVec3f(w/2, h/2, 0);
        boxes[0] = ofMesh::box(t, t, d, 1,1,1);
        vecs[1] = ofVec3f(-w/2, h/2, 0);
        boxes[1] = ofMesh::box(t, t, d, 1,1,1);
        vecs[2] = ofVec3f(0, h/2, d/2);
        boxes[2] = ofMesh::box(w, t, t, 1,1,1);
        vecs[3] = ofVec3f(0, h/2, -d/2);
        boxes[3] = ofMesh::box(w, t, t, 1,1,1);
        vecs[4] = ofVec3f(w/2, 0, d/2);
        boxes[4] = ofMesh::box(t, h, t, 1,1,1);
        vecs[5] = ofVec3f(w/2, 0, -d/2);
        boxes[5] = ofMesh::box(t, h, t, 1,1,1);
        vecs[6] = ofVec3f(-w/2, 0, -d/2);
        boxes[6] = ofMesh::box(t, h, t, 1,1,1);
        vecs[7] = ofVec3f(-w/2, 0, d/2);
        boxes[7] = ofMesh::box(t, h, t, 1,1,1);
        vecs[8] = ofVec3f(w/2, -h/2, 0);
        boxes[8] = ofMesh::box(t, t, d, 1,1,1);
        vecs[9] = ofVec3f(-w/2, -h/2, 0);
        boxes[9] = ofMesh::box(t, t, d, 1,1,1);
        vecs[10] = ofVec3f(0, -h/2, d/2);
        boxes[10] = ofMesh::box(w, t, t, 1,1,1);
        vecs[11] = ofVec3f(0, -h/2, -d/2);
        boxes[11] = ofMesh::box(w, t, t, 1,1,1);
        
    };
    
private:
    ofVboMesh boxes[12];
    ofVec3f vecs[12];
    PhysicValue offset;
};

class HatCloseObj : public SoundObject, public ofNode {
public:
    HatCloseObj():SoundObject(42){
        ofVec3f tv[4] = { ofVec3f(1,1,1), ofVec3f(-1,-1,1), ofVec3f(-1,1,-1), ofVec3f(1,-1,-1) };
        int ti[4][3] = {{2,1,0}, {0,3,2}, {1,3,0}, {2,3,1}};
        
        float size = 50.;
        
        for (int i = 0; i < 4; i++) {
            vecs[i] = (tv[ti[i][0]] + tv[ti[i][1]] + tv[ti[i][2]]) * size / 3.;
            
            ofVboMesh tri;
            for (int j = 0; j < 3; j++){
                tri.addVertex(tv[ti[i][j]] * size);
                tri.addNormal(vecs[i].getNormalized());
            }
            meshes[i] = tri;
        }
        
        offset = PhysicValue(2., 0.04, 0.3);
        offset.enableLowerLimit();
        offset.setLowerLimit(0.);
        offset.enableUpperLimit();
        offset.setUpperLimit(3.);
        
        ofNode::setPosition(0, 150, 0);
    }
    void update(){
        offset.update();
    }
    void bang(int velocity){
        offset.addForce(velocity * 0.0044);
    }
    void drawObj(){
        ofNode::draw();
    }
    void customDraw(){
        for (int i = 0; i < 4; i++) {
            ofPushMatrix();
            ofTranslate(vecs[i] * offset.get());
            meshes[i].draw();
            ofPopMatrix();
        }
    }
private:
    ofVboMesh meshes[4];
    ofVec3f vecs[4];
    PhysicValue offset;
};

