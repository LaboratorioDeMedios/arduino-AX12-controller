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

class DollHead {
public:
    DollHead();
    void setDir(ofVec3f dir);
    void setDir (float x, float y, float z);
    void render();
    
    
private:
    ofVec3f dir;
    
};


#endif /* defined(__ax12OSCServer__DollHead__) */
