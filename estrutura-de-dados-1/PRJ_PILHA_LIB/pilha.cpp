#include "pilha.h"

Lista* criaPilha (void){
	inicializa();
}

Lista* push (Lista* l , int v){
	insere(l, v);
}

Lista* pop (Lista* l){
	removeInicio(l);
}
	
bool isEmpty (Lista* l){
	vazia(l);
}

int size(Lista* l){
	tamanho(l);
}

int top(Lista* l){
	mostraInicio(l);
}

void mostrar(Lista *l){
	imprime(l);
}





