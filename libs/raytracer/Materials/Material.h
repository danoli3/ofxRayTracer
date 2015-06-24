#ifndef __MATERIAL__
#define __MATERIAL__

#include "World.h"			// required for the shade function in all derived classes
#include "RGBColour.h"
#include "ShadeRec.h"
#include "ReferenceCount.h"

class Material : public ReferenceCount {	
	public:
	
		Material(void);						
		
		Material(const Material& material); 
		
		virtual Material*								
		clone(void) const = 0;	
				
		virtual 								
		~Material(void);
				
		virtual RGBColour
		shade(ShadeRec& sr);	
		
	protected:
	
		Material& 								
		operator= (const Material& rhs);						
};

#endif
