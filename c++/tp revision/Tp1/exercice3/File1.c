#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

typedef struct eleve eleve;
void fwrite2(eleve*student[6]);
void fread2(eleve*student[6]);

struct eleve

{

	char nom[20];
	char prenom[20];
	char adresse[40];
	char classe[10];

};



   int main(int argc, char *argv[])
{
	eleve student[6];
	fwrite2(&student);
	fread2(&student);

	getch();
	return 0;
}

void fwrite2(eleve*student[6])
{

   int i=0;
   for(i=0;i<=6;i++)
   {
	 printf("Nom \n");
	 scanf("%s",student[i]->nom);
	  printf("Prenom\n");
	 scanf("%s",student[i]->prenom);
	 printf("adresse\n");
	 scanf("%s",student[i]->adresse);
	  printf("classe\n");
	 scanf("%s",student[i]->classe);

   }

}
void fread2(eleve*student[6])
{
	int i=0;
	for(i=0;i<=6;i++)
   {
	 printf("Voici tes infos : \n %s , %s , %s , %",student[i]->nom,student[i]->prenom,student[i]->adresse,student[i]->classe);

   }

}


