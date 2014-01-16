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
    
    noiseMultiplierX = ofRandom(0.0001, 0.01);
    noiseMultiplierY = ofRandom(0.0001, 0.01);
    noiseOffsetX = ofRandom(100, 10000);
    noiseOffsetY = ofRandom(100, 10000);
    
    diam = 2;

}

void ofLaserBall::update(){
    
    t += 0.12; // ofGetElapsedTimef();
    noiseX = ofNoise(t*noiseMultiplierX+noiseOffsetX);
    noiseY = ofNoise(t*noiseMultiplierY+noiseOffsetY);
    
    posX = ofMap(noiseX, 0, 1, -300, ofGetWindowWidth()+300);
    posY = ofMap(noiseY, 0, 1, -300, ofGetWindowHeight()+300);

    
}

void ofLaserBall::draw(){
    // values for R, G, B, A
    ofSetColor(0,255,0, 90);
    ofCircle(posX, posY, diam);
}