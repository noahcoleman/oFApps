#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    noiseSteps = 0.1; //smoothness (I think) **default = 0.1
    noiseAmount = 100; //speed of change (I think) **default = 100
    ofBackground(0);
    
}

//--------------------------------------------------------------
void testApp::update(){
    t = ofGetElapsedTimef();
    noiseX = ofNoise(t*noiseSteps+noiseAmount)*100;
    noiseY = ofNoise(t*(noiseSteps*2)+noiseAmount)*100;

    //i need to map the output of ofNoise from 1000 to 2000 in order to send the servos to those values
    serValX = ofMap(noiseX, 30, 70, 1000, 2000);
    serValY = ofMap(noiseY, 30, 70, 1000, 2000);
    
    //print the values for the servos (this will go to the Arduino later)
    cout << serValX << endl;
    cout << serValY << endl;
    
    //map for screen test
    circleX = ofMap(noiseX, 30, 70, 0, ofGetWindowWidth());
    circleY = ofMap(noiseY, 30, 70, 0, ofGetWindowHeight());
    
    
    
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofCircle(circleX, circleY, 20);

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
