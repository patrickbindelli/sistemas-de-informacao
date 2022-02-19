
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include "cad_usuarios.h"
void realocar(USUARIO *&u, int tam){
	
	if(u == NULL){
		u = (USUARIO *) malloc(sizeof(USUARIO));
		
		if(u == NULL){
	       cout<< "ERRO AO ALOCAR MEMORIA\n"; 
	       exit(0);
	    }
	}
	
	u = (USUARIO *) realloc(u, tam * sizeof(USUARIO));
}

void adicionar(USUARIO *&u, int tam){
	USUARIO temp;
	char input[50];	
	
	cout << "Nome: ";
	fflush(stdin);
	fgets(temp.nome, 100, stdin);
	temp.nome[strcspn(temp.nome, "\n")] = 0;
	
	cout << "RG: ";
	fflush(stdin);
	fgets(temp.rg, 100, stdin);
	temp.rg[strcspn(temp.rg, "\n")] = 0;
	
	cout << "CPF: ";
	fflush(stdin);
	fgets(temp.cpf, 100, stdin);
	temp.cpf[strcspn(temp.cpf, "\n")] = 0;
	
	cout << "Endereço: ";
	fflush(stdin);
	fgets(temp.endereco, 100, stdin);
	temp.endereco[strcspn(temp.endereco, "\n")] = 0;
	
	realocar(u, tam);
	u[tam - 1] = temp;
}

void imprimirVetor(USUARIO *&u, int tam){
	if(tam == 0){
		cout << "Vetor não inicializado";
	}else{
		for (int i = 0; i < tam; i++){
				printf("{ Nome: %s ; RG: %s ; CPF: %s ; Endereço: %s }", u[i].nome, u[i].rg, u[i].cpf, u[i].endereco);
		}  
	}
	cout << endl;
}

