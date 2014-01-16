#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    ofHideCursor();
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    // update the laser dots
    for(int i=0; i<NBALLS; i++)
    {
        myLaserBall[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    //BACKGROUND
    ofSetColor(0, 8);//black with 10% alpha
    ofRect(0,0,ofGetWidth(),ofGetHeight());//cover screen with rectangle
    
    // begin loop to draw the dots
    for(int i=0; i<NBALLS; i++)
    {
        myLaserBall[i].draw();
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
