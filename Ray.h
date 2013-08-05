//---------------------------------------------------------------------------

#ifndef RayH
#define RayH

#include <cmath>
using namespace std;

class TRay
{
	public:
		float a;
		float b;
		float c;
		TRay* Reflected(TRay* norm);

};


//---------------------------------------------------------------------------
#endif
