//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{  //parametrage du client
    client = new TIdTCPClient;
	 Trame->Clear();
        i=0;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnPetiteClick(TObject *Sender)
{
	//trame pour le petit marteau
	unsigned char msg= 0x08;
	trame->activation(msg,client);
	trame->retourMarteau(client);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnInterClick(TObject *Sender)
{
	//trame pour le marteau interm�diaire
	unsigned char msg= 0x04;
	trame->activation(msg,client);
	trame->retourMarteau(client);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnMoyClick(TObject *Sender)
{
	//trame pour le marteau moyen
	unsigned char msg= 0x02;
	trame->activation(msg,client);
	trame->retourMarteau(client);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnGrandeClick(TObject *Sender)
{
	//trame pour le grand marteau
	unsigned char msg= 0x01;
	trame->activation(msg,client);
	trame->retourMarteau(client);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Server1Execute(TIdContext *AContext)
{

Trame->Lines->Add("Le serveur a re�u");

}

//---------------------------------------------------------------------------

void __fastcall TForm1::Connect_BtClick(TObject *Sender)
{
Server1->Active=true;            //Configuration du serveur par le bouton connec
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Deconnect_BtClick(TObject *Sender)
{
Server1->Active=false;
Trame->Lines->Add("Le Serveur est �teint");
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button1Click(TObject *Sender)
{
	client->Host="192.168.64.124";
	client->Port=502;                       //Param�tres de connexion du clien
	client->Connect();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	if(client->Connected())
	{
	  Shape1->Brush->Color=clGreen;
	}
	else
	{
		Shape1->Brush->Color=clRed;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Server1Connect(TIdContext *AContext)
{
String requete;

Trame->Lines->Add("Serveur connect�!");
Trame->Lines->Add("L'addresse ip du client est :");
Trame->Lines->Add(AContext->Binding->PeerIP);
Trame->Lines->Add("L'addresse du port du client est :");
Trame->Lines->Add(AContext->Binding->PeerPort);
	if(i==0)
	{
	 client->Host="192.168.64.124";
			client->Port=502;
			client->Connect();
	}
while(AContext->Connection->Socket->Connected()==true)
{
requete=AContext->Connection->Socket->ReadLn();
Trame->Lines->Add(requete);


	if(requete=="Cloche1")                     //Si la requete envoy� est cloche1 on active la petite cloche
	{

		unsigned char msg= 0x08;
		trame->activation(msg,client);
		trame->retourMarteau(client);

	}
	if(requete=="Cloche2")
	{


		unsigned char msg=0x04;
		trame->activation(msg,client);
		trame->retourMarteau(client);

	}
	if(requete=="Cloche3")
	{


		//trame pour le marteau moyen
		unsigned char msg= 0x02;
		trame->activation(msg,client);
		trame->retourMarteau(client);

	}
	if(requete=="Cloche4")
	{
	

			//trame pour le grand marteau
		unsigned char msg= 0x01;
		trame->activation(msg,client);
		trame->retourMarteau(client);

	}
      i=1;
	  }


	AContext->Connection->IOHandler->WriteLn("Termin�");
	AContext->Connection->Disconnect();
    i=0;
}
//---------------------------------------------------------------------------

