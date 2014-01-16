#pragma once

#include "ofMain.h"
#include "ofLaserBall.h"

#define NBALLS 1000

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    float t;
    float noiseX;
    float noiseY;
    float noiseStepsX;
    float noiseStepsY;
    float noiseAmount;
    int serValX;
    int serValY;
    float posX;
    float posY;
    
    ofLaserBall myLaserBall[NBALLS];
    
    

};
