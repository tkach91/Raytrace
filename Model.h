//---------------------------------------------------------------------------

#ifndef ModelH
#define ModelH

#include "types.h"
#include "Ray.h"

class CModel
{
	public:
		float Kd;
		float Ks;
		int p;
		char type;

		TRGBColor* Color;

		virtual TIntersect *Intersect(T3dPoint* V, TRay* ray) = 0;
		virtual TRay* Normal(T3dPoint* PInt) = 0;
};
//---------------------------------------------------------------------------
#endif
