#include "ofxRayTracer.h"

//--------------------------------------------------------------
void ofxRayTracer::setup(){
	ofBackground(0, 0, 0);
    
	world = new World();
	world->build();
	
	int hres = world->vp.hres;
	int vres = world->vp.vres;

	int offset = 0;
	if(world->camera_ptr->get_stereo() == true)
	{	hres = hres * 2;
		offset = world->camera_ptr->get_offset();
		hres += offset;
	}
    
    howManyRendered = 0;
    
    w = hres;
    h = vres;
    totalPixels = w * h;
	
    ofLog(OF_LOG_NOTICE, "Hres:"+ofToString(hres));
    
	// Check samples
	//int currentSamples = w->vp.num_samples;
	//if(samples != currentSamples && samples != 0)
	// {
	//    w->vp.set_samples(samples);
	// }
    
    trackPixels.allocate(w,h,OF_PIXELS_RGBA);
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            trackPixels.setColor(x,y,ofColor::black);
            // 0 = not rendered
            // 1 = rendered
        }
    }
    
    renderedPixels.allocate(w,h,OF_PIXELS_RGBA);
    // Set the render pixels to Black and Alpha full
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            renderedPixels.setColor(x,y,ofColor(0,0,0,0));
        }
    }
    
    toRender = shared_ptr<ofTexture>(new ofTexture);
    rendered = shared_ptr<ofTexture>(new ofTexture);
    
    toRender->allocate(trackPixels);
    rendered->allocate(renderedPixels);
	
}

void ofxRayTracer::exit() {
	if(world)
	{
		delete world;
		world = NULL;
	}
}

//--------------------------------------------------------------
void ofxRayTracer::update(){
    
    
    if(howManyRendered < totalPixels ) {
        
        const int numberToRender = 512;
        int currentRender = 0;
        vector<Pixel> current;
        current.reserve(numberToRender);
        bool endLoop = false;
        for (int y = 0; y < h && endLoop == false; y++){
            for (int x = 0; x < w && endLoop == false; x++){
                if(trackPixels.getColor(x, y) == ofColor::black) {
                    currentRender++;
                    current.push_back(Pixel(x,y));
                }
                if(currentRender >= numberToRender) {
                    endLoop = true;
                }
            }
        }
        
        int iterations = current.size();
        for(int i = 0; i < iterations; i++){
            RenderedPixel render;
//          if(world->camera_ptr != NULL) {
//              world->camera_ptr->render_scene(*world, current[i], render);
//          } else {
                world->render_scene(current[i], render);
//          }
            
            renderedPixels.setColor(current[i].x, current[i].y, convertColor(render.color.r, render.color.g, render.color.b));
            trackPixels.setColor(current[i].x, current[i].y, ofColor::white);
            howManyRendered++;
        }
        toRender->loadData(trackPixels);
        rendered->loadData(renderedPixels);
    }

}

ofColor ofxRayTracer::convertColor(double r, double g, double b) {
    return ofColor(r*255.0f, g*255.0f, b*255.0f, 255.0f);
}


//--------------------------------------------------------------
void ofxRayTracer::draw(){
	ofBackground(128, 128, 128);
    ofSetColor(255,255,255,255);
    
    toRender->draw(0,0);
//    ofSetColor(255, 255, 255, 128);
    rendered->draw(0,0);
    
    
}

//--------------------------------------------------------------
void ofxRayTracer::keyPressed(int key){

}

//--------------------------------------------------------------
void ofxRayTracer::keyReleased(int key){

}

//--------------------------------------------------------------
void ofxRayTracer::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofxRayTracer::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxRayTracer::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxRayTracer::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxRayTracer::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofxRayTracer::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofxRayTracer::dragEvent(ofDragInfo dragInfo){ 

}