//---------------------------------------------------------------------------


#pragma hdrstop

#include "Hyper.h"
TIntersect* CHyper::IntersectX(T3dPoint* V, TRay* ray)
{
	TIntersect Res;
	double A,B,C,D;
	float t1,t2;
	A = -Bp*Bp*Cp*Cp*(ray->a)*(ray->a) +
		Ap*Ap*Cp*Cp*(ray->b)*(ray->b) +
		Ap*Ap*Bp*Bp*(ray->c)*(ray->c);

	B = 2*(-Bp*Bp*Cp*Cp*ray->a*(V->X - Xc) +
		   Ap*Ap*Cp*Cp*ray->b*(V->Y - Yc) +
		   Ap*Ap*Bp*Bp*ray->c*(V->Z - Zc));

	C = -Bp*Bp*Cp*Cp*(V->X - Xc)*(V->X - Xc) +
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
			Res.Xp = (V->X + ray->a*t1);
			if (fabs(Res.Xp - Xc)<(H/2))
			{
				Res.Len = t1;
				Res.Zp = (V->Z + ray->c*t1);
				Res.Yp = (V->Y + ray->b*t1);
				return &Res;
			}
			else
			{
				Res.Len = -1;
				return &Res;
			}
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
		float x1, x2;
		x1 = fabs(V->X + ray->a*t1 - Xc);
		x2 = fabs(V->X + ray->a*t2 - Xc);
		if ((t1*t2)<0)
		{
			if (((t2>0)&&(x2>H/2))||((t1>0)&&(x1>H/2)))
			{
				Res.Len = -1;
				return &Res;
			}
			if (t1<0)
			{
				Res.Len = t2;
			}
			else
			{
				Res.Len = t1;
			}
			Res.Xp = (V->X + ray->a*Res.Len);
			Res.Yp = (V->Y + ray->b*Res.Len);
			Res.Zp = (V->Z + ray->c*Res.Len);
			return &Res;
		}
		if ((x1>H/2)&&(x2>H/2))
		{
			Res.Len = -1;
			return &Res;
		}
		if ((x1>H/2)||((x2<H/2)&&(x1<H/2)&&(t2<t1)) )
		{
			Res.Len = t2;
		}
		else
		{
			Res.Len = t1;
		}
		Res.Xp = (V->X + ray->a*Res.Len);
		Res.Yp = (V->Y + ray->b*Res.Len);
		Res.Zp = (V->Z + ray->c*Res.Len);
		return &Res;
	}
}

