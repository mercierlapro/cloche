#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void initialisation(int tab[10]);
int recherche(int tab[10],int valeur);
void affichage(int tab[10],int valeur,int rep);
int _tmain(int argc, _TCHAR* argv[]) 
{
	int tab[10],valeur,rep;
	affichage(tab,valeur,rep);
	getch();
	return 0;
}

void initialisation(int tab [10])
{
	int i=0;
	int a,b,stock;
	for(i=0;i<10;i++)
	{
		printf("entrez un nombre :) \n");
		scanf("%d",&tab[i]);
	}

	for(i=0;i<10;i++)
	{
	   a=0,b=0;
	   a=tab[i];
	   b=tab[i+1];
	   stock=0;

	   if(a>b)
	   {
		 stock=a;
		 a=b;
		 tab[i]=a;
		 b=stock;
		 tab[i+1]=b;
		 i=0;

	   }

	}
}

int recherche(int tab[10],int valeur)
{
   int i=0;
   int position;
   printf("entrez une valeur à rechercher :p \n");
   scanf("%d",&valeur);

   return valeur;

}

void affichage(int tab[10],int valeur,int rep)
{   int i=0;
	initialisation(tab);
	printf("Le tableau : \n");
	for (i=0 ;i< 10;i++)
	{
		printf("%d \n",tab[i]);
	}
	valeur=recherche(tab,valeur);

	printf(" votre valeur : %d \n",valeur);

	for(i=0;i<10;i++)
	{
			if(valeur==tab[i])
		{
			printf("votre valeur est présente \n position : %d \n",i);
			rep=1;


		}
			else
		{
			printf("votre valeur n'est pas présente \n position : %d \n",i);
			rep=0;
        }




	}








}
