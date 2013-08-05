//---------------------------------------------------------------------------

#ifndef TypesH
#define TypesH

struct T3dPoint
{
	float X;
	float Y;
	float Z;
};

struct TRGBColor
{
  int r;
  int g;
  int b;
};

struct TIntersect
{
	int I;   //номер модели
	float Len; // расстояние до пересечения
	float Xp;
	float Yp;
	float Zp;
};




//---------------------------------------------------------------------------
#endif
