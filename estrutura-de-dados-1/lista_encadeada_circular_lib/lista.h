	#include <iostream>
	#include <stdlib.h>
	
	using namespace std;
	
	struct lista {
		int info;
		struct lista* prox;
	};
	
	typedef struct lista Lista;
	
	// inserção
	Lista* inicializa (void);
	Lista* insereInicio (Lista* l, int i);
	Lista* insereFim (Lista* l, int i);
	
	// impressão
	void imprime (Lista* l);
	Lista* mostraInicio (Lista* l);
	Lista* mostraFim (Lista* l);
	
	// retorno
	bool vazia (Lista* l);
	int tamanho (Lista* l);
	int ocorrencias (Lista* l, int v);
	bool busca_dado (Lista* l, int v);
	
	// remoção
	Lista* removeInicio (Lista* l);
	Lista* removeFim (Lista* l);
	Lista* retira (Lista* l, int v);
	Lista* libera(Lista* l);
	

