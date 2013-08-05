//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>

#include "Scene.h"
#include "Model.h"
#include "Hyper.h"
#include "Unit2.h"
#include "Ellipse.h"
#include "Polygon.h"
#include "Sphere.h"
#include <math.h>
#include <Tabs.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <cstdlib>
#include "time.h"


//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *BitBtn2;
	TImage *Image1;
	TGroupBox *GroupBox1;
	TListBox *ListBox1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TBitBtn *BitBtn8;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TBitBtn *BitBtn13;
	TTabSheet *TabSheet2;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TBitBtn *BitBtn9;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TEdit *Edit14;
	TEdit *Edit15;
	TEdit *Edit16;
	TEdit *Edit17;
	TEdit *Edit18;
	TEdit *Edit19;
	TEdit *Edit20;
	TBitBtn *BitBtn12;
	TTabSheet *TabSheet3;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label30;
	TBitBtn *BitBtn10;
	TBitBtn *BitBtn11;
	TEdit *Edit22;
	TEdit *Edit23;
	TEdit *Edit24;
	TEdit *Edit25;
	TEdit *Edit26;
	TEdit *Edit27;
	TEdit *Edit28;
	TEdit *Edit29;
	TEdit *Edit30;
	TEdit *Edit31;
	TEdit *Edit32;
	TComboBox *ComboBox1;
	TEdit *Edit33;
	TLabel *Label28;
	TLabel *Label29;
	TBitBtn *BitBtn15;
	TEdit *Edit40;
	TEdit *Edit41;
	TEdit *Edit42;
	TEdit *Edit43;
	TEdit *Edit44;
	TEdit *Edit45;
	TBitBtn *BitBtn16;
	TBitBtn *BitBtn17;
	TListBox *ListBox2;
	TLabel *Label2;
	TBitBtn *BitBtn7;
	TBitBtn *BitBtn18;
	TBitBtn *BitBtn19;
	TLabel *Label3;
	TLabel *Label27;
	TEdit *Edit39;
	TButton *Button1;
	TButton *Button2;
	TGroupBox *GroupBox2;
	TLabel *Label1;
	TLabel *Label16;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label31;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	TBitBtn *BitBtn6;
	TEdit *Edit21;
	TEdit *Edit34;
	TEdit *Edit35;
	TEdit *Edit36;
	TEdit *Edit37;
	TEdit *Edit38;
	TBitBtn *BitBtn14;
	TEdit *Edit46;
	TSaveDialog *SaveDialog1;
	TOpenDialog *OpenDialog1;
	TEdit *Edit47;
	TEdit *Edit48;
	TButton *Button3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit49;
	TLabel *Label32;
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall BitBtn5Click(TObject *Sender);
	void __fastcall BitBtn6Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall BitBtn7Click(TObject *Sender);
	void __fastcall BitBtn8Click(TObject *Sender);
	void __fastcall BitBtn9Click(TObject *Sender);
	void __fastcall BitBtn10Click(TObject *Sender);
	void __fastcall BitBtn11Click(TObject *Sender);
	void __fastcall BitBtn12Click(TObject *Sender);
	void __fastcall BitBtn13Click(TObject *Sender);
	void __fastcall BitBtn14Click(TObject *Sender);
	void __fastcall BitBtn16Click(TObject *Sender);
	void __fastcall BitBtn15Click(TObject *Sender);
	void __fastcall BitBtn17Click(TObject *Sender);
	void __fastcall KeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall KeyPress2(TObject *Sender, wchar_t &Key);
	void __fastcall InitListBox1();
	void __fastcall InitListBox2();
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall ListBox2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
