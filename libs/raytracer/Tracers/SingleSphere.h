#ifndef __SINGLE_SPHERE__
#define __SINGLE_SPHERE__

#include "Tracer.h"

class SingleSphere: public Tracer {
	public:
		
		SingleSphere(void);
										
		SingleSphere(World* _worldPtr);					
		
		virtual											
		~SingleSphere(void);
		
		virtual RGBColour	
		trace_ray(const Ray& ray) const;
};

#endif
