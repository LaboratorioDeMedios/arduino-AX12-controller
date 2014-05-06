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
    
    arduino = Arduino();
    arduino.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    serial.setup("/dev/tty.usbserial-A70060V8", 9600);
	serial.startContinuousRead(false);
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
    serial.writeString(message);
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
