#include "lista.h"

Lista* inicializa (void)
	{
		return NULL;
	}
	
/* inser��o no in�cio: retorna a lista atualizada */
Lista* insere (Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

/* fun��o imprime: imprime valores dos elementos */
void imprime (Lista* l){
	Lista* p; /* vari�vel auxiliar para percorrer a lista */
	for (p = l; p != NULL; p = p->prox)
	printf("info = %d\n", p->info);
}

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
bool vazia (Lista* l){
	return (l == NULL);
}

/* fun��o busca: busca um elemento na lista */
Lista* busca (Lista* l, int v){
	Lista* p;
	for (p=l; p!=NULL; p=p->prox){
		if (p->info == v) cout << endl << "Info: " << p->info << endl << "Prox: " << p->prox << endl;
	}
	cout << endl << "> Valor n�o encontrado !" << endl;
 	return NULL;
 	
}

/* fun��o retira: retira elemento da lista */
Lista* retira (Lista* l, int v) {
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l; /* ponteiro para percorrer a lista*/
	
	/* procura elemento na lista, guardando anterior */
	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}
	
	/* verifica se achou elemento */	
	if (p == NULL){
		cout << endl << "> Valor n�o encontrado !" << endl;
		return l; /* n�o achou: retorna lista original */
	} 
	
	/* retira elemento */
	if (ant == NULL) {
		/* retira elemento do inicio */
		l = p->prox;
	}
	else {
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	}
	
	cout << endl << "> Valor removido !" << endl;
	free(p);
	return l;
}

// retorna o n�-dado no in�cio da lista para exibi��o, sem retir�-lo;
Lista* mostraInicio (Lista* l){
	if(!vazia(l)){
		return l;
	}
}

// retornar o n�-dado no fim da lista para exibi��o, sem retir�-lo;
Lista* mostraFim (Lista* l){
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
		if (p->prox == NULL) return p;
 	
	free(p);
	 return NULL;
}

// retorna um valor inteiro representando a quantidade de dados contidos na lista, para que seja informado ao usu�rio;
int tamanho (Lista* l){
	Lista* p;
	int i(0);
	for (p = l; p != NULL; p = p->prox)
		i++;
	
	free(p);
	return i;
}

// retorna o n�mero de ocorr�ncias de um dado valor inteiro informado pelo usu�rio na lista (lembrando que a lista poder� conter dados repetidos);
int ocorrencias (Lista* l, int v){
	Lista* p;
	int i(0);
	for (p = l; p != NULL; p = p->prox)
		if(p -> info == v) i++;
	
	return i;
}

// dever� inserir um novo n�-dado no fim da lista;
Lista* insereFim (Lista* l, int i){

	Lista* ant = NULL;
	Lista* p;
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	novo -> info = i;
	novo -> prox = NULL;
	
	if(l == NULL){
		return novo;
	}else{
		p = l;
		while(p->prox != NULL){	
			p = p->prox;	
		}		
		p -> prox = novo;
	}
	
	return l;
}

// remove n�-dado no in�cio da Lista
Lista* removeInicio (Lista* l){
	return l->prox;
}

//- removeFim() - remove n�-dado no fim da Lista.*/
Lista* removeFim (Lista* l){
	Lista* ant = NULL;
	Lista* p;
	
	if(l == NULL){
		return l;
	}else{
		p = l;
		while(p->prox != NULL){
			ant = p;
			p = p->prox;
		}
		ant->prox = p->prox;
	}
	return l;
}



