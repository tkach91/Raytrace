//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

TCam* Cam = new TCam;
CScene *Scene = new CScene;

int Nm,Nl;
double t1,t2;
float dalf,dtet;
//
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	Cam->alf = 3*M_PI/2;
	Cam->tet = 0;
	Edit37->Text = FloatToStrF(Cam->tet*180/M_PI,ffGeneral,3,2);
	Edit38->Text = FloatToStrF(Cam->alf*180/M_PI,ffGeneral,3,2);
	t1 = clock();
	Label1->Caption = "Идёт построение изображения";
	Form1->Refresh();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

	Scene->Cam = Cam;

	Scene->Canvas = Image1->Canvas;

	Scene->Ka = 0.2;
	Scene->MaxRek = 3;
	dalf = 10*M_PI/180;
	dtet = 10*M_PI/180;
	Cam->alf = 3*M_PI/2;
	Cam->tet = 0;
	int i;


	Cam->W = Image1->Width;
	Cam->H = Image1->Height;
	Cam->Xc = 0;
	Cam->Yc = 0;
	Cam->Zc = 100;
	Cam->R = 500;
	TRGBColor* B = new TRGBColor;
	B->r = 0;
	B->g = 0;
	B->b = 0;
	Cam->BackGround = B;

	CHyper *H = new CHyper;

	H->Xc = 150.0;
	H->Yc = 130.0;
	H->Zc = 50.0;
	H->Ap = 50.0;
	H->Bp = 50.0;
	H->Cp = 60;
	H->H = 150;
	H->Kd = 1;
	H->Ks = 0.6;
	H->p = 100;
	H->type = 'h';
	H->Ax = 'z';
	TRGBColor* Col1 = new TRGBColor;
	Col1->r = 200;
	Col1->g = 50;
	Col1->b = 150;
	H->Color = Col1;

	Scene->AddModel(H);

	CEllipse *Ellps = new CEllipse;
	Ellps->Xc = -150.0;
	Ellps->Yc = -50.0;
	Ellps->Zc = 70.0;
	Ellps->Ap = 50.0;
	Ellps->Bp = 100.0;
	Ellps->Cp = 60.0;
	Ellps->Kd = 1;
	Ellps->Ks = 0.6;
	Ellps->p = 100;
	Ellps->type = 'e';
	TRGBColor* Col2 = new TRGBColor;
	Col2->r = 0;
	Col2->g = 200;
	Col2->b = 0;
	Ellps->Color = Col2;
	Scene->AddModel(Ellps);

	T3dPoint* A1 = new T3dPoint;
	T3dPoint* B1 = new T3dPoint;
	T3dPoint* C1 = new T3dPoint;
	A1->X  = 0;
	A1->Y = 50;
	A1->Z = 0;

	B1->X = -50;
	B1->Y = 0;
	B1->Z = 0;

	C1->X = 0;
	C1->Y = 0;
	C1->Z = 0;


	CPolygon *P = new CPolygon;
	P->A  = A1;
	P->B = B1;
	P->C = C1;
	P->Kd = 1;
	P->Ks = 0.6;
	P->norm = NULL;
	TRGBColor* Col4 = new TRGBColor;
	Col4->r = 30;
	Col4->g = 20;
	Col4->b = 130;
	P->Color = Col4;
	P->type = 'p';
	Scene->AddModel(P);

	CEllipse *Ellps1 = new CEllipse;
	Ellps1->Xc = 150.0;
	Ellps1->Yc = -150.0;
	Ellps1->Zc = 70.0;
	Ellps1->Ap = 50.0;
	Ellps1->Bp = 100.0;
	Ellps1->Cp = 60.0;
	Ellps1->Kd = 1;
	Ellps1->Ks = 0.6;
	Ellps1->p = 100;
	Ellps1->type = 'e';
	TRGBColor* Col5 = new TRGBColor;
	Col5->r = 200;
	Col5->g = 200;
	Col5->b = 0;
	Ellps1->Color = Col5;
	Scene->AddModel(Ellps1);

	TLamp *L1 = new TLamp;
	L1->Xc = 260;
	L1->Yc = -250;
	L1->Zc = 380;
	L1->Ir = 0.4;
	L1->Ig = 0.4;
	L1->Ib = 0.8;

	Scene->AddLamp(L1);

	L1 = new TLamp;
	L1->Xc = 300;
	L1->Yc = 80;
	L1->Zc = 400;
	L1->Ir = 0.5;
	L1->Ig = 0.3;
	L1->Ib = 0.2;

	Scene->AddLamp(L1);

	L1 = new TLamp;
	L1->Xc = 200;
	L1->Yc = 380;
	L1->Zc = 390;
	L1->Ir = 0.5;
	L1->Ig = 0.5;
	L1->Ib = 0;

	Scene->AddLamp(L1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
	dalf = StrToInt(Edit21->Text)*M_PI/180;
	t1 = clock();
	Label1->Caption = "Идёт построение изображения";
	Cam->alf += dalf;
	if (Cam->alf >= 2*M_PI)
		Cam->alf -= 2*M_PI;
	Edit38->Text = FloatToStrF(Cam->alf*180/M_PI,ffGeneral,3,2);
	Form1->Refresh();
   	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
	dalf = StrToInt(Edit21->Text)*M_PI/180;
	t1 = clock();
	Label1->Caption = "Идёт построение изображения";
	Cam->alf -= dalf;
	if (Cam->alf <= -2*M_PI)
		Cam->alf += 2*M_PI;
	Edit38->Text = FloatToStrF(Cam->alf*180/M_PI,ffGeneral,3,2);
	Form1->Refresh();
   	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
	Label1->Caption = "Идёт построение изображения";
	dtet = StrToInt(Edit21->Text)*M_PI/180;
	t1 = clock();
	Cam->tet -= dtet;
	if (Cam->tet <= -2*M_PI)
		Cam->tet += 2*M_PI;
	Edit37->Text = FloatToStrF(Cam->tet*180/M_PI,ffGeneral,3,2);
	Label1->Caption = "Идёт построение изображения";
	Form1->Refresh();
   	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
	Label1->Caption = "Идёт построение изображения";
	dtet = StrToInt(Edit21->Text)*M_PI/180;
	t1 = clock();
	Cam->tet += dtet;
	if (Cam->tet >= 2*M_PI)
		Cam->tet -= 2*M_PI;
	Edit37->Text = FloatToStrF(Cam->tet*180/M_PI,ffGeneral,3,2);
	Form1->Refresh();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
	InitListBox1();
	InitListBox2();
	Edit34->Text = FloatToStrF(Cam->Xc,ffGeneral,3,1);
	Edit35->Text = FloatToStrF(Cam->Yc,ffGeneral,3,1);
	Edit36->Text = FloatToStrF(Cam->Zc,ffGeneral,3,1);
	Edit37->Text = FloatToStrF(Cam->tet*180/M_PI,ffGeneral,3,2);
	Edit38->Text = FloatToStrF(Cam->alf*180/M_PI,ffGeneral,3,2);
	Edit39->Text = FloatToStrF(Scene->Ka,ffGeneral,3,2);
	Edit46->Text = IntToStr(Scene->MaxRek);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::InitListBox1()
{
	Form1->ListBox1->Clear();
	int i;
	for (int i = 0; i < Scene->ModelCount(); i++)
	{
		switch (Scene->GetModel(i)->type)
		{
			case 's': Form1->ListBox1->Items->Add(IntToStr(i+1) + ". Сфера"); break;
			case 'p': Form1->ListBox1->Items->Add(IntToStr(i+1) + ". Полигон"); break;
			case 'e': Form1->ListBox1->Items->Add(IntToStr(i+1) + ". Эллипсоид"); break;
			case 'h': Form1->ListBox1->Items->Add(IntToStr(i+1) + ". Гиперболоид"); break;
		}
	}
	if (Nm != 0)
	{
		Form1->ListBox1->ItemIndex = Nm-1;
	}
}
void __fastcall TForm1::InitListBox2()
{
    Form1->ListBox2->Clear();
	int i;
	for (i = 0; i < Scene->LampCount(); i++)
	{
		Form1->ListBox2->Items->Add(IntToStr(i+1) + ". Источник");
	}
	if (Nl != 0)
	{
		Form1->ListBox2->ItemIndex = Nl-1;
	}
}


void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
	int I = ListBox1->ItemIndex;
	if (I != -1)
	{
        Scene->DeleteModel(I);
		t1 = clock();
		Label1->Caption = "Идёт построение изображения";
		Form1->Refresh();
		Scene->RenderImage();
		t2= clock();
		Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
		InitListBox1();
	}

}
//---------------------------------------------------------------------------









