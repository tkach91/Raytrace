//---------------------------------------------------------------------------

#ifndef SphereH
#define SphereH

#include "Model.h"

class CSphere: public CModel
{


	public:
		float Xc;    // ספונא
		float Yc;
		float Zc;
		float R;

		float Kd;
		float Ks;
		int p;

		TIntersect *Intersect(T3dPoint* V, TRay* ray);
		TRay* Normal(T3dPoint* PInt);
};



//---------------------------------------------------------------------------
#endif
