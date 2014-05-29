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
    
    ofSetFrameRate(24);
    
	ofBackground(30, 30, 130);
    
	l1.setPosition(200, 300, 50);
	l2.setPosition(-200, -200, 50);
    
    dollHead = new DollHead();
    
    tempPitch = tempYaw = tempRoll = 0;
    
    // pitch: 20.2041 heading: 0.343797 roll: 95.8658
    
    listening = true;
    keyboardMotorTest = true;
    
#ifdef ARDUINO_PRESENT    
    arduino = Arduino();
    arduino.setup();
#endif
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
                
                dollHead->setAngles (pitch, yaw, roll);
            }
            
        }
        
    } else {
        float pitch = tempPitch;
        float yaw = tempYaw;
        float roll = tempRoll;
        dollHead->setAngles (pitch, yaw, roll);
    }
    
    signed int pitch = (signed int)dollHead->getPitch();
    signed int yaw = (signed int)dollHead->getYaw();
    signed int roll = (signed int)dollHead->getRoll();
    
#ifdef ARDUINO_PRESENT
    if (!keyboardMotorTest) {
        arduino.moveMotor(1, pitch);
        arduino.moveMotor(2, yaw);
        arduino.moveMotor(4, roll);
    }
#endif
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    dollHead->render();
    
    ofDisableLighting();
    ofBackground(0);
    
    
    ofDrawBitmapString("angles: ", 20, 20);
    ofDrawBitmapString(dollHead->toString(), 120, 20);
    
    ofDrawBitmapString("listening OSC: ", 20, 40);
    ofDrawBitmapString(ofToString(listening), 140, 40);
    
    ofDrawBitmapString("keyboard test: ", 20, 60);
    ofDrawBitmapString(ofToString(keyboardMotorTest), 140, 60);
    
    
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
#ifdef ARDUINO_PRESENT
    arduino.keyPressed(key);
#endif
    
    string message;
    
    switch (key) {
        case 'q': tempPitch -= 10; break;
        case '1': tempPitch += 10; break;
        case '2': tempYaw += 10; break;
        case 'w': tempYaw -= 10; break;
        case '3': tempRoll += 10; break;
        case 'e': tempRoll -= 10; break;
        case 'l': listening = !listening; break;
        case 'k': keyboardMotorTest = !keyboardMotorTest; break;
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
