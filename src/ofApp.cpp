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
    
    dollHead = new DollHead();
    
    arduino = Arduino();
    arduino.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
		receiver.getNextMessage(&m);

        if(m.getAddress() == "/head/orientation/") {
			float x = m.getArgAsFloat(0);
			float y = m.getArgAsFloat(1);
            float z = m.getArgAsFloat(2);
            
            dollHead->setDir(x, y, z);

        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    dollHead->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    arduino.keyPressed(key);
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
