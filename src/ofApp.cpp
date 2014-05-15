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
    
#ifdef ARDUINO_PRESENT
    arduino = Arduino();
    arduino.setup();
#endif
}

//--------------------------------------------------------------
void ofApp::update(){

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
            
        //    cout << "/head/orientationAngles/";
            
            float pitch = m.getArgAsFloat(0); //up down
            float yaw = m.getArgAsFloat(1); // left right
            float roll = m.getArgAsFloat(2); // ear to shoulder left, ear to shoulder right :)
            
          //  cout << pitch << "/" << yaw << "/" << roll << endl;
            
            dollHead->setAngles (pitch, yaw, roll);
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
#ifdef ARDUINO_PRESENT
    serial.setup("/dev/tty.usbserial-A70060V8", 9600); //TODO check: this in draw??
	serial.startContinuousRead(false);                  //TODO check: this in draw??
#endif
    
    
    ofDisableLighting();
    ofBackground(0);


    ofDrawBitmapString("angles: ", 20, 20);
    ofDrawBitmapString(dollHead->toString(), 120, 20);

    cam.begin();

    ofEnableLighting();
    ofEnableDepthTest();
	l1.enable();
	l2.enable();
    
    dollHead->render();
    
    cam.end();

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    string message;
    switch (key) {
		case 49: // 1
			message += "a";
			break;
        case 50: // 2
			message += "?";
			break;
		case 51: // 3
			message += "3";
			break;
    }
    
#ifdef ARDUINO_PRESENT
    serial.writeString(message);
#endif
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
