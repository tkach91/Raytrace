//---------------------------------------------------------------------------


#pragma hdrstop


#include "Scene.h"


void CScene::RenderImage()
{
	int x,y,rek,K;
	char r,g,b;

	TRay ray;
	T3dPoint Vcam;
	T3dPoint* V;
	TRGBColor Col;
	TColor col;

	Vcam = *Cam->LocToGlob(0,0,Cam->R);

	K = -1;
	for (x=0; x < Cam->W; x++)
		for (y = 0; y < Cam->H; y++)
		{
		  rek=0;
		  ray = *(Cam->getRay(x,y));      // разыменование = обращение по адресу
		  V = &Vcam;
		  Col = *getColor(rek, K,&Vcam,V, &ray);

		  r = (char)Col.r;
		  g = (char)Col.g;
		  b = (char)Col.b;
		  col = RGB(r, g, b);
		 // SetPixel(hdc, x, y, col);
			Canvas->Pixels[x][y] = col;
		}
}


TIntersect*  CScene::findInt(int K, T3dPoint* V, TRay* ray)
{
	TIntersect tMin;
	TIntersect temp;

	tMin.I = -1;
	tMin.Len = -1;

	int i;
	for (i = 0; i < Models.size(); i++)
	{
		if (i != K)
		{
			temp = *Models[i]->Intersect(V, ray);
			temp.I = i;
			if (temp.Len != -1)
			{
				if ((temp.Len < tMin.Len) || (tMin.Len == -1))
				{
					tMin = temp;
				}
			}
		}
	}
   //	delete temp;
	return &tMin;
}



TRay* MulVect(T3dPoint* A1, T3dPoint* A2, T3dPoint* B1, T3dPoint* B2)
{
	float X1 = A2->X - A1->X;          // AB * AD
	float Y1 = A2->Y - A1->Y;
	float Z1 = A2->Z - A1->Z;

	float X2 = B2->X - B1->X;
	float Y2 = B2->Y - B1->Y;
	float Z2 = B2->Z - B1->Z;
	TRay Res;
	Res.a = Y1*Z2 - Y2*Z1;
	Res.b = X1*Z2 - X2*Z1;
	Res.c = X1*Y2 - X2*Y1;
	return &Res;
}




float getCos(TRay* X,TRay* Y)
{
	float Cos, Lray, Lnorm;
	Lray = sqrt(X->a*X->a + X->b*X->b + X->c*X->c);
	Lnorm = sqrt(Y->a*Y->a + Y->b*Y->b + Y->c*Y->c);

	Cos =  (X->a*Y->a + X->b*Y->b + X->c*Y->c)/(Lray*Lnorm);


	return Cos;
}

TRay* LookRay(T3dPoint* V, T3dPoint* PInt)
{
	TRay look; // = new TRay;
	look.a = V->X - PInt->X;     // направление взгляда
	look.b = V->Y - PInt->Y;
	look.c = V->Z - PInt->Z;
  //	delete V;
	return &look;
}

TRGBColor* CScene::getColor(int rek, int K,T3dPoint* Vcam,T3dPoint* V, TRay* ray)
{
	TRGBColor Col;// = new TRGBColor;
	TIntersect* Intersect = findInt(K, V, ray);

	if (Intersect->I == -1)
		return Cam->BackGround;

	int i = Intersect->I;
	T3dPoint PInt; //= new T3dPoint;
	PInt.X = Intersect->Xp;
	PInt.Y = Intersect->Yp;
	PInt.Z = Intersect->Zp;
  //	memcpy(Col, Models[i]->Color, sizeof(TRGBColor)) ;
	Col.r = Models[i]->Color->r;
	Col.g = Models[i]->Color->g;
	Col.b = Models[i]->Color->b;
	float R = Ka*Col.r;
	float G = Ka*Col.g;
	float B = Ka*Col.b;
	float Cos,Cos_b;
	TRay lampray;
	TRay norm;
	TRay ref;
	TRay look;
	TIntersect Shad;

	look = *LookRay(Vcam,&PInt);

	norm = *Models[i]->Normal(&PInt);

	int j;
	for (j = 0; j < Lamps.size(); j++)
	{
		lampray = *(Lamps[j]->GetRay(&PInt));
		ref = *(lampray.Reflected(&norm));
		Cos = getCos(&lampray,&norm);
		Cos_b = getCos(&look,&ref);
		if (Cos<0) Cos=0;
		Shad = *findInt(i, &PInt, &lampray);
		if (Shad.Len == -1)
		{
			R += Col.r*Lamps[j]->Ir*(Models[i]->Kd*Cos+ Models[i]->Ks*pow(Cos_b,Models[i]->p));
			if (R>255) R=255;
			G += Col.g*Lamps[j]->Ig*(Models[i]->Kd*Cos+ Models[i]->Ks*pow(Cos_b,Models[i]->p));
			if (G>255) G=255;
			B += Col.b*Lamps[j]->Ib*(Models[i]->Kd*Cos+ Models[i]->Ks*pow(Cos_b,Models[i]->p));
			if (B>255) B=255;
		}

	}

	if (rek<MaxRek)
	{
		rek++;
		ref = *ray->Reflected(&norm);
		TRGBColor C = *getColor(rek, i, Vcam, &PInt,&ref);
		R += Models[i]->Ks*C.r;
		if (R>255) R=255;
		G += Models[i]->Ks*C.g;
		if (G>255) G=255;
		B += Models[i]->Ks*C.b;
		if (B>255) B=255;
	}

	Col.r = (int)(R+0.5);
	Col.g = (int)(G+0.5);
	Col.b = (int)(B+0.5);
   //	delete PInt;
	return &Col;
}

