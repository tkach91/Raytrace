//---------------------------------------------------------------------------

#ifndef EllipseH
#define EllipseH

#include <cmath>
using namespace std;
#include "Model.h"
#include "Types.h"
#include "Ray.h"

class CEllipse: public CModel
{
	public:
		float Xc;    // ספונא
		float Yc;
		float Zc;

		float Ap;
		float Bp;
		float Cp;

		TIntersect *Intersect(T3dPoint* V, TRay* ray);
		TRay* Normal(T3dPoint* PInt);
};


//---------------------------------------------------------------------------
#endif
