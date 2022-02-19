#include "lista.h"

Lista* criaFila(void);
void enqueue(Lista* &l, int i);
Lista* dequeue(Lista* &l);
int size(Lista* l);
bool isEmpty(Lista* l);
int front(Lista* l);
void mostrar(Lista* l);