void CScene::LoadFromFile(char *filename)
{
	Models.clear();
	Lamps.clear();

	FILE *f = fopen(filename, "r");
	int size;
	fscanf(f, "%d\n", &size);

	for (int i = 0; i < size; i++)
	{
		char type;
		fscanf(f, "%c\n", &type);
		if (type == 'h')
		{
			CHyper *Hyper = new CHyper;
			Hyper->type = 'h';

			fscanf(f, "%f\n", &Hyper->Xc);
			fscanf(f, "%f\n", &Hyper->Yc);
			fscanf(f, "%f\n", &Hyper->Zc);
			fscanf(f, "%f\n", &Hyper->Ap);
			fscanf(f, "%f\n", &Hyper->Bp);
			fscanf(f, "%f\n", &Hyper->Cp);
			fscanf(f, "%f\n", &Hyper->H);

			fscanf(f, "%f\n", &Hyper->Kd);
			fscanf(f, "%f\n", &Hyper->Ks);
			fscanf(f, "%d\n", &Hyper->p);
			Hyper->Color = new TRGBColor;
			fscanf(f, "%d\n", &Hyper->Color->r);
			fscanf(f, "%d\n", &Hyper->Color->g);
			fscanf(f, "%d\n", &Hyper->Color->b);
			fscanf(f, "%c\n", &Hyper->Ax);

			Models.push_back(Hyper);
		}
		else if (type == 'p')
		{
			CPolygon *Polygon = new CPolygon;
			Polygon->type = 'p';

			Polygon->A = new T3dPoint;
			fscanf(f, "%f\n", &Polygon->A->X);
			fscanf(f, "%f\n", &Polygon->A->Y);
			fscanf(f, "%f\n", &Polygon->A->Z);

			Polygon->B = new T3dPoint;
			fscanf(f, "%f\n", &Polygon->B->X);
			fscanf(f, "%f\n", &Polygon->B->Y);
			fscanf(f, "%f\n", &Polygon->B->Z);

			Polygon->C = new T3dPoint;
			fscanf(f, "%f\n", &Polygon->C->X);
			fscanf(f, "%f\n", &Polygon->C->Y);
			fscanf(f, "%f\n", &Polygon->C->Z);

			fscanf(f, "%f\n", &Polygon->Kd);
			fscanf(f, "%f\n", &Polygon->Ks);
			fscanf(f, "%d\n", &Polygon->p);

			Polygon->Color = new TRGBColor;
			fscanf(f, "%d\n", &Polygon->Color->r);
			fscanf(f, "%d\n", &Polygon->Color->g);
			fscanf(f, "%d\n", &Polygon->Color->b);

			Polygon->norm = NULL;

			Models.push_back(Polygon);
		}
		else if (type == 'e')
		{
			CEllipse *Ellipse = new CEllipse;
			Ellipse->type = 'e';

			fscanf(f, "%f\n", &Ellipse->Xc);
			fscanf(f, "%f\n", &Ellipse->Yc);
			fscanf(f, "%f\n", &Ellipse->Zc);

			fscanf(f, "%f\n", &Ellipse->Ap);
			fscanf(f, "%f\n", &Ellipse->Bp);
			fscanf(f, "%f\n", &Ellipse->Cp);

			fscanf(f, "%f\n", &Ellipse->Kd);
			fscanf(f, "%f\n", &Ellipse->Ks);
			fscanf(f, "%d\n", &Ellipse->p);

			Ellipse->Color = new TRGBColor;
			fscanf(f, "%d\n", &Ellipse->Color->r);
			fscanf(f, "%d\n", &Ellipse->Color->g);
			fscanf(f, "%d\n", &Ellipse->Color->b);

			Models.push_back(Ellipse);
		}
		else if (type == 's')
		{
			CSphere *Sphere = new CSphere;
			Sphere->type = 's';

			fscanf(f, "%f\n", &Sphere->Xc);
			fscanf(f, "%f\n", &Sphere->Yc);
			fscanf(f, "%f\n", &Sphere->Zc);

			fscanf(f, "%f\n", &Sphere->R);

			fscanf(f, "%f\n", &Sphere->Kd);
			fscanf(f, "%f\n", &Sphere->Ks);
			fscanf(f, "%d\n", &Sphere->p);

			Sphere->Color = new TRGBColor;

			fscanf(f, "%d\n", &Sphere->Color->r);
			fscanf(f, "%d\n", &Sphere->Color->g);
			fscanf(f, "%d\n", &Sphere->Color->b);

			Models.push_back(Sphere);
		}

	}

	fscanf(f, "%d\n", &size);

	for (int i = 0; i < size; i++)
	{
		TLamp *L = new TLamp;
		fscanf(f, "%d\n", &L->Xc);
		fscanf(f, "%d\n", &L->Yc);
		fscanf(f, "%d\n", &L->Zc);

		fscanf(f, "%f\n", &L->Ir);
		fscanf(f, "%f\n", &L->Ig);
		fscanf(f, "%f\n", &L->Ib);
		Lamps.push_back(L);
	}

	fscanf(f, "%f\n", &Ka);

	fclose(f);
}

