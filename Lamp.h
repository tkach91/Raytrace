//---------------------------------------------------------------------------

#ifndef LampH
#define LampH

#include "Types.h"
#include "Ray.h"

class TLamp
{
	public:
		int Xc;
		int Yc;
		int Zc;
		float Ir;
		float Ig;
		float Ib;
		TRay *GetRay(T3dPoint* PInt);
};
//---------------------------------------------------------------------------
#endif
