#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);

	current_msg_string = 0;
	mouseX = 0;
	mouseY = 0;
	mouseButtonState = "";

	ofBackground(30, 30, 130);

	l1.setPosition(200, 300, 50);
	l2.setPosition(-200, -200, 50);

    dollHead = new DollHead();

    tempx = tempy = tempz = 0;

    // pitch: 20.2041 heading: 0.343797 roll: 95.8658

    listening = true;

    arduino = Arduino();
    arduino.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (listening) {
        while(receiver.hasWaitingMessages()){
            ofxOscMessage m;
            receiver.getNextMessage(&m);

            if (m.getAddress() == "/head/orientationDir/") {
                float x = m.getArgAsFloat(0);
                float y = m.getArgAsFloat(1);
                float z = m.getArgAsFloat(2);

                dollHead->setDir(ofVec3f(x,y,z));

            }
            else if (m.getAddress() == "/head/orientationAngles/") {

                float pitch = m.getArgAsFloat(0); //up down
                float yaw = m.getArgAsFloat(2); // left right
                float roll = m.getArgAsFloat(1); // ear to shoulder left, ear to shoulder right :)

                pitch += tempx;
                yaw += tempy;
                roll += tempz;

                dollHead->setAngles (pitch, yaw, roll);
            }
            
        }
    } else {
        float pitch = tempx;
        float yaw = tempy;
        float roll = tempz;
        dollHead->setAngles (pitch, yaw, roll);
    }
    
    signed int pitch = (signed int)dollHead->getPitch();
    signed int yaw = (signed int)dollHead->getYaw();
    signed int roll = (signed int)dollHead->getRoll();
    
    arduino.moveMotor(1, pitch);
    arduino.moveMotor(2, yaw);
    arduino.moveMotor(4, roll);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    dollHead->render();
    
    ofDisableLighting();
    ofBackground(0);
    
    
    ofDrawBitmapString("angles: ", 20, 20);
    ofDrawBitmapString(dollHead->toString(), 120, 20);
    
    //cam.begin();
    
    ofEnableLighting();
    ofEnableDepthTest();
	l1.enable();
	l2.enable();
    
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateX(90);

    
    dollHead->render();
    
    //cam.end();
    
    /*
     cout << "pitch: " << cam.getPitch() << " ";
     cout << "heading: " << cam.getHeading() << " ";
     cout << "roll: " << cam.getRoll() << endl;
     */

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    arduino.keyPressed(key);
    string message;
    switch (key) {
        case 'q': tempx -= 10; break;
        case '1': tempx += 10; break;
        case '2': tempy += 10; break;
        case 'w': tempy -= 10; break;
        case '3': tempz += 10; break;
        case 'e': tempz -= 10; break;
        case 'l': listening = !listening; break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
