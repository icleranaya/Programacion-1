#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Lista.h"

Lista *inicList()
{	
	Lista *list = (Lista *) malloc(sizeof(Lista));
	list->head = NULL;
	list->size = 0;
	return list;
}

int esVacia(Lista *l)
{
	return l->head == NULL;
}

void insert(Lista *l, Item e)
{
	/* Declaracion de los Nodos de forma dinamica */
	Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
	
	/* Asignacion del elemento al nuevo Nodo por la cola */
	nuevo->data = e;
	nuevo->next = l->head;
	if(esVacia(l))
	{
		l->head = nuevo;
	}
	else
	{
		/* se insertan los elementos por la cabeza de la lista */
		nuevo->next = l->head;
		l->head = nuevo;
	}
	l->size++;
}

Item delHead(Lista *l)
{
	Nodo *aux = l->head;
	int elem = aux->data;
	l->head = aux->next;
	free(aux);
	l->size--;
	return elem;
}

Item eliminar(Lista *l, Item pos)
{
	Nodo *aux, *ant;
	int elem, i = 1;

	aux = l->head;

	/* eliminacion del primer elemento de la lista */
	if(pos == 1)
		elem = delHead(l);
	else
	{	
		/* eliminacion del ultimo elemento de la lista*/
		if(pos == sizeList(l))
		{
			while(i < pos)
			{
				ant = aux;
				aux = aux->next;
				i++;
			}
			ant->next = l->head;
			elem = aux->data;
			free(aux);
			l->size--;
		}
		else
		{
			aux = l->head;
			/* eleminacion de elementos en medio de la lista */
			while(i < pos)
			{
				ant = aux;
				aux = aux->next;
				elem = aux->data;
                i++;
			}
			ant->next = aux->next;
			free(aux);
			l->size--;
		}
	}
	
	/* retorna el elemento eliminado */
	return elem;
}

Item survivor(Lista *l, Item dead)
{
	int i = 1, act = 1;

	while(l->size > 1)
	{
		if(i < dead)
		{
			i++;
			act++;
		}
		else
		{
			eliminar(l, act);
			i = 1;
		}
		if(act > l->size)
			act = 1;
	}
	return l->head->data;
}

Item sizeList(Lista *l)
{
	return l->size;
}

void printList(Lista *l)
{
	Nodo* act = l->head;
	int i = 0;
	while(i < sizeList(l))
	{
		printf("%d", act->data);
		act = act->next;
		if(i != sizeList(l) - 1) printf("->");
		i++;
	}
	printf("\n");
}

void delList(Lista *l)
{
	Nodo *act = l->head;
	int i = 0;
	while(i < sizeList(l))
	{
		l->head = l->head->next;
		free(act);
		act = l->head;
		i++;
	}
	l->head = NULL;
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

Item elemk(Lista *l, Item pos)
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
	return 0;
}