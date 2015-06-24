// This file contains the definition of the class RGBColour

#include <math.h>

#include "RGBColour.h"

// -------------------------------------------------------- default constructor

RGBColour::RGBColour(void)
	: r(0.0), g(0.0), b(0.0) 							
{}


// -------------------------------------------------------- constructor

RGBColour::RGBColour(float c)
	: r(c), g(c), b(c) 							
{}
								

// -------------------------------------------------------- constructor

RGBColour::RGBColour(float _r, float _g, float _b)	
	: r(_r), g(_g), b(_b)
{}


// -------------------------------------------------------- copy constructor

RGBColour::RGBColour(const RGBColour& c)
	: r(c.r), g(c.g), b(c.b)
{} 				 
		

// -------------------------------------------------------- destructor

RGBColour::~RGBColour(void)		
{}


// --------------------------------------------------------assignment operator

RGBColour& 											
RGBColour::operator= (const RGBColour& rhs) {
	if (this == &rhs)
		return (*this);

	r = rhs.r; g = rhs.g; b = rhs.b;

	return (*this);
}
 

// -------------------------------------------------------- powc
// raise each component to the specified power
// used for color filtering in Chapter 28

RGBColour
RGBColour::powc(float p) const {
	return (RGBColour(pow(r, p), pow(g, p), pow(b, p)));
}

