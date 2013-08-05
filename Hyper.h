//---------------------------------------------------------------------------

#ifndef HyperH
#define HyperH

#include "Model.h"
#include <cmath>
using namespace std;
#include "Model.h"
#include "Types.h"
#include "Ray.h"

class CHyper: public CModel
{
	private:

		TIntersect* IntersectX(T3dPoint* V, TRay* ray);
		TIntersect* IntersectY(T3dPoint* V, TRay* ray);
		TIntersect* IntersectZ(T3dPoint* V, TRay* ray);
	public:

		float Xc;    // сфера
		float Yc;
		float Zc;

		float Ap;
		float Bp;   //  полуоси
		float Cp; //  эллипсоида и гиперболоида
		float H;  // высота гиперболоида
		char Ax; // ось вращения гиперболоида


		TIntersect *Intersect(T3dPoint* V, TRay* ray);
		TRay* Normal(T3dPoint* PInt);
};

//---------------------------------------------------------------------------
#endif
