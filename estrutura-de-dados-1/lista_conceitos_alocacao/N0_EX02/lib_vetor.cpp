
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include "lib_vetor.h"


// exibindo todos os elementos de um vetor de inteiros
void exibeVetor(int tam, int *vet){
	for(int i = 0; i < tam; i++){
		printf("[%d] ", vet[i]);
	}
}


// exibindo os elementos ímpares de um vetor de inteiros
void exibeImpares(int tam, int *vet){
	for(int i = 0; i < tam; i++){
		if(vet[i] % 2 != 0) printf("[%d] ", vet[i]);
	}
}


// exibindo os elementos pares de um vetor de inteiros
void exibePares(int tam, int *vet){
		for(int i = 0; i < tam; i++){
		if(vet[i] % 2 == 0) printf("[%d] ", vet[i]);
	}
}
