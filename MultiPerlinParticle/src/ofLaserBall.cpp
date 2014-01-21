//
//  ofLaserBall.cpp
//  MultiPerlinParticle
//
//  Created by Noah Coleman on 1/15/14.
//
//

#include "ofLaserBall.h"


ofLaserBall::ofLaserBall()
{
    
    noiseMultiplierX = ofRandom(0.001, 0.06);
    noiseMultiplierY = ofRandom(0.001, 0.06);
    noiseMultiplierG = ofRandom(0.001, 0.06);
    noiseMultiplierB = ofRandom(0.001, 0.06);

    noiseOffsetX = ofRandom(100, 10000);
    noiseOffsetY = ofRandom(100, 10000);
    noiseOffsetG = ofRandom(83, 937);
    noiseOffsetB = ofRandom(62, 336);
    
    noiseR = ofRandom(255);
    noiseB = ofMap(ofNoise(t*noiseMultiplierX+noiseOffsetX), 0, 1, 0, 255); //ofRandom(127);
    noiseG = ofMap(ofNoise(t*noiseMultiplierY+noiseOffsetY), 0, 1, 0, 255); //ofRandom(127, 255);
    
    
    diam = ofRandom(1.7, 2);

}

void ofLaserBall::update(){
    

    
    
    t = ofGetElapsedTimef();
    noiseX = ofNoise(t*noiseMultiplierX+noiseOffsetX);
    noiseY = ofNoise(t*noiseMultiplierY+noiseOffsetY);
    
    posX = ofMap(noiseX, 0, 1, -500, ofGetWindowWidth()+500);
    posY = ofMap(noiseY, 0, 1, -500, ofGetWindowHeight()+500);
    


    
}

void ofLaserBall::draw(){
    // values for R, G, B, A
    // ofSetColor(noiseR, noiseB, noiseG);
    ofSetColor(0,noiseG,noiseB, ofRandom(89,90));
    ofCircle(posX+ofRandom(-0.6,0.6), posY+ofRandom(-0.6,0.6), diam);
}