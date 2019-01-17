//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//---------------------------------------------------------------------------

pile_entier::pile_entier(int t)
{
	pile_entier *pile2;
	pile=new int(t);
	t=100;
	taille=t; // taille max
	hauteur=0; // taille réel
}
pile_entier::~pile_entier()
{
	pile_entier *pile;
	delete pile;
}
void pile_entier::empile(int val)
{
  pile_entier *pile2;


  int j=0;
  for(int i=0;i<taille;i++)
  {
	if(pile[i])
	{
		j++;
	}

  }
  pile[j]=val;
  hauteur++;

}
int pile_entier::depile()
{
  pile_entier *pile;
  int j=0;
  pile->hauteur--;
  int valeur=0;
  for(int i=0;i<pile->taille;i++)
  {

	if(pile->pile[i])
	{
		j++;
	}

  }
  valeur=j;
  pile->pile[j]=0;
  return valeur;
}
int pile_entier::pleine()
{
  pile_entier *pile;
  int retourner=0;
  int j=0;
  for(int i=0;i<pile->taille;i++)
  {

	if(pile->pile[i])
	{
		j++;
	}

  }
  if(j!=0)
  {
	retourner=1;
  }
  else
  {
	  retourner=0;
  }

  return retourner;

}
int pile_entier::vide()
{
   pile_entier *pile;
  int retourner=0;
  int j=0;
  for(int i=0;i<pile->taille;i++)
  {

	if(pile->pile[i])
	{
		j++;
	}

  }
  if(j==0)
  {
	retourner=0;
  }
  else
  {
	  retourner=0;
  }

  return retourner;
}
int *pile_entier::getpile()
{
 pile_entier *pile;
 return pile->pile;

}
int pile_entier::gethauteur()
{
   pile_entier *pile;
   return pile->hauteur;
}
int pile_entier::gettaille()
{
   pile_entier *pile;
   return pile->taille;
}



#pragma package(smart_init)
