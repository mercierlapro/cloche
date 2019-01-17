#pragma hdrstop
#pragma argsused

#include <stdio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void echange(int *v1,int *v2);

int _tmain(int argc, _TCHAR* argv[])
{

	int *variable1=5;
	int *variable2=10;
	printf("%d \n %d \n",variable1,variable2);
	echange(&variable1,&variable2);
	printf("%d \n %d \n",variable1,variable2);

	getch();
	return 0;
}
void echange(int *v1,int *v2)
{
	int stock=0;
	stock=*v1;
	*v1=*v2;
	*v2=stock;


}
