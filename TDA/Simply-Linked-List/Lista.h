#ifndef LISTA_H
#define LISTA_H

typedef struct _NODO
{
	char data;
	struct _NODO *next;
}Nodo;

typedef struct 
{
	Nodo *head;
	int size;
} Lista;

void inicList(Lista *l);
int esVacia(Lista l);
void insHead(Lista *l, char e);
void delHead(Lista *l);
int sizeList(Lista l);
void printList(Lista l);
void delList(Lista *l);
void invertir(Lista *l);
char elemk(Lista *l, int pos);

#endif