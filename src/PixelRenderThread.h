#pragma once
#include "ofMain.h"
#include "MultiThread.h"
#include "World.h"

const int NUMBER_TO_RENDER = 512;

class PixelRenderThread: public ofThread {
public:
	PixelRenderThread();
	~PixelRenderThread();
	void render(Pixel pixel);
	void update();
    int canRenderPixels();
    bool isPixelRendered();
    vector<RenderedPixel> & getRenderedPixels();
    void clearRenderedPixels();
    void setWorld(shared_ptr<World> world);
private:
	void threadedFunction();
	ofThreadChannel<Pixel> toRender;
	ofThreadChannel<RenderedPixel> rendered;
	int toBeRendered;
	vector<RenderedPixel> renderedPixels;
    shared_ptr<World> world;
};
