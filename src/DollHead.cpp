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


void DollHead::setAngles(ofVec3f angles) {
    this->setAngles(angles[0], angles[1], angles[2]);
}

void DollHead::setAngles (float pitch, float yaw, float roll) {
    pitch = ofDegToRad(pitch);
    yaw = ofDegToRad(yaw);
    roll = ofDegToRad(roll);
    
    dir.x = cos(yaw)*cos(pitch);
    dir.y = sin(yaw)*cos(pitch);
    dir.z = sin(pitch);
}



void DollHead::render() {
    ofPushMatrix();
    ofTranslate(200, 200);
    ofRotateX(dir.x);
    ofRotateY(dir.y);
    ofRotateZ(dir.z);
    ofDrawBox(100);
    ofPopMatrix();
}
