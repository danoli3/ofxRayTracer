#include "RayCast.h"
#include "World.h"
#include "ShadeRec.h"
#include "Material.h"

// -------------------------------------------------------------------- default constructor

RayCast::RayCast(void)
	: Tracer()
{}


// -------------------------------------------------------------------- constructor
		
RayCast::RayCast(World* _worldPtr)
	: Tracer(_worldPtr)
{}


// -------------------------------------------------------------------- destructor

RayCast::~RayCast(void) {}


// -------------------------------------------------------------------- trace_ray

RGBColour	
RayCast::trace_ray(const Ray& ray) const {
	ShadeRec sr(world_ptr->hit_objects(ray));
		
	if (sr.hit_an_object) {
		sr.ray = ray;			// used for specular shading
		return (sr.material_ptr->shade(sr));
	}   
	else
		return (world_ptr->background_color);
}


// -------------------------------------------------------------------- trace_ray
// this ignores the depth argument

RGBColour	
RayCast::trace_ray(const Ray ray, const int depth) const {
	ShadeRec sr(world_ptr->hit_objects(ray));
	if (sr.hit_an_object) {
		sr.ray = ray;			// used for specular shading
		return (sr.material_ptr->shade(sr));
	}   
	else
		return (world_ptr->background_color);
}

RGBColour	
RayCast::trace_ray(const Ray ray, const int depth, int &count, int &jump) const {
	ShadeRec sr(world_ptr->hit_objects(ray));
	sr.count = &count;
	sr.jump = &jump;
	if (sr.hit_an_object) {
		sr.ray = ray;			// used for specular shading
		return (sr.material_ptr->shade(sr));
	}   
	else
		return (world_ptr->background_color);
}

