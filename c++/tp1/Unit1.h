//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
#include "Unit2.h"
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TMainMenu *MainMenu1;
	TMenuItem *fichier1;
	TMenuItem *nouveau1;
	TMenuItem *fermer1;
	TMenuItem *version1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TChart *Chart1;
	TButton *Button6;
	TEdit *Edit1;
	TEdit *FrequenceAcquisition;
	TButton *Button7;
	TLineSeries *Series2;
	TTimer *Timer1;
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall fermer1Click(TObject *Sender);
	void __fastcall nouveau1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:  int x,y,freq,t;int *pile2;int val;	// Déclarations utilisateur
public:		// Déclarations utilisateur
		pile_entier *pile;


	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
