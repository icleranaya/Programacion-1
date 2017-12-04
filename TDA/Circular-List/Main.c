#include <stdio.h>
#include "Lista.h"

int main()
{
	Lista *p;
	int sequence, kill, i = 1;


	p = inicList();

	while(scanf("%d %d", &sequence, &kill) == 2)
	{
		p = inicList();
		while(i <= sequence)
		{
			insert(p, i);
			i++;
		}
		i = 1;
		invertir(p);
		if(!esVacia(p))
			printList(p);
		printf("sobreviviente: %d\n", survivor(p, kill));
		delList(p);
	}
	delList(p);
	return 0;
}
