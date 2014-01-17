#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    serial.setup("/dev/tty.usbmodem1421",9600);// make sure the serial port is correct (not sure how to get it on the pi?)
    
    ofSetFrameRate(30); // also the rate oF will try to send data over the serial
    
    // These variables will be obsolete once this program is ready for pi/arduino time
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    noiseMultiplierX = 0.1;
    noiseMultiplierY = 0.2;
    noiseOffsetX = ofRandom(100, 1000);
    noiseOffsetY = ofRandom(100, 1000);
    
}

//--------------------------------------------------------------
void testApp::update(){
    t = ofGetElapsedTimef();
    noiseX = ofNoise(t*noiseMultiplierX+noiseOffsetX);
    noiseY = ofNoise(t*noiseMultiplierY+noiseOffsetY);
    cout << noiseX << endl;
    cout << noiseY << endl;
    
    // SCREEN MAPPING (will become obsolete)
    posX = ofMap(noiseX, 0, 1, 0, ofGetWindowWidth());
    posY = ofMap(noiseY, 0, 1, 0, ofGetWindowHeight());

    
    // SERVO MAPPING (values from 1000 to 2000)
    // in order to "zoom" in on the distribution of the noise, it might
    // be necessary to map the values to 600 and 2400 or similar.  Then
    // I need to figure out how to turn the servos off in order not to break
    // them when they get sent past 1000/2000.
    
    serValX = ofMap(noiseX, 0, 1, 1000, 2000);
    serValY = ofMap(noiseY, 0, 1, 1000, 2000);
    
    // print the values for the servos (this will go to the Arduino later)
    cout << serValX << endl;
    cout << serValY << endl;

}

//--------------------------------------------------------------
void testApp::draw(){
    //This whole thing will be obsolete once I migrate to pi/arduino
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
