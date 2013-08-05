//---------------------------------------------------------------------------

#ifndef PolygonH
#define PolygonH

#include "Model.h"

 class CPolygon: public CModel
{

	void CalcNorm();
	public:
		T3dPoint* A;    // полигон
		T3dPoint* B;
		T3dPoint* C;
		TRay* norm;

		TIntersect *Intersect(T3dPoint* V, TRay* ray);
		TRay* Normal(T3dPoint* PInt);
};




//---------------------------------------------------------------------------
#endif
