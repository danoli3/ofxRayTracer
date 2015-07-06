#include "PixelRenderThread.h"
#include "ofConstants.h"

PixelRenderThread::PixelRenderThread()
:toBeRendered(0){
	// start the thread as soon as the
	// class is created, it won't use any CPU
	// until we send a new frame to be rendered
	startThread();
}

PixelRenderThread::~PixelRenderThread(){
	// when the class is destroyed
	// close both channels and wait for
	// the thread to finish
	toRender.close();
	rendered.close();
	waitForThread(true);
}

void PixelRenderThread::render(Pixel pixel){
	// send the pixel to the thread for rendering
	toRender.send(pixel);
    ++toBeRendered;
}

void PixelRenderThread::update(){
	// check if there's a new rendered pixel
	// tryReceive doesn't reallocate or make any copies
    RenderedPixel renderedPixel;
	while(rendered.tryReceive(renderedPixel)){
        renderedPixels.push_back(renderedPixel);
		--toBeRendered;
	}
}

int PixelRenderThread::canRenderPixels(){
    return (NUMBER_TO_RENDER - toBeRendered);
}

bool PixelRenderThread::isPixelRendered(){
    return (!renderedPixels.empty());
}

vector<RenderedPixel> & PixelRenderThread::getRenderedPixels(){
    return renderedPixels;
}

void PixelRenderThread::clearRenderedPixels(){
    renderedPixels.clear();
}

void PixelRenderThread::setWorld(shared_ptr<World> world){
    this->world = world;
}

void PixelRenderThread::threadedFunction(){
	while(isThreadRunning()){
		// wait until there's a new pixel
		// this blocks the thread, so it doesn't use
		// the CPU at all, until a pixel arrives.
		// also receive doesn't allocate or make any copies
		Pixel pixel = Pixel(0,0);
		if(toRender.receive(pixel)){
			// we have a new pixel, render it
            RenderedPixel renderedPixel = {Point2D(pixel.x,pixel.y),RGBColour(0,0,0)};
            
            // TODO: Put render code here
            world->render_scene(pixel, renderedPixel);

			// once rendered send the result back to the
			// main thread. in c++11 we can move it to
			// avoid a copy
#if __cplusplus>=201103
			rendered.send(std::move(renderedPixel));
#else
			rendered.send(renderedPixel);
#endif
		}else{
			// if receive returns false the channel
			// has been closed, go out of the while loop
			// to end the thread
			break;
		}
	}
}

