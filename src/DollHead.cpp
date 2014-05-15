//
//  DollHead.cpp
//  ax12OSCServer
//
//  Created by Tomas Laurenzo on 5/6/14.
//
//

#include "DollHead.h"


DollHead::DollHead() {
    pitch = roll = yaw = 0;
    
}


void DollHead::setAngles(ofVec3f angles) {
    this->setAngles(angles[0], angles[1], angles[2]);
}

void DollHead::setAngles (float pitch, float yaw, float roll) {
    this->pitch = pitch; // ofDegToRad(pitch);
    this->yaw = yaw; // ofDegToRad(yaw);
    this->roll = roll; // ofDegToRad(roll);
}

string DollHead::toString() {
    std::stringstream ss;
    ss << pitch << ", " << yaw << ", " << roll;
    std::string s = ss.str();

    return ofToString(s);
    
}


void DollHead::render() {
    ofPushMatrix();
    ofRotateX(pitch);
    ofRotateY(yaw);
    ofRotateZ(roll);
    ofDrawBox(100);
    ofPopMatrix();
}
