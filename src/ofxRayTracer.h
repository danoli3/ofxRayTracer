#pragma once

#include "ofMain.h"

#include <stdlib.h>
#include <assert.h>
#include <map>
#include <list>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

#include "PixelRenderThread.h"
#include "World.h"
#include <vector>

class ofxRayTracer : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofColor convertColor(double r, double g, double b);
	
private:
	shared_ptr<ofTexture> toRender;
    shared_ptr<ofTexture> rendered;
    
    PixelRenderThread renderer;
    
    ofPixels trackPixels;
    ofPixels renderedPixels;
    
    shared_ptr<World> world;
    int h;
    int w;
    int howManyRendered;
    int totalPixels;
};
