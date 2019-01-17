#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	/*   exercice 1



	int *ptr;
	*ptr=5;

	printf("%d \n",ptr);   // cela affiche l'adresse du pointeur :)    */

	/*
	exercice 2
	float varfloat=1.5;
	float *advar=&varfloat;  //advar contient l'adresse de varfloat

	printf("%x \n",&varfloat);   //affiche l'adresse de varfloat
	printf("%x \n",advar);     //affiche ce que contient advar  */


	/*exercice 3

	int tabint[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};

	int *tabptr=tabint;
	int i;
	for(i=0;i<15;i+=2)
	{
		printf("%d \n",*(tabptr+i));
	}    */

	system("pause");
	return 0;
}
