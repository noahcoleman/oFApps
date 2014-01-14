#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    serial.setup("/dev/tty.usbmodem1421",9600);// make sure the serial port is correct (not sure how to get it on the pi?)
    
    ofSetFrameRate(120); // also the rate oF will try to send data over the serial
    
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    noiseSteps = 0.1; //smoothness (I think) **default = 0.1
    noiseAmount = 1000; //speed of change (I think) **default = 100
    
}

//--------------------------------------------------------------
void testApp::update(){
    t = ofGetElapsedTimef();
    noiseX = ofNoise(t*noiseSteps+noiseAmount)*100;
    noiseY = ofNoise(t*(noiseSteps*.834)+noiseAmount)*100;
    cout << noiseX << endl;
    cout << noiseY << endl;
    if (noiseX <= 30) {
        noiseX = 30;
    }else if (noiseX >= 70){
        noiseX = 70;
    }
    if (noiseY <= 30) {
        noiseY = 30;
    }else if (noiseY >= 70){
        noiseY = 70;
    }

    //i need to map the output of ofNoise from 1000 to 2000 in order to send the servos to those values
    serValX = ofMap(noiseX, 30, 70, 1000, 2000);
    serValY = ofMap(noiseY, 30, 70, 1000, 2000);
    
    //print the values for the servos (this will go to the Arduino later)
    cout << serValX << endl;
    cout << serValY << endl;
    
    //map for screen test
    posX = ofMap(noiseX, 30, 70, 0, ofGetWindowWidth());
    posY = ofMap(noiseY, 30, 70, 0, ofGetWindowHeight());
    
    
    
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    //BACKGROUND
    ofSetColor(0,5);//black with 5% alpha
    ofRect(0,0,ofGetWidth(),ofGetHeight());//cover screen with rectangle
    
    //VIRTUAL LASER POINTER & GITD TRAIL
    ofSetColor(0,255,0,90);//nice GITD green!
    ofCircle(posX, posY, 2);
    if ((posX = 0) || (posX = ofGetWindowWidth())){
        ofSetColor(0);
        ofCircle(posX, posY, 2);
    }
    if ((posY = 0) || (posY = ofGetWindowHeight())){
        ofSetColor(0);
        ofCircle(posX, posY, 2);
    }
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
