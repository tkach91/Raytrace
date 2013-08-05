//---------------------------------------------------------------------------

#ifndef CamH
#define CamH

#include "Cam.h"
#include "Ray.h"
#include "Types.h"

class TCam
{
	public:
	int Xc;
	int Yc;
	int Zc;
	int W;
	int H;
	int R;
	float alf;
	float tet;
	TRGBColor* BackGround;
	TRay* getRay(int x,int y);
	T3dPoint* LocToGlob(int x, int y, int z);
};



//---------------------------------------------------------------------------
#endif