TIntersect* CHyper::IntersectY(T3dPoint* V, TRay* ray)
{
	TIntersect Res;
	double A,B,C,D;
	float t1,t2;
	float Min=0;
	A = Bp*Bp*Cp*Cp*(ray->a)*(ray->a) -
		Ap*Ap*Cp*Cp*(ray->b)*(ray->b) +
		Ap*Ap*Bp*Bp*(ray->c)*(ray->c);

	B = 2*(Bp*Bp*Cp*Cp*ray->a*(V->X - Xc) -
		   Ap*Ap*Cp*Cp*ray->b*(V->Y - Yc) +
		   Ap*Ap*Bp*Bp*ray->c*(V->Z - Zc));

	C = Bp*Bp*Cp*Cp*(V->X - Xc)*(V->X - Xc) -
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
		if (t1>1e-2)

		{
			Res.Yp = (V->Y + ray->b*t1);
			if (fabs(Res.Yp - Yc)<(H/2))
			{
				Res.Len = t1;
				Res.Xp = (V->X + ray->a*t1);
				Res.Zp = (V->Z + ray->c*t1);
				return &Res;
			}
			else
			{
				Res.Len = -1;
				return &Res;
			}
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

	if ((t1<Min)&&(t2<Min))
	{
		Res.Len = -1;
		return &Res;
	}
	else
	{
		float y1, y2;
		y1 = fabs(V->Y + ray->b*t1 - Yc);
		y2 = fabs(V->Y + ray->b*t2 - Yc);
		if ((t1*t2)<0)
		{
			if (((t2>Min)&&(y2>H/2))||((t1>Min)&&(y1>H/2)))
			{
				Res.Len = -1;
				return &Res;
			}
			if (t1<Min)
			{
             	Res.Len = t2;

			}
			else
			{
				Res.Len = t1;
			}
			Res.Xp = (V->X + ray->a*Res.Len);
			Res.Yp = (V->Y + ray->b*Res.Len);
			Res.Zp = (V->Z + ray->c*Res.Len);
			return &Res;
		}
		if ((y1>H/2)&&(y2>H/2))
		{
			Res.Len = -1;
			return &Res;
		}
		if ((y1>H/2)||((y2<H/2)&&(y1<H/2)&&(t2<t1)) )
		{
			Res.Len = t2;
		}
		else
		{
			Res.Len = t1;
		}
		Res.Xp = (V->X + ray->a*Res.Len);
		Res.Yp = (V->Y + ray->b*Res.Len);
		Res.Zp = (V->Z + ray->c*Res.Len);
		return &Res;


	}
}

TIntersect* CHyper::IntersectZ(T3dPoint* V, TRay* ray)
{
	TIntersect Res;
	double A,B,C,D;
	float t1,t2;
	A = Bp*Bp*Cp*Cp*(ray->a)*(ray->a) +
		Ap*Ap*Cp*Cp*(ray->b)*(ray->b) -
		Ap*Ap*Bp*Bp*(ray->c)*(ray->c);

	B = 2*(Bp*Bp*Cp*Cp*ray->a*(V->X - Xc) +
		   Ap*Ap*Cp*Cp*ray->b*(V->Y - Yc) -
		   Ap*Ap*Bp*Bp*ray->c*(V->Z - Zc));

	C = Bp*Bp*Cp*Cp*(V->X - Xc)*(V->X - Xc) +
		Ap*Ap*Cp*Cp*(V->Y - Yc)*(V->Y - Yc) -
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
			Res.Zp = (V->Z + ray->c*t1);
			if (fabs(Res.Zp - Zc)<(H/2))
			{
				Res.Len = t1;
				Res.Xp = (V->X + ray->a*t1);
				Res.Yp = (V->Y + ray->b*t1);
				return &Res;
			}
			else
			{
				Res.Len = -1;
				return &Res;
			}

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
		/*if (((t2<=0)&&(t1>0)) ||( fabs(t1)<fabs(t2)&&t1>0))
			Res.Len = t1;
		else
			Res.Len = t2;
		Res.Xp = (V->X + ray->a*Res.Len);
		Res.Yp = (V->Y + ray->b*Res.Len);
		Res.Zp = (V->Z + ray->c*Res.Len);
		return &Res; */
		float z1, z2;
		z1 = fabs(V->Z + ray->c*t1 - Zc);
		z2 = fabs(V->Z + ray->c*t2 - Zc);
		if ((t1*t2)<0)
		{
			if (((t2>0)&&(z2>H/2))||((t1>0)&&(z1>H/2)))
			{
				Res.Len = -1;
				return &Res;
			}
			if (t1<0)
			{
             	Res.Len = t2;

			}
			else
			{
				Res.Len = t1;
			}
			Res.Xp = (V->X + ray->a*Res.Len);
			Res.Yp = (V->Y + ray->b*Res.Len);
			Res.Zp = (V->Z + ray->c*Res.Len);
			return &Res;
		}
		if ((z1>H/2)&&(z2>H/2))
		{
			Res.Len = -1;
			return &Res;
		}
		if ((z1>H/2)||((z2<H/2)&&(z1<H/2)&&(t2<t1)) )
		{
			Res.Len = t2;
		}
		else
		{
			Res.Len = t1;
		}
		Res.Xp = (V->X + ray->a*Res.Len);
		Res.Yp = (V->Y + ray->b*Res.Len);
		Res.Zp = (V->Z + ray->c*Res.Len);
		return &Res;
	}
}

TIntersect *CHyper::Intersect(T3dPoint* V, TRay* ray)
{
	TIntersect Hyp,P1,P2;
	switch (Ax)
	{
		case 'z': Hyp = *IntersectZ(V, ray); break;
		case 'y': Hyp = *IntersectY(V, ray); break;
		case 'x': Hyp = *IntersectX(V, ray); break;

	}

 //	P1 = *PlaneHypInt1(V,Model,ray);
//	P2 = PlaneHypInt2(V,Model,ray);
 //	if (Hyp.Len<P1.Len)
		return &Hyp;
 //	return &P1;
}

TRay* CHyper::Normal(T3dPoint* PInt)
{
	TRay norm;
	norm.a = (PInt->X - Xc)/(Ap*Ap);
	norm.b = (PInt->Y - Yc)/(Bp*Bp);
	norm.c = -(PInt->Z - Zc)/(Cp*Cp);
	return &norm;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
