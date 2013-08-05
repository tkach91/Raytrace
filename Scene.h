//---------------------------------------------------------------------------

#ifndef SceneH
#define SceneH

#include <vector>
#include <cmath>

using namespace std;

#include "Cam.h"
#include "Model.h"
#include "Types.h"
#include "Lamp.h"

#include "Hyper.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "Sphere.h"

#include <Windows.h>
#include <Graphics.hpp>

class CScene
{
	private:
		vector<CModel *> Models;
		vector<TLamp *> Lamps;

		TIntersect*  findInt(int K, T3dPoint* V, TRay* ray);
	public:
		int MaxRek;
		TCam *Cam;
		float Ka;


		TCanvas *Canvas;

		void RenderImage();
		TRGBColor* getColor(int rek, int K,T3dPoint* Vcam,T3dPoint* V, TRay* ray);

		void AddModel(CModel *Model) { Models.push_back(Model); }
		void AddLamp(TLamp *Lamp) { Lamps.push_back(Lamp); }

		CModel *GetModel(int index) { return Models[index]; }
		TLamp *GetLamp(int index) { return Lamps[index]; }

		void DeleteModel(int index) { Models.erase(Models.begin() + index); }
		void DeleteLamp(int index) { Lamps.erase(Lamps.begin() + index); }

		int ModelCount() { return Models.size(); }
		int LampCount() { return Lamps.size(); }

		void LoadFromFile(char *filename);
		void SaveToFile(char *filename);
};

//---------------------------------------------------------------------------
#endif
