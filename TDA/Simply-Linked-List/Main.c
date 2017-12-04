#include <stdio.h>
#include "Lista.h"
#define N 4

int main()
{
	Lista l;
	char elementos[N]="abcd";
	int pos, i;

	inicList(&l);
	esVacia(l);
	for(i = 0; i < N; i++)
	{
		insHead(&l, elementos[i]);
	}
	printf("Tamaño de la Lista = %d\n",sizeList(l));
	invertir(&l);
	printList(l);
	while(scanf("%d", &pos) == 1)
	{
		if(elemk(&l, pos) != '%')
			printf("Numero %d | Elemento %c\n", pos, elemk(&l, pos));
		else
			printf("###Error###\n");
	}
	
	delList(&l);
	return 0;
}