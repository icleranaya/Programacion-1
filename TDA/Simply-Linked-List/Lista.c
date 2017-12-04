#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void inicList(Lista *l)
{
	l->head = NULL;
	l->size = 0;
}

int esVacia(Lista l)
{
	return l.head == NULL;
}

void insHead(Lista *l, char e)
{
	Nodo *nuevo;

	nuevo = (Nodo *)malloc(sizeof(Nodo));
	nuevo->data = e;
	nuevo->next = l->head;
	l->head = nuevo;
	l->size++;
}

void delHead(Lista *l)
{
	Nodo *act;
	act = l->head;
	l->head = act->next;
	free(act);
	l->size--;
}

int sizeList(Lista l)
{
	return l.size;
}

void printList(Lista l)
{
	Nodo* act;
	act = l.head;
	while(act != NULL)
	{
		printf("%c", act->data);
		act = act->next;
		if(act != NULL) printf("->");
	}
	printf("\n");
}

void delList(Lista *l)
{
	Nodo *act;
	act = l->head;
	while(act != NULL)
	{
		l->head = l->head->next;
		free(act);
		act = l->head;
	}
	l->size = 0;
}

void invertir(Lista *l)
{
	Nodo *ant, *act, *sig;
	ant = NULL;
	act = l->head;
	while(act != NULL)
	{
		sig = act->next;
		act->next = ant;
		ant = act;
		act = sig;
	}
	l->head = ant;
}

char elemk(Lista *l, int pos)
{
	Nodo *act;
	int aux, i;

	act = l->head;
	if(pos == l->size)
		return  act->data;
	if(pos > 0 && pos <= l->size)
	{
		aux = l->size - pos;
		for(i = 1; i <= aux; i++)
			act = act->next;
		return act->data;
	}
	return '%';
}