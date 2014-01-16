#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    serial.setup("/dev/tty.usbmodem1421",9600);// make sure the serial port is correct (not sure how to get it on the pi?)
    
    ofSetFrameRate(120); // also the rate oF will try to send data over the serial
    
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    noiseStepsX = 0.1; //smoothness (I think) **default = 0.1
    noiseStepsY = 0.2;
    
}

//--------------------------------------------------------------
void testApp::update(){
    t = ofGetElapsedTimef();
    noiseX = ofNoise(t*noiseStepsX);
    noiseY = ofNoise(t*noiseStepsY);
    cout << noiseX << endl;
    cout << noiseY << endl;
    
    // SCREEN MAPPING
    posX = ofMap(noiseX, 0, 1, 0, ofGetWindowWidth());
    posY = ofMap(noiseY, 0, 1, 0, ofGetWindowHeight());

    
    // SERVO MAPPING
    // i need to map the output of ofNoise from 1000 to 2000 in order to send the servos to those values
    serValX = ofMap(noiseX, 0, 1, 1000, 2000);
    serValY = ofMap(noiseY, 0, 1, 1000, 2000);
    // print the values for the servos (this will go to the Arduino later)
    cout << serValX << endl;
    cout << serValY << endl;

}

//--------------------------------------------------------------
void testApp::draw(){
    //BACKGROUND
    ofSetColor(0,5);//black with 5% alpha
    ofRect(0,0,ofGetWidth(),ofGetHeight());//cover screen with rectangle
    
    //VIRTUAL LASER POINTER & GITD TRAIL
    ofSetColor(0,255,0,90);//nice GITD green!
    ofCircle(posX, posY, 2);
    }

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
