#include "fila.h"

Lista* criaFila(void){
	inicializa();
}

void enqueue(Lista* &l, int i){
	l = insereFim(l, i);
}

Lista* dequeue(Lista* &l){
	Lista *aux = mostraInicio(l);
	l = removeInicio(l);
	return aux;
}

int size(Lista* l){
	return tamanho(l);
}

bool isEmpty(Lista* l){
	return vazia(l);
}

int front(Lista* l){
	Lista *aux = mostraInicio(l);
	return isEmpty(aux) ? 0 : aux->info;
}

void mostrar(Lista* l){
	imprime(l);
}
