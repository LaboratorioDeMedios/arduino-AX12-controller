//
//  DollHead.h
//  ax12OSCServer
//
//  Created by Tomas Laurenzo on 5/6/14.
//
//

#ifndef __ax12OSCServer__DollHead__
#define __ax12OSCServer__DollHead__


#include "ofMain.h"
#include "ofx3DModelLoader.h"


class DollHead {
public:
    DollHead();
    
    void setAngles(ofVec3f angles);
    void setAngles (float pitch, float yaw, float roll);
    
    void setDir (ofVec3f dir);
    
    void render();
    
    string toString();
    
private:
    float pitch;
    float yaw;
    float roll;
    
    ofx3DModelLoader headModel;

    
    
};


#endif /* defined(__ax12OSCServer__DollHead__) */
