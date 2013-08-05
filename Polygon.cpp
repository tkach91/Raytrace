//---------------------------------------------------------------------------


#pragma hdrstop

#include "Polygon.h"

void CPolygon::CalcNorm()
{
	TRay* N = new TRay;
	float Xab = B->X - A->X;
	float Yab = B->Y - A->Y;
	float Zab = B->Z - A->Z;

	float Xac = C->X - A->X;
	float Yac = C->Y - A->Y;
	float Zac = C->Z - A->Z;

	N->a = Yab*Zac - Yac*Zab;
	N->b = Xab*Zac - Xac*Zab;
	N->c = Xab*Yac - Xac*Yab;
   //	TRay N1;
 //	//N1 = *MulVect(A, B, A, C);
   //	N1 = &N;
	norm = N;//MulVect(A, B, A, C);;
}

TIntersect *CPolygon::Intersect(T3dPoint* V, TRay* ray)
{
    	////
	float A, B, C, M, T;
	T3dPoint D;
//   	TRay N1,N2,N3;
	TIntersect Res;
	Normal(NULL);
	A = norm->a;
	B = norm->b;
	C = norm->c;
	M = -A*(this->A->X) - B*(this->A->Y) - C*(this->A->Z);
	T =  A*ray->a + B*ray->b + C*ray->c;
	if (T == 0)
	{
		Res.Len = -1;
		return &Res;
	}
	T = -(A*V->X + B*V->Y + C*V->Z + M)/T;
	if (T<1e-3)
	{
		Res.Len = -1;
		return &Res;
	}
	Res.Len = T;
	Res.Xp = (V->X + ray->a*T);
	Res.Yp = (V->Y + ray->b*T);
	Res.Zp = (V->Z + ray->c*T);
	return &Res;
	///////////////////////////////////////////////
    /*	D.X = (V->X + ray->a*T);
	D.Y = (V->Y + ray->b*T);
	D.Z = (V->Z + ray->c*T);
	N1 = *MulVect(A, B, A, &D);
	N2 = *MulVect(B, C, B, &D);
	N3 = *MulVect(C, A, C, &D);

	if ((N1.a*N2.a > 0)&&(N1.b*N2.b > 0)&&(N1.c*N2.c > 0))
	{
		if ((N1.a*N3.a > 0)&&(N1.b*N3.b > 0)&&(N1.c*N3.c > 0))
		{
			Res.Len = T;
			Res.Xp = D.X;
			Res.Yp = D.Y;
			Res.Zp = D.Z;
			return &Res;
		}
	}
	Res.Len = -1;
	return &Res;        */
}

TRay* CPolygon::Normal(T3dPoint* PInt)
{
	if (norm == NULL)
	{
		norm = new TRay;
		CalcNorm();
	}
	return norm;
}


//---------------------------------------------------------------------------

#pragma package(smart_init)
