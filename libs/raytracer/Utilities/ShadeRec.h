#ifndef __SHADE_REC__
#define __SHADE_REC__

// this file contains the declaration of the class ShadeRec

#include <vector>

class Material;
class World;

// We need the following as #includes instead of forward class declarations,
// because we have the objects themselves, not pointers or references

#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "RGBColour.h"

class ShadeRec {
	public:
	
		bool				hit_an_object;		// Did the ray hit an object?
		Material* 			material_ptr;		// Pointer to the nearest object's material
		Point3D 			hit_point;			// World coordinates of intersection
		Point3D				local_hit_point;	// World coordinates of hit point on generic object (used for texture transformations)
		Normal				normal;				// Normal at hit point
		Ray					ray;				// Required for specular highlights and area lights
		int					depth;				// recursion depth
		float				t;					// ray parameter
		World&				w;					// World reference
		RGBColour            color;

		// changes for MT implementation for the Sampler Problems
		int					*count;	 // Count pointer to track the number of current sample
		int					*jump;   // Jump number used for every num_samples (per pixel)
		bool				sync;    // sync - used when there are multiple sample_hemispheres called (Environment light and AO)
		// Just stops the count and Jump from falling out of sync
				
		ShadeRec(World& wr);					// constructor
		
		ShadeRec(const ShadeRec& sr);			// copy constructor
};

#endif