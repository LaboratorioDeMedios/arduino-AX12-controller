//
//  DollHead.cpp
//  ax12OSCServer
//
//  Created by Tomas Laurenzo on 5/6/14.
//
//

#include "DollHead.h"


DollHead::DollHead() {
    dir = ofVec3f(0,0,0);
    
}

void DollHead::setDir(ofVec3f dir) {
    this->dir = dir;
}

void DollHead::setDir (float x, float y, float z) {
    dir.x = x;
    dir.y = y;
    dir.z = z;
}

void DollHead::render() {
    ofPushMatrix();
    ofRotateX(dir.x);
    ofRotateY(dir.y);
    ofRotateZ(dir.z);
    ofDrawBox(100);
    ofPopMatrix();
}
