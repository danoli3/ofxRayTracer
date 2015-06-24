#ifndef __RAY_CAST__
#define __RAY_CAST__

#include "Tracer.h"

class RayCast: public Tracer {
	public:
		
		RayCast(void);
		
		RayCast(World* _worldPtr);
				
		virtual											
		~RayCast(void);		

		virtual RGBColour	
		trace_ray(const Ray& ray) const;

		virtual RGBColour	
		trace_ray(const Ray ray, const int depth) const;
		
		virtual RGBColour	
		trace_ray(const Ray ray, const int depth, int &count, int &jump) const;
};

#endif