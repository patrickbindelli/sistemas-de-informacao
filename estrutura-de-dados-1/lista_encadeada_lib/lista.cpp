#include "lista.h"

Lista* inicializa (void)
	{
		return NULL;
	}
	
/* inserção no início: retorna a lista atualizada */
Lista* insere (Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

/* função imprime: imprime valores dos elementos */
void imprime (Lista* l){
	Lista* p; /* variável auxiliar para percorrer a lista */
	for (p = l; p != NULL; p = p->prox)
	printf("info = %d\n", p->info);
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
bool vazia (Lista* l){
	return (l == NULL);
}

/* função busca: busca um elemento na lista */
Lista* busca (Lista* l, int v){
	Lista* p;
	for (p=l; p!=NULL; p=p->prox){
		if (p->info == v) cout << endl << "Info: " << p->info << endl << "Prox: " << p->prox << endl;
	}
	cout << endl << "> Valor não encontrado !" << endl;
 	return NULL;
 	
}

/* função retira: retira elemento da lista */
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
		cout << endl << "> Valor não encontrado !" << endl;
		return l; /* não achou: retorna lista original */
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

// retorna o nó-dado no início da lista para exibição, sem retirá-lo;
Lista* mostraInicio (Lista* l){
	if(!vazia(l)){
		return l;
	}
}

// retornar o nó-dado no fim da lista para exibição, sem retirá-lo;
Lista* mostraFim (Lista* l){
	Lista* p;
	for (p = l; p != NULL; p = p->prox)
		if (p->prox == NULL) return p;
 	
	free(p);
	 return NULL;
}

// retorna um valor inteiro representando a quantidade de dados contidos na lista, para que seja informado ao usuário;
int tamanho (Lista* l){
	Lista* p;
	int i(0);
	for (p = l; p != NULL; p = p->prox)
		i++;
	
	free(p);
	return i;
}

// retorna o número de ocorrências de um dado valor inteiro informado pelo usuário na lista (lembrando que a lista poderá conter dados repetidos);
int ocorrencias (Lista* l, int v){
	Lista* p;
	int i(0);
	for (p = l; p != NULL; p = p->prox)
		if(p -> info == v) i++;
	
	return i;
}

// deverá inserir um novo nó-dado no fim da lista;
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

// remove nó-dado no início da Lista
Lista* removeInicio (Lista* l){
	return l->prox;
}

//- removeFim() - remove nó-dado no fim da Lista.*/
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



