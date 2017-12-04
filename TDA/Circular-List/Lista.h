#ifndef LISTA_H
#define LISTA_H

typedef int Item; /* elemento generico del programa */

/* Nodo de enlace simple de la lista ( elemento y apuntador ) */
typedef struct _NODO
{
	int data;
	struct _NODO *next;
}Nodo;

typedef struct 
{
	Nodo *head;
	int size;
} Lista;

Lista *inicList(); /* inicializa la lista */
int esVacia(Lista *l); /* indica si esta vacia la lista */
void insert(Lista *l, Item e); /* inserta nuevos elementos por la cola de la lista */
Item delHead(Lista *l); /* elimina por la cabeza de la lista */
Item eliminar(Lista *l, Item pos); /* elimina en una posicion k de la lista */
Item survivor(Lista *l, Item dead);
Item sizeList(Lista *l); /* de vuelve el tamanho total de la lista */
void printList(Lista *l); /* muestra el contenido de la lista */
void delList(Lista *l); /* elimina por completo la lista */
void invertir(Lista *l); /* invierte la lista */
Item elemk(Lista *l, Item pos);

#endif