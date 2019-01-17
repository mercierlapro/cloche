//---------------------------------------------------------------------------

#pragma hdrstop

#include "PortSerie.h"
#include <vcl.h>

#include <windows.h>
bool PortSerie::ouverture(wchar_t* port)
{
	bool rep;
	hcomm=CreateFile(port,GENERIC_WRITE|GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_FLAG_NO_BUFFERING,NULL);
	if (hcomm==INVALID_HANDLE_VALUE)
	{
		rep =false;
	}
	else
	{
		GetCommState(hcomm,&serie);
		serie.BaudRate = 9600;
		serie.ByteSize =8;
		serie.Parity = NOPARITY;
		serie.StopBits = ONESTOPBIT;
		SetCommState(hcomm,&serie);
		rep=true;
	}


	return rep;

}
void PortSerie::fermeture()
{
  CloseHandle(hcomm);
}

char * PortSerie::ecriture(wchar_t *chaine)
{
  unsigned long pt=0;
	char chaine2[50];
	wcstombs(chaine2,chaine,sizeof(chaine2));
	WriteFile(hcomm,&chaine2, strlen(chaine2),&pt, NULL);
	PurgeComm(hcomm,PURGE_TXCLEAR);
	return chaine2;

}
char* PortSerie::lecture(int taille)
{
  taille=15;
  char  *chaine2;
  chaine2=new char[taille+1];

	unsigned long pt;
	pt=0;
	chaine2[0]='\0';

	ReadFile(hcomm,chaine2, taille,&pt, &over);
	PurgeComm(hcomm,PURGE_RXCLEAR);
	return chaine2;

}
//---------------------------------------------------------------------------
#pragma package(smart_init)
