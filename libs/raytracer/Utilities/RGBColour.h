#ifndef __RGB_COLOR__
#define __RGB_COLOR__

// This file contains the declaration of the class RGBColour

//------------------------------------------------------------ class RGBColour
class RGBColour {
	
	public:
	
		float	r, g, b;									
				
	public:
	
		RGBColour(void);										// default constructor
		RGBColour(float c);									// constructor
		RGBColour(float _r, float _g, float _b);				// constructor
		RGBColour(const RGBColour& c); 						// copy constructor
		
		~RGBColour(void);									// destructor
		
		RGBColour& 											// assignment operator
		operator= (const RGBColour& rhs); 

		RGBColour 											// addition
		operator+ (const RGBColour& c) const;	

		RGBColour& 											// compound addition
		operator+= (const RGBColour& c);
		
		RGBColour 											// multiplication by a float on the right
		operator* (const float a) const;
		
		RGBColour& 											// compound multiplication by a float on the right
		operator*= (const float a);					
				
		RGBColour 											// division by a float
		operator/ (const float a) const;
		
		RGBColour& 											// compound division by a float
		operator/= (const float a); 
				
		RGBColour 											// component-wise multiplication
		operator* (const RGBColour& c) const;
		
		bool												// are two RGBColours the same?
		operator== (const RGBColour& c) const;				

		RGBColour											// raise components to a power
		powc(float p) const;
		
		float												// the average of the components
		average(void) const;
};



// inlined member functions

// ----------------------------------------------------------------------- operator+
// addition of two colors

inline RGBColour 
RGBColour::operator+ (const RGBColour& c) const {
	return (RGBColour(r + c.r, g + c.g, b + c.b));
}


// ----------------------------------------------------------------------- operator+=
// compound addition of two colors

inline RGBColour& 
RGBColour::operator+= (const RGBColour& c) {
	r += c.r; g += c.g; b += c.b;
    return (*this);
}


// ----------------------------------------------------------------------- operator*
// multiplication by a float on the right

inline RGBColour 
RGBColour::operator* (const float a) const {
	return (RGBColour (r * a, g * a, b * a));	
}


// ----------------------------------------------------------------------- operator*=
// compound multiplication by a float on the right

inline RGBColour& 
RGBColour::operator*= (const float a) {
	r *= a; g *= a; b *= a;
	return (*this);
}


// ----------------------------------------------------------------------- operator/
// division by float

inline RGBColour 
RGBColour::operator/ (const float a) const {
	return (RGBColour (r / a, g / a, b / a));
}


// ----------------------------------------------------------------------- operator/=
// compound division by float

inline RGBColour& 
RGBColour::operator/= (const float a) {	
	r /= a; g /= a; b /= a;
	return (*this);
}



// ----------------------------------------------------------------------- operator*
// component-wise multiplication of two colors

inline RGBColour 
RGBColour::operator* (const RGBColour& c) const {
	return (RGBColour (r * c.r, g * c.g, b * c.b));
} 


// ----------------------------------------------------------------------- operator==
// are two RGBColours the same?

inline bool
RGBColour::operator== (const RGBColour& c) const {
	return (r == c.r && g == c.g && b == c.b);
}


// ----------------------------------------------------------------------- average
// the average of the three components

inline float											
RGBColour::average(void) const {
	return (0.333333333333 * (r + g + b));
}




// inlined non-member function

// ----------------------------------------------------------------------- operator*
// multiplication by a float on the left

RGBColour 
operator* (const float a, const RGBColour& c);

inline RGBColour 
operator* (const float a, const RGBColour& c) {
	return (RGBColour (a * c.r, a * c.g, a * c.b));	
}


#endif
