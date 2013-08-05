//---------------------------------------------------------------------------


#pragma hdrstop

#include "Ray.h"


TRay* TRay::Reflected(TRay* norm)
{
	TRay ref;// = new TRay;
	float Cos, Lray, Lnorm;
	Lray = sqrt(a*a + b*b + c*c);
	Lnorm = sqrt(norm->a*norm->a + norm->b*norm->b + norm->c*norm->c);
	Cos =  (a*norm->a + b*norm->b + c*norm->c)/(Lray*Lnorm);
	ref.a = -(2*Cos*Lray*norm->a/Lnorm - a);
	ref.b = -(2*Cos*Lray*norm->b/Lnorm - b);
	ref.c = -(2*Cos*Lray*norm->c/Lnorm - c);
	return &ref;

}

//---------------------------------------------------------------------------

#pragma package(smart_init)
