//---------------------------------------------------------------------------


#pragma hdrstop

#include "Sphere.h"


TIntersect *CSphere::Intersect(T3dPoint* V, TRay* ray)
{
	//////
	//T3dPoint* V = new T3dPoint;
	TIntersect Res; // = new TIntersect;

	float A,B,C,D;
	float t1,t2;
	A = (ray->a)*(ray->a) + (ray->b)*(ray->b) + (ray->c)*(ray->c);
	B = 2*(ray->a*(V->X - Xc) + ray->b*(V->Y - Yc) +
		   ray->c*(V->Z - Zc));
	C = (V->X - Xc)*(V->X - Xc) +
		(V->Y - Yc)*(V->Y - Yc) +
		(V->Z - Zc)*(V->Z - Zc) -
		(R)*(R);
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
//////////////////////////////////////////////////////////
	if (fabs(t1)<1e-3)
	{
		if (fabs(t2)<1e-3)
		{
			Res.Len = -1;
			return &Res;
		}
		else
		{
			Res.Len = t2;
			Res.Xp = (V->X + ray->a*t2);
			Res.Yp = (V->Y + ray->b*t2);
			Res.Zp = (V->Z + ray->c*t2);
			return &Res;
		}
	}
	if (fabs(t2)<1e-3)
	{
		Res.Len = t1;
		Res.Xp = (V->X + ray->a*t1);
		Res.Yp = (V->Y + ray->b*t1);
		Res.Zp = (V->Z + ray->c*t1);
		return &Res;
	}
	///////////////////////////////////////////////////
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

TRay* CSphere::Normal(T3dPoint* PInt)
{
	TRay norm; //= new TRay;
	norm.a = PInt->X - Xc;      // нормаль
	norm.b = PInt->Y - Yc;
	norm.c = PInt->Z - Zc;
	return &norm;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
