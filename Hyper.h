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

		float Xc;    // �����
		float Yc;
		float Zc;

		float Ap;
		float Bp;   //  �������
		float Cp; //  ���������� � ������������
		float H;  // ������ ������������
		char Ax; // ��� �������� ������������


		TIntersect *Intersect(T3dPoint* V, TRay* ray);
		TRay* Normal(T3dPoint* PInt);
};

//---------------------------------------------------------------------------
#endif
