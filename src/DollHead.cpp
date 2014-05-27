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
    
//    headModel.loadModel("bolvanka.3ds", 2);
    //    headModel.loadModel("skull.3ds", 20);
        headModel.loadModel("NewSquirrel.3ds", 20);
    
    
    
    
}


void DollHead::setDir(ofVec3f dir) {

    this->yaw = atan(dir.x / dir.y);
    
    this->pitch = atan(sqrt(dir.x * dir.x + dir.y * dir.y) / dir.z);
    
    this->roll = 0;
    
}


void DollHead::setAngles(ofVec3f angles) {
    this->setAngles(angles[0], angles[1], angles[2]);
}

void DollHead::setAngles (float pitch, float yaw, float roll) {
    this->pitch = pitch;
    this->yaw = yaw;
    this->roll = roll; 
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
//    ofDrawBox(100);
    
    ofSetColor(255, 255, 255, 255);
    
    headModel.draw();
    
    ofPopMatrix();
}

float DollHead::getPitch(){
    return this->pitch;
};

float DollHead::getYaw(){
    return this->yaw;
};

float DollHead::getRoll(){
    return this->roll;
};