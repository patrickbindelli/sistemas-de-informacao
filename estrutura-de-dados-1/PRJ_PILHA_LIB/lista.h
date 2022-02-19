	#include <iostream>
	#include <stdlib.h>
	
	using namespace std;
	
	struct lista {
		int info;
		struct lista* prox;
	};
	
	typedef struct lista Lista;
		
		/* função de inicialização: retorna uma lista vazia */
	Lista* inicializa (void);
	Lista* insere (Lista* l, int i);
	void imprime (Lista* l);
	bool vazia (Lista* l);
	Lista* busca (Lista* l, int v);
	Lista* retira (Lista* l, int v);
	void libera (Lista* l);
	
	Lista* mostraInicio (Lista* l);
	Lista* mostraFim (Lista* l);
	int tamanho(Lista* l);
	int ocorrencias (Lista* l, int v);
	 
	Lista* insereFim (Lista* l, int i);
	Lista* removeInicio (Lista* l);
	Lista* removeFim (Lista* l);
