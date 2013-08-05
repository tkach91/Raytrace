//---------------------------------------------------------------------------


#pragma hdrstop

#include "Lamp.h"

TRay* TLamp::GetRay(T3dPoint* PInt)
{
	TRay ray; //= new TRay;
	ray.a = Xc - PInt->X;          // падающий луч
	ray.b = Yc - PInt->Y;
	ray.c = Zc - PInt->Z;
	return &ray;
}


//---------------------------------------------------------------------------

#pragma package(smart_init)