void CScene::SaveToFile(char *filename)
{
	FILE *f = fopen(filename, "w");
	fprintf(f, "%d\n", Models.size());

	for (int i = 0; i < Models.size(); i++)
	{
		fprintf(f, "%c\n", Models[i]->type);
		if (Models[i]->type == 'h')
		{
			CHyper *Hyper = (CHyper *)Models[i];

			fprintf(f, "%f\n", Hyper->Xc);
			fprintf(f, "%f\n", Hyper->Yc);
			fprintf(f, "%f\n", Hyper->Zc);
			fprintf(f, "%f\n", Hyper->Ap);
			fprintf(f, "%f\n", Hyper->Bp);
			fprintf(f, "%f\n", Hyper->Cp);
			fprintf(f, "%f\n", Hyper->H);

			fprintf(f, "%f\n", Hyper->Kd);
			fprintf(f, "%f\n", Hyper->Ks);
			fprintf(f, "%d\n", Hyper->p);
			fprintf(f, "%d\n", Hyper->Color->r);
			fprintf(f, "%d\n", Hyper->Color->g);
			fprintf(f, "%d\n", Hyper->Color->b);
			fprintf(f, "%c\n", Hyper->Ax);
		}
		else if (Models[i]->type == 'p')
		{
			CPolygon *Polygon = (CPolygon *)Models[i];

			fprintf(f, "%f\n", Polygon->A->X);
			fprintf(f, "%f\n", Polygon->A->Y);
			fprintf(f, "%f\n", Polygon->A->Z);

			fprintf(f, "%f\n", Polygon->B->X);
			fprintf(f, "%f\n", Polygon->B->Y);
			fprintf(f, "%f\n", Polygon->B->Z);

			fprintf(f, "%f\n", Polygon->C->X);
			fprintf(f, "%f\n", Polygon->C->Y);
			fprintf(f, "%f\n", Polygon->C->Z);

			fprintf(f, "%f\n", Polygon->Kd);
			fprintf(f, "%f\n", Polygon->Ks);
			fprintf(f, "%d\n", Polygon->p);

			fprintf(f, "%d\n", Polygon->Color->r);
			fprintf(f, "%d\n", Polygon->Color->g);
			fprintf(f, "%d\n", Polygon->Color->b);
		}
		else if (Models[i]->type == 'e')
		{
			CEllipse *Ellipse = (CEllipse *)Models[i];

			fprintf(f, "%f\n", Ellipse->Xc);
			fprintf(f, "%f\n", Ellipse->Yc);
			fprintf(f, "%f\n", Ellipse->Zc);

			fprintf(f, "%f\n", Ellipse->Ap);
			fprintf(f, "%f\n", Ellipse->Bp);
			fprintf(f, "%f\n", Ellipse->Cp);

			fprintf(f, "%f\n", Ellipse->Kd);
			fprintf(f, "%f\n", Ellipse->Ks);
			fprintf(f, "%d\n", Ellipse->p);

			fprintf(f, "%d\n", Ellipse->Color->r);
			fprintf(f, "%d\n", Ellipse->Color->g);
			fprintf(f, "%d\n", Ellipse->Color->b);
		}
		else if (Models[i]->type == 's')
		{
			CSphere *Sphere = (CSphere *)Models[i];

			fprintf(f, "%f\n", Sphere->Xc);
			fprintf(f, "%f\n", Sphere->Yc);
			fprintf(f, "%f\n", Sphere->Zc);

			fprintf(f, "%f\n", Sphere->R);

			fprintf(f, "%f\n", Sphere->Kd);
			fprintf(f, "%f\n", Sphere->Ks);
			fprintf(f, "%d\n", Sphere->p);

			fprintf(f, "%d\n", Sphere->Color->r);
			fprintf(f, "%d\n", Sphere->Color->g);
			fprintf(f, "%d\n", Sphere->Color->b);

        }

	}

	fprintf(f, "%d\n", Lamps.size());

	for (int i = 0; i < Lamps.size(); i++)
	{
		TLamp *L = Lamps[i];

		fprintf(f, "%d\n", L->Xc);
		fprintf(f, "%d\n", L->Yc);
		fprintf(f, "%d\n", L->Zc);

		fprintf(f, "%f\n", L->Ir);
		fprintf(f, "%f\n", L->Ig);
		fprintf(f, "%f\n", L->Ib);
	}

	fprintf(f, "%f\n", Ka);
	fclose(f);

}

//---------------------------------------------------------------------------

#pragma package(smart_init)
