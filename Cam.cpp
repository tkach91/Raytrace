//---------------------------------------------------------------------------


#pragma hdrstop

#include "Cam.h"

    float Mloc[1][4];
	float Mp[4][4];
	float Mgl[1][4];

TRay* TCam::getRay(int x,int y)
{
	TRay ray;// = new TRay;
	T3dPoint V; // = new T3dPoint;
	T3dPoint Pix;// = new T3dPoint;

	V = *LocToGlob(0, 0, R);
	Pix.X = x - (W/2);
	Pix.Y = H/2 - y;
	Pix = *LocToGlob(Pix.X, Pix.Y, 0);

	ray.a = Pix.X - V.X;
	ray.b = Pix.Y - V.Y;
	ray.c = Pix.Z - V.Z;
	return &ray;
}

T3dPoint* TCam::LocToGlob(int x, int y, int z)
{
	T3dPoint G; //= new T3dPoint;

	//float **Mp;
	//float **Mgl;
	int i,j,t;
	int M=1,N=4,K=4;

	/*Mloc = (float **)malloc(sizeof(float *)*M);
	for (i=0;i<M;i++)
		Mloc[i] = (float *)malloc(sizeof(float)*N);

	Mp = (float **)malloc(sizeof(float *)*N);
	for (i=0;i<N;i++)
		Mp[i] = (float *)malloc(sizeof(float)*K);

	Mgl = (float **)malloc(sizeof(float *)*M);
	for (i=0;i<M;i++)
		Mgl[i] = (float *)malloc(sizeof(float)*K);
	  */
	Mloc[0][0] = (float)x;
	Mloc[0][1] = (float)y;
	Mloc[0][2] = (float)z;
	Mloc[0][3] = 1;

	Mp[0][0] = -cos(alf);
	Mp[0][1] = sin(alf);
	Mp[0][2] = 0;
	Mp[0][3] = 0;

	Mp[1][0] = -sin(alf)*sin(tet);
	Mp[1][1] = -sin(tet)*cos(alf);
	Mp[1][2] = cos(tet);
	Mp[1][3] = 0;

	Mp[2][0] = -sin(alf)*cos(tet);
	Mp[2][1] = -cos(alf)*cos(tet);
	Mp[2][2] = -sin(tet);
	Mp[2][3] = 0;

	Mp[3][0] = (float)Xc;
	Mp[3][1] = (float)Yc;
	Mp[3][2] = (float)Zc;
	Mp[3][3] = 1;

	int S;
	for (i=0;i<M;i++)
		for (j=0;j<K;j++)
		{
			S=0;
			for (t=0;t<N;t++)
				S+= Mloc[i][t]*Mp[t][j];
			Mgl[i][j] = S;
		}

	G.X = (Mgl[0][0]);
	G.Y = (Mgl[0][1]);
	G.Z = (Mgl[0][2]);
	//free(Mloc);
	//free(Mp);
	//free(Mgl);
	return &G;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
