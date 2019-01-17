//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{      t=0;
		freq=0;
		x=y=0;

	Form1->Edit1->Visible=false;
	Form1->Button6->Visible=false;
	Form1->Button5->Visible=false;
	Form1->Button4->Visible=false;
	Form1->Button3->Visible=false;
	Form1->Button2->Visible=false;
	Form1->Button1->Visible=false;
	Form1->Chart1->Visible=false;
	Timer1->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
   pile_entier *pile;
   t=Form1->Edit1->Text.ToInt();
   Form1->Button5->Visible=true;
   Form1->Button4->Visible=true;
   Form1->Button3->Visible=true;
   Form1->Button2->Visible=true;
   Form1->Button1->Visible=true;
   Form1->Edit1->Visible=false;
   Form1->Button6->Visible=false;
   Form1->Chart1->Visible=false;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Form1->Button5->Visible=true;
   Form1->Button4->Visible=true;
   Form1->Button3->Visible=true;
   Form1->Button2->Visible=true;
   Form1->Button1->Visible=true;
   Form1->Edit1->Visible=false;
   Form1->Button6->Visible=false;
   Form1->Chart1->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::fermer1Click(TObject *Sender)
{
  Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::nouveau1Click(TObject *Sender)
{
	Form1->Edit1->Visible=true;
	Form1->Button6->Visible=true;
	Form1->Button5->Visible=false;
	Form1->Button4->Visible=false;
	Form1->Button3->Visible=false;
	Form1->Button2->Visible=false;
	Form1->Button1->Visible=false;
	Form1->Chart1->Visible=false;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form1->FrequenceAcquisition->Visible=true;
	Form1->Button7->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Timer1->Enabled=false;
	freq=Form1->FrequenceAcquisition->Text.ToInt();
	Form1->Button7->Visible=false;
	Form1->FrequenceAcquisition->Visible=false;



}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{



	  Series2->AddXY(x,pile2[y],"valeur",clRed);
	  x++;
	  y++;





}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	val=0;
	val=rand();


	for(int i=0;i<t;i++)
	{
		pile2[i]=0;
	}

	Timer1->Interval=freq;
	Timer1->Enabled=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Timer1->Enabled=false;
}
//---------------------------------------------------------------------------
