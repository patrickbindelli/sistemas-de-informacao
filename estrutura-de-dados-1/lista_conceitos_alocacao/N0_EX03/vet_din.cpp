// Autor: Patrick Venancio Bindelli

#include "vet_din.h"

void realocar(int tam, float *&v){
	
	// Caso o vetor n�o esteja inicizalizado, inicializa-se
	if(v == NULL){
		v = (float *) malloc(tam * sizeof(float));
		
		if(v == NULL){
			cout << "Erro ao alocar mem�ria" << endl; 
			exit(0);
		}
	}// Realocando um novo tamanho para v
	
	v = (float *) realloc(v, tam * sizeof(float));
}

void adicionar(int tam, float *&v, float valor){
	// (tam - n) -> n-1 (indice do vetor)
	v[tam - 1] = valor;
}

// Percorre o vetor e imprime seu conte�do no console
void imprimirVetor(int tam, float *&v){
	if(tam == 0){
		cout << "Vetor n�o inicializado";
	}else{
		for (int i = 0;i < tam; i++){
       		printf("[%.2f] ", v[i]);
		}  
	}
	cout << endl;
}

