#include "lista.h"

// inicializa a lista
Lista* inicializa (void){ return NULL; }

// insere nó-dado no início da lista
Lista* insereInicio (Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	
	if(vazia(l)){
		novo->prox = novo;
		return novo;
	}
	
	novo -> prox = l->prox;
	l->prox = novo;
	cout << endl << "Valor adicionado!" << endl;
	return l;
}

// insere nó-dado ao fim da lista
Lista* insereFim (Lista* l, int i){

	// Verifica se a lista está vazia
	// Nesse caso só se pode inserir no início, então reutilizamos a função
	if(vazia(l)) return insereInicio(l, i);
	
	// Caso contrario, adiciona após o último elemento
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l->prox;
	l->prox = novo;
	cout << endl << "Valor adicionado!" << endl;
	return novo;
}

// imprime os valores de todo nó-dado da lista
void imprime (Lista* l){
	
	if(vazia(l)){
		cout << "Lista vazia!" << endl;
		return;
	}
	
	Lista* aux = l->prox; /* variável auxiliar para percorrer a lista */
	
	printf("info: ");
	do{
		printf("[%d] ", aux->info);
		aux = aux->prox;
	}while(aux != l->prox);
	cout << endl;
}

// retorna o nó-dado no início da lista para exibição, sem retirá-lo
Lista* mostraInicio (Lista* l){
	if(!vazia(l)){
		return l->prox;
	}
	
	return NULL;
}

// retornar o nó-dado no fim da lista para exibição, sem retirá-lo
Lista* mostraFim (Lista* l){
	if(!vazia(l)){
		return l;
	}
	
	return NULL;
}

// checa se a lista está vazia
bool vazia (Lista* l){
	return (l == NULL);
}

// retorna um valor inteiro representando a quantidade de dados contidos na lista, para que seja informado ao usuário
int tamanho (Lista* l){
	
	if(vazia(l)) return 0;
	
	Lista* aux = l->prox;
	int tamanho(0);
	
	do{
		tamanho++;
		aux = aux->prox;
	}while(aux != l->prox);
	
	return tamanho;
}

// retorna o número de ocorrências de um dado valor inteiro informado pelo usuário na lista (lembrando que a lista poderá conter dados repetidos)
int ocorrencias (Lista* l, int v){
	if(vazia(l)) return 0;
	
	Lista* aux = l->prox;
	int i(0);
	do{
		if(aux -> info == v) i++;
		aux = aux->prox;
	}while (aux != l->prox);
		
	return i;
}

// remove nó-dado no início da Lista
Lista* removeInicio (Lista* l){
	if(vazia(l)){
		cout << "Lista vazia!" << endl;
		return l;
	}
	
	if(tamanho(l) == 1) return NULL;
	
	Lista* aux = l;
	aux->prox = l->prox->prox;
	cout << "Início removido!" << endl;
	return aux;
}

// remove nó-dado no fim da Lista
Lista* removeFim (Lista* l){
	if(vazia(l)){
		cout << "Lista vazia!" << endl;
		return l;
	}
	
	if(tamanho(l) == 1) return NULL;
	
	Lista* aux = l;
	
	do{
		aux = aux->prox;
	}while(aux->prox != l);
	
	aux->prox = l->prox;
	return aux;
}

// retira elemento da lista
Lista* retira (Lista* l, int v) {
	if(vazia(l)){
		printf("Lista vazia!\n");
		return l;
	}
		
	Lista* ant = NULL; /* ponteiro para elemento anterior */
	Lista* p = l->prox; /* ponteiro para percorrer a lista*/
 	/* procura elemento na lista, guardando anterior */
	do{ //garantir a travessia da lista mesmo no caso de único nó, partindo do inicial e usando-o tb para teste final
		if (p->info == v)
			break;
		ant = p;
		p = p->prox;	
	}while(p != l->prox); 
	
 	/* verifica se achou elemento */
 	if (ant != NULL && p == l->prox) //ok
 		return l; /* não achou: retorna lista original */
 	//verifica se há apenas 1 nó-dado
 	if (p == p->prox){ 
 		free(p);
 		return NULL;
	}
	
	//achou nó-dado numa lista com 2 ou mais elementos 
	if (ant == NULL && p == l->prox){//ok //primeiro nó-dado em p
		l->prox = p->prox; //último aponta para segundo
		free(p);
		return l;
	}
	
	//senão, é nó intermediário para final
	ant->prox = p->prox;
	if (p == l){//se p aponta para o último nó-dado
		l = ant;
	} 
	free(p);
	return l;
}

bool busca_dado (Lista* l, int v){
	if(vazia(l)) return false;
	
	Lista* aux = l->prox;
	
	do{ // realiza a busca até encontrar a primeira aparição
		if (aux->info == v)
			break;
		aux = aux->prox;	
	}while(aux != l->prox); 
	
	if(aux->info == v)
		return true;
	
	return false;
}

Lista* libera(Lista* l){
	if(vazia(l)){
		cout << "Lista vazia!" << endl;
		return l;
	}
	
	Lista* p = l->prox;
	
	
	do{ // realiza a busca até encontrar a primeira aparição
		Lista* temp = p->prox; // guarda referência para o próximo elemento
		free(p); // libera a memória apontada por p
		p = temp;
		
	}while(p != l->prox);
	
	cout << "Lista liberada!" << endl;
	return NULL;		
}
