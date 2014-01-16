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
    
    noiseMultiplierX = ofRandom(0.1, 0.3);
    noiseMultiplierY = ofRandom(0.1, 0.3);
    
    diam = 2;

}

void ofLaserBall::update(){
    
    t += 0.12; // ofGetElapsedTimef();
    noiseX = ofNoise(t*noiseMultiplierX);
    noiseY = ofNoise(t*noiseMultiplierY);
    
    posX = ofMap(noiseX, 0, 1, 0, ofGetWindowWidth());
    posY = ofMap(noiseY, 0, 1, 0, ofGetWindowHeight());

    
}

void ofLaserBall::draw(){
    // values for R, G, B, A
    ofSetColor(0,255,0, 90);
    ofCircle(posX, posY, diam);
}