void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
	CSphere* NewModel = new CSphere;
	NewModel->type = 's';
	NewModel->Xc = StrToFloat(Edit1->Text);
	NewModel->Yc = StrToFloat(Edit2->Text);
	NewModel->Zc = StrToFloat(Edit3->Text);
	NewModel->R = StrToFloat(Edit4->Text);
	NewModel->Kd = StrToFloat(Edit8->Text);
	NewModel->Ks = StrToFloat(Edit9->Text);
	NewModel->p = 100;
	TRGBColor *C = new TRGBColor;
	C->r = StrToInt(Edit5->Text);
	C->g = StrToInt(Edit6->Text);
	C->b = StrToInt(Edit7->Text);
	NewModel->Color = C;

	Scene->AddModel(NewModel);
	t1 = clock();
	Label1->Caption = "Идёт построение изображения";
	Form1->Refresh();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
	InitListBox1();

}
//---------------------------------------------------------------------------





void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{

	CEllipse* NewModel = new CEllipse;

	NewModel->type = 'e';
	NewModel->Xc = StrToFloat(Edit10->Text);
	NewModel->Yc = StrToFloat(Edit11->Text);
	NewModel->Zc = StrToFloat(Edit12->Text);
	NewModel->Ap = StrToFloat(Edit13->Text);
	NewModel->Bp = StrToFloat(Edit14->Text);
	NewModel->Cp = StrToFloat(Edit15->Text);

	NewModel->Kd = StrToFloat(Edit19->Text);
	NewModel->Ks = StrToFloat(Edit20->Text);
	NewModel->p = 100;
	TRGBColor *C = new TRGBColor;
	C->r = StrToInt(Edit16->Text);
	C->g = StrToInt(Edit17->Text);
	C->b = StrToInt(Edit18->Text);
	NewModel->Color = C;

	Scene->AddModel(NewModel);
	t1 = clock();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
	InitListBox1();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::BitBtn10Click(TObject *Sender)
{
	CHyper* NewModel = new CHyper;
	NewModel->type = 'h';
	NewModel->Xc = StrToFloat(Edit22->Text);
	NewModel->Yc = StrToFloat(Edit23->Text);
	NewModel->Zc = StrToFloat(Edit24->Text);
	NewModel->Ap = StrToFloat(Edit25->Text);
	NewModel->Bp = StrToFloat(Edit26->Text);
	NewModel->Cp = StrToFloat(Edit27->Text);

	NewModel->Kd = StrToFloat(Edit31->Text);
	NewModel->Ks = StrToFloat(Edit32->Text);
	NewModel->p = 100;
	NewModel->H = StrToFloat(Edit33->Text);
	TRGBColor *C = new TRGBColor;
	C->r = StrToInt(Edit28->Text);
	C->g = StrToInt(Edit29->Text);
	C->b = StrToInt(Edit30->Text);
	NewModel->Color = C;
	switch (ComboBox1->ItemIndex)
	{
		case 0: NewModel->Ax = 'x'; break;
		case 1: NewModel->Ax = 'y'; break;
		case 2: NewModel->Ax = 'z'; break;
	}

	Scene->AddModel(NewModel);
	t1 = clock();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
	InitListBox1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn11Click(TObject *Sender)
{
	int I = ListBox1->ItemIndex;

	if (I == -1)
	{
		ShowMessage("Модель не выбрана!");
		return;
	}


	if (Scene->GetModel(I)->type != 'h')
	{
		ShowMessage("Модель не соотвтествует типу!");
		return;
	}

	CHyper *Hyper = (CHyper *)Scene->GetModel(I);
	Hyper->Xc = StrToFloat(Edit22->Text);
	Hyper->Yc = StrToFloat(Edit23->Text);
	Hyper->Zc = StrToFloat(Edit24->Text);
	Hyper->Ap = StrToFloat(Edit25->Text);
	Hyper->Bp = StrToFloat(Edit26->Text);
	Hyper->Cp = StrToFloat(Edit27->Text);

	Hyper->Kd = StrToFloat(Edit31->Text);
	Hyper->Ks = StrToFloat(Edit32->Text);
	Hyper->p = 100;
	Hyper->H = StrToFloat(Edit33->Text);
	Hyper->Color->r = StrToInt(Edit28->Text);
	Hyper->Color->g = StrToInt(Edit29->Text);
	Hyper->Color->b = StrToInt(Edit30->Text);
	switch (ComboBox1->ItemIndex)
	{
		case 0: Hyper->Ax = 'x'; break;
		case 1: Hyper->Ax = 'y'; break;
		case 2: Hyper->Ax = 'z'; break;
	}
	t1 = clock();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
	InitListBox1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn12Click(TObject *Sender)
{
	int I = ListBox1->ItemIndex;

	if (I == -1)
	{
		ShowMessage("Модель не выбрана!");
		return;
	}


	if (Scene->GetModel(I)->type != 'e')
	{
		ShowMessage("Модель не соотвтествует типу!");
		return;
	}

	CEllipse *Ellipse = (CEllipse *)Scene->GetModel(I);

	Ellipse->Xc = StrToFloat(Edit10->Text);
	Ellipse->Yc = StrToFloat(Edit11->Text);
	Ellipse->Zc = StrToFloat(Edit12->Text);
	Ellipse->Ap = StrToFloat(Edit13->Text);
	Ellipse->Bp = StrToFloat(Edit14->Text);
	Ellipse->Cp = StrToFloat(Edit15->Text);

	Ellipse->Kd = StrToFloat(Edit19->Text);
	Ellipse->Ks = StrToFloat(Edit20->Text);
	Ellipse->p = 100;
	Ellipse->Color->r = StrToInt(Edit16->Text);
	Ellipse->Color->g = StrToInt(Edit17->Text);
	Ellipse->Color->b = StrToInt(Edit18->Text);
	t1 = clock();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения:"+ FloatToStr(t2-t1) + " мс";
	InitListBox1();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn13Click(TObject *Sender)
{
	int I = ListBox1->ItemIndex;

	if (I == -1)
	{
		ShowMessage("Модель не выбрана!");
		return;
	}


	if (Scene->GetModel(I)->type != 's')
	{
		ShowMessage("Модель не соотвтествует типу!");
		return;
	}

	CSphere *Sphere = (CSphere *)Scene->GetModel(I);
	Sphere->Xc = StrToFloat(Edit1->Text);
	Sphere->Yc = StrToFloat(Edit2->Text);
	Sphere->Zc = StrToFloat(Edit3->Text);
	Sphere->R = StrToFloat(Edit4->Text);
	Sphere->Kd = StrToFloat(Edit8->Text);
	Sphere->Ks = StrToFloat(Edit9->Text);
	Sphere->p = 100;
	Sphere->Color->r = StrToInt(Edit5->Text);
	Sphere->Color->g = StrToInt(Edit6->Text);
	Sphere->Color->b = StrToInt(Edit7->Text);
	t1 = clock();
	Label1->Caption = "Идёт построение изображения";
	Form1->Refresh();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
	InitListBox1();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn14Click(TObject *Sender)
{
	Cam->Xc = StrToFloat(Edit34->Text);
	Cam->Yc = StrToFloat(Edit35->Text);
	Cam->Zc = StrToFloat(Edit36->Text);
	Cam->tet = StrToFloat(Edit37->Text)*M_PI/180;
	Cam->alf = StrToFloat(Edit38->Text)*M_PI/180;
	Scene->Ka = StrToFloat(Edit39->Text);
	Scene->MaxRek = StrToInt(Edit46->Text);
	t1 = clock();
	Label1->Caption = "Идёт построение изображения";
	Form1->Refresh();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";

}
//---------------------------------------------------------------------------



void __fastcall TForm1::BitBtn16Click(TObject *Sender)
{
	TLamp* NewLamp = new TLamp;
	NewLamp->Xc = StrToFloat(Edit40->Text);
	NewLamp->Yc = StrToFloat(Edit41->Text);
	NewLamp->Zc = StrToFloat(Edit42->Text);
	NewLamp->Ir = StrToFloat(Edit43->Text);
	NewLamp->Ig = StrToFloat(Edit44->Text);
	NewLamp->Ib = StrToFloat(Edit45->Text);
	Scene->AddLamp(NewLamp);
	t1 = clock();
	Label1->Caption = "Идёт построение изображения";
	Form1->Refresh();
	Scene->RenderImage();
	t2 = clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
	InitListBox2();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn15Click(TObject *Sender)
{
	int I = ListBox2->ItemIndex;
	if (I == -1)
		return;

	Scene->DeleteLamp(I);
	t1 = clock();
	Label1->Caption = "Идёт построение изображения";
	Form1->Refresh();
	Scene->RenderImage();
	t2= clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
	InitListBox2();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn17Click(TObject *Sender)
{
	int I = ListBox2->ItemIndex;
	if (I == -1)
		return;
	Scene->GetLamp(I)->Xc = StrToFloat(Edit40->Text);
	Scene->GetLamp(I)->Yc = StrToFloat(Edit41->Text);
	Scene->GetLamp(I)->Zc = StrToFloat(Edit42->Text);
	Scene->GetLamp(I)->Ir = StrToFloat(Edit43->Text);
	Scene->GetLamp(I)->Ig = StrToFloat(Edit44->Text);
	Scene->GetLamp(I)->Ib = StrToFloat(Edit45->Text);
	t1 = clock();
	Label1->Caption = "Идёт построение изображения";
	Form1->Refresh();
	Scene->RenderImage();
	t2= clock();
	Label1->Caption = "Время построения: " + FloatToStr(t2-t1) + " мс";
	InitListBox2();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::KeyPress(TObject *Sender, wchar_t &Key)
{
   /*	if ((Key<'0')||(Key>'9'))
	{
		if (Key!=',')
		{
			Key = '/n';
		}
	}  */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::KeyPress2(TObject *Sender, wchar_t &Key)
{
   /*	if ((Key<'0')||(Key>'9'))
	{
		Key = '/n';
    }   */
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
	int i = ListBox1->ItemIndex;
	if (i == -1)
		return;

	CModel *Model = Scene->GetModel(i);
	if (Model->type == 's')
	{
		CSphere *Sphere = (CSphere *)Model;
		PageControl1->ActivePageIndex = 0;
		Edit1->Text = FloatToStr(Sphere->Xc);
		Edit2->Text = FloatToStr(Sphere->Yc);
		Edit3->Text = FloatToStr(Sphere->Zc);

		Edit4->Text = FloatToStr(Sphere->R);
		Edit8->Text = FloatToStr(Sphere->Kd);
		Edit9->Text = FloatToStr(Sphere->Ks);

		Edit5->Text = IntToStr(Sphere->Color->r);
		Edit6->Text = IntToStr(Sphere->Color->g);
		Edit7->Text = IntToStr(Sphere->Color->b);

	} else if (Model->type == 'e')
	{

		CEllipse *Ellipse = (CEllipse *)Model;
		PageControl1->ActivePageIndex = 1;

		Edit10->Text = FloatToStr(Ellipse->Xc);
		Edit11->Text = FloatToStr(Ellipse->Yc);
		Edit12->Text = FloatToStr(Ellipse->Zc);

		Edit13->Text = FloatToStr(Ellipse->Ap);
		Edit14->Text = FloatToStr(Ellipse->Bp);
		Edit15->Text = FloatToStr(Ellipse->Cp);

		Edit19->Text = FloatToStr(Ellipse->Kd);
		Edit20->Text = FloatToStr(Ellipse->Ks);

		Edit16->Text = IntToStr(Ellipse->Color->r);
		Edit17->Text = IntToStr(Ellipse->Color->g);
		Edit18->Text = IntToStr(Ellipse->Color->b);

	} else if (Model->type == 'h')
	{

		CHyper *Hyper = (CHyper *)Model;
		PageControl1->ActivePageIndex = 2;


		Edit22->Text = FloatToStr(Hyper->Xc);
		Edit23->Text = FloatToStr(Hyper->Yc);
		Edit24->Text = FloatToStr(Hyper->Zc);

		Edit25->Text = FloatToStr(Hyper->Ap);
		Edit26->Text = FloatToStr(Hyper->Bp);
		Edit27->Text = FloatToStr(Hyper->Cp);


		Edit31->Text = FloatToStr(Hyper->Kd);
		Edit32->Text = FloatToStr(Hyper->Ks);

		Edit33->Text = FloatToStr(Hyper->H);

		Edit28->Text = IntToStr(Hyper->Color->r);
		Edit29->Text = IntToStr(Hyper->Color->g);
		Edit30->Text = IntToStr(Hyper->Color->b);


		switch (Hyper->Ax)
		{
			case 'x': ComboBox1->ItemIndex = 0; break;
			case 'y': ComboBox1->ItemIndex = 1; break;
			case 'z': ComboBox1->ItemIndex = 2; break;
		}


	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListBox2Click(TObject *Sender)
{
	int I = ListBox2->ItemIndex;
	if (I == -1)
		return;

	Edit40->Text = FloatToStr(Scene->GetLamp(I)->Xc);
	Edit41->Text = FloatToStr(Scene->GetLamp(I)->Yc);
	Edit42->Text = FloatToStr(Scene->GetLamp(I)->Zc);
	Edit43->Text = FloatToStr(Scene->GetLamp(I)->Ir);
	Edit44->Text = FloatToStr(Scene->GetLamp(I)->Ig);
	Edit45->Text = FloatToStr(Scene->GetLamp(I)->Ib);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (SaveDialog1->Execute())
	{
		UnicodeString s = SaveDialog1->FileName;
		char *filename = s.t_str();
		Scene->SaveToFile(filename);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (OpenDialog1->Execute())
	{
		UnicodeString s = OpenDialog1->FileName;
		char *filename = s.t_str();
		Scene->LoadFromFile(filename);
		InitListBox1();
		InitListBox2();
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int start, end;
	int step;
	int old = Scene->MaxRek;
	int summ;
	start = StrToInt(Edit47->Text);
	end = StrToInt(Edit48->Text);
	step = StrToInt(Edit49->Text);
	while (start <= end)
	{
		Scene->MaxRek = start;
		summ = 0;
		for (int i = 0; i < 4; i++)
		{
			t1 = clock();
			Scene->RenderImage();
			t2 = clock();
			summ += t2 - t1;
		}
		summ /= 4;

	  //	Form2->Chart1->ClearChart();
		Form2->Series1->Add(summ, IntToStr(start), clRed);
		start += step;
	}
	Scene->MaxRek = old;
	Form2->ShowModal();
}
//---------------------------------------------------------------------------

