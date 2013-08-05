//---------------------------------------------------------------------------


#pragma hdrstop

#include "Ellipse.h"


TIntersect *CEllipse::Intersect(T3dPoint* V, TRay* ray)
{
	TIntersect Res;
	double A,B,C,D;
	float t1,t2;
	A = Bp*Bp*Cp*Cp*(ray->a)*(ray->a) +
		Ap*Ap*Cp*Cp*(ray->b)*(ray->b) +
		Ap*Ap*Bp*Bp*(ray->c)*(ray->c);

	B = 2*(Bp*Bp*Cp*Cp*ray->a*(V->X - Xc) +
		   Ap*Ap*Cp*Cp*ray->b*(V->Y - Yc) +
		   Ap*Ap*Bp*Bp*ray->c*(V->Z - Zc));

	C = Bp*Bp*Cp*Cp*(V->X - Xc)*(V->X - Xc) +
		Ap*Ap*Cp*Cp*(V->Y - Yc)*(V->Y - Yc) +
		Ap*Ap*Bp*Bp*(V->Z - Zc)*(V->Z - Zc) -
		Ap*Ap*Bp*Bp*Cp*Cp;
	if (A==0)
	{   if (B==0)
		{
			Res.Len = -1;
			return &Res;
		}
		t1 = -C/B;
		if (t1>0)
		{
		Res.Len = t1;
		Res.Xp = (V->X + ray->a*t1);
		Res.Yp = (V->Y + ray->b*t1);
		Res.Zp = (V->Z + ray->c*t1);
		return &Res;
		}
		else
		{
			Res.Len = -1;
			return &Res;
		}

	}

	D = B*B - 4*A*C;
	if (D < 0)
	{
		Res.Len = -1;
		return &Res;
	}
	t1 = (-B - sqrt(D))/(2*A);
	t2 = (-B + sqrt(D))/(2*A);
	if ((t1<=0)&&(t2<=0))
	{
		Res.Len = -1;
		return &Res;
	}
	else
	{
		if (((t2<=0)&&(t1>0)) || fabs(t1)<fabs(t2))
			Res.Len = t1;
		else
			Res.Len = t2;
		Res.Xp = (V->X + ray->a*Res.Len);
		Res.Yp = (V->Y + ray->b*Res.Len);
		Res.Zp = (V->Z + ray->c*Res.Len);
		return &Res;
	}


}

TRay* CEllipse::Normal(T3dPoint* PInt)
{
	TRay norm;
	norm.a = (PInt->X - Xc)/(Ap*Ap);
	norm.b = (PInt->Y - Yc)/(Bp*Bp);
	norm.c = (PInt->Z - Zc)/(Cp*Cp);
	return &norm;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
