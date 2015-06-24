// This is the declaration of the base class Tracer
// The tracer classes have no copy constructor, assignment operator. or clone function because 
// of the world pointer, which should not be assigned or copy constructed
// See comments in the World.h file.

#ifndef __TRACER__
#define __TRACER__

#include "Constants.h"
#include "Ray.h"
#include "RGBColour.h"

class World;

class Tracer {
	public:
	
		Tracer(void);									
		
		Tracer(World* _world_ptr);						
				
		virtual											
		~Tracer(void);									

		virtual RGBColour	
		trace_ray(const Ray& ray) const;

		virtual RGBColour	
		trace_ray(const Ray ray, const int depth) const;
		
		// Overloaded trace_ray for MT implementation
		virtual RGBColour	
		trace_ray(const Ray ray, const int depth, int &count, int &jump) const;
				
	protected:
	
		World* world_ptr;
};

#endif
