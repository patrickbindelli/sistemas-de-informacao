#include "lista.h"

// inicializa a lista
Lista* inicializa (void){ return NULL; }

// insere n�-dado no in�cio da lista
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

// insere n�-dado ao fim da lista
Lista* insereFim (Lista* l, int i){

	// Verifica se a lista est� vazia
	// Nesse caso s� se pode inserir no in�cio, ent�o reutilizamos a fun��o
	if(vazia(l)) return insereInicio(l, i);
	
	// Caso contrario, adiciona ap�s o �ltimo elemento
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l->prox;
	l->prox = novo;
	cout << endl << "Valor adicionado!" << endl;
	return novo;
}

// imprime os valores de todo n�-dado da lista
void imprime (Lista* l){
	
	if(vazia(l)){
		cout << "Lista vazia!" << endl;
		return;
	}
	
	Lista* aux = l->prox; /* vari�vel auxiliar para percorrer a lista */
	
	printf("info: ");
	do{
		printf("[%d] ", aux->info);
		aux = aux->prox;
	}while(aux != l->prox);
	cout << endl;
}

// retorna o n�-dado no in�cio da lista para exibi��o, sem retir�-lo
Lista* mostraInicio (Lista* l){
	if(!vazia(l)){
		return l->prox;
	}
	
	return NULL;
}

// retornar o n�-dado no fim da lista para exibi��o, sem retir�-lo
Lista* mostraFim (Lista* l){
	if(!vazia(l)){
		return l;
	}
	
	return NULL;
}

// checa se a lista est� vazia
bool vazia (Lista* l){
	return (l == NULL);
}

// retorna um valor inteiro representando a quantidade de dados contidos na lista, para que seja informado ao usu�rio
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

// retorna o n�mero de ocorr�ncias de um dado valor inteiro informado pelo usu�rio na lista (lembrando que a lista poder� conter dados repetidos)
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

// remove n�-dado no in�cio da Lista
Lista* removeInicio (Lista* l){
	if(vazia(l)){
		cout << "Lista vazia!" << endl;
		return l;
	}
	
	if(tamanho(l) == 1) return NULL;
	
	Lista* aux = l;
	aux->prox = l->prox->prox;
	cout << "In�cio removido!" << endl;
	return aux;
}

// remove n�-dado no fim da Lista
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
	do{ //garantir a travessia da lista mesmo no caso de �nico n�, partindo do inicial e usando-o tb para teste final
		if (p->info == v)
			break;
		ant = p;
		p = p->prox;	
	}while(p != l->prox); 
	
 	/* verifica se achou elemento */
 	if (ant != NULL && p == l->prox) //ok
 		return l; /* n�o achou: retorna lista original */
 	//verifica se h� apenas 1 n�-dado
 	if (p == p->prox){ 
 		free(p);
 		return NULL;
	}
	
	//achou n�-dado numa lista com 2 ou mais elementos 
	if (ant == NULL && p == l->prox){//ok //primeiro n�-dado em p
		l->prox = p->prox; //�ltimo aponta para segundo
		free(p);
		return l;
	}
	
	//sen�o, � n� intermedi�rio para final
	ant->prox = p->prox;
	if (p == l){//se p aponta para o �ltimo n�-dado
		l = ant;
	} 
	free(p);
	return l;
}

bool busca_dado (Lista* l, int v){
	if(vazia(l)) return false;
	
	Lista* aux = l->prox;
	
	do{ // realiza a busca at� encontrar a primeira apari��o
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
	
	
	do{ // realiza a busca at� encontrar a primeira apari��o
		Lista* temp = p->prox; // guarda refer�ncia para o pr�ximo elemento
		free(p); // libera a mem�ria apontada por p
		p = temp;
		
	}while(p != l->prox);
	
	cout << "Lista liberada!" << endl;
	return NULL;		
}
