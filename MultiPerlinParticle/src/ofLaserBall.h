//
//  ofLaserBall.h
//  MultiPerlinParticle
//
//  Created by Noah Coleman on 1/15/14.
//
//

#ifndef MultiPerlinParticle_ofLaserBall_h
#define MultiPerlinParticle_ofLaserBall_h
#include "ofMain.h"

class ofLaserBall{
    
public: // place public functions or variables declarations here
    
    // methods, equivalent to specific functions of your class objects
    void update();  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing
    
    // variables
    float t;      // time
    float noiseMultiplierX; // multiplier for ofNoise function
    float noiseMultiplierY;
    float noiseX; // noise
    float noiseY;
    float posX; // position
    float posY;
    
    int diam;      // size
    
    ofLaserBall(); // constructor - used to initialize an object, if no properties are passed
              //               the program sets them to the default value
    
private: // place private functions or variables declarations here
    
}; // dont't forget the semicolon!!


#endif
