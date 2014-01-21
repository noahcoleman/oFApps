#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    serial.setup("/dev/tty.usbmodem1411",9600);// make sure the serial port is correct (not sure how to get it on the pi?)
    
    ofSetFrameRate(30); // also the rate oF will try to send data over the serial
    
    // These variables will be obsolete once this program is ready for pi/arduino time
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    noiseMultiplierX = ofRandom(0.05, 0.2);
    noiseMultiplierY = ofRandom(0.05, 0.2);
    noiseOffsetX = ofRandom(100, 1000);
    noiseOffsetY = ofRandom(100, 1000);
    
}

//--------------------------------------------------------------
void testApp::update(){
    t = ofGetElapsedTimef() ;
    noiseX = ofNoise(t*noiseMultiplierX+noiseOffsetX);
    noiseY = ofNoise(t*noiseMultiplierY+noiseOffsetY);
//    cout << noiseX << endl;
//    cout << noiseY << endl;
    
    // SERVO MAPPING (values from 1000 to 2000)  **Actually, I am going to map these to 1000-2000 when they get to the Arduino,
    // so I'm mapping them as unsigned chars from 0 to 254. clamping is set to TRUE so it is always between 0-254
    
    serValX = ofMap(noiseX, 0.3, 0.7, 0, 254, true);
    serValY = ofMap(noiseY, 0.3, 0.7, 0, 254, true);
    
    // print the values for the servos (this will go to the Arduino later)
    cout << serValX << endl;
    cout << serValY << endl;
    
    // send the x byte
    serial.writeByte(serValX);
    
    // send the y byte
    serial.writeByte(serValY);
    
    // since we do not allow the range to go outside 0-254, we can send the 255
    // byte as a packet boundary marker to signal the end of our packet.
    serial.writeByte(255);
    
    // REMEMBER that this is sending bytes to the arduino quite quickly
    // 30 times / second (see ofSetFrameRate above).  Thus, on the Arduino
    // end you will only get quick responsiveness if you do your best to avoid
    // using delays in your code!  Otherwise the Arduino Serial ring buffer will fill
    // (because it is getting too much data too fast) and you will start losing
    // data points.

    // SCREEN MAPPING (will become obsolete)
    posX = ofMap(serValX, 0, 254, 0, ofGetWindowWidth());
    posY = ofMap(serValY, 0, 254, 0, ofGetWindowHeight());


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
