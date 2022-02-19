
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include "matriz.h"


void inicializaMatriz(char **&matriz, int &l, int &c){
	matriz = (char **)malloc(l * sizeof(char *));
	for (int i=0; i<l; i++){
		matriz[i] = (char *)malloc(c * sizeof(char)); 
	}
	
	if (matriz == NULL){
		cout << "Erro ao alocar memória";
		exit(0);
	}
}

void inicializaMatriz(int **&ascii, int &l, int &c){
	ascii = (int **)malloc(l * sizeof(int *));
	
	for (int i=0; i<l; i++){
		ascii[i] = (int *)malloc(c * sizeof(int)); 
	}
	
	if (ascii == NULL){
		cout << "Erro ao alocar memória";
		exit(0);
	}
}

void adicionaLinha(char **&matriz, int &l, int &c){
	l++; 
	
	// inicializando uma matriz temporaria
	char **m2; 
	inicializaMatriz(m2, l, c);
	
	// Copiando os valores da matriz original para a temporaria
	for(int i = 0; i < l - 1; i++){
		for(int j = 0; j < c; j++){
			m2[i][j] = matriz[i][j];
		}
	}
    
    // Libera-se totalmente a matriz original e reinicializa com o novo numero de linhas
    free(matriz);
	inicializaMatriz(matriz, l, c);
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			matriz[i][j] = ' ';
		}
	}
	
	// Retornando os valores originais para a matriz original
	matriz = m2;
}

void adicionaColuna(char **&matriz, int &l, int &c){
	c++;
	int i;
	for (i = 0; i < l; i++){
		matriz[i] = (char *)realloc(matriz[i], c * sizeof(char)); //adicionando coluna em cada linha existente...
	}
        
	for (i = 0; i < l ; i++){ //fixar coluna em adição e iterar linha para atribuição
		matriz[i][c-1] = ' ';
	}
}

// Removendo uma linha ou uma coluna de uma matriz dinâmica
void removeLinha(char **&matriz, int &l, int &c){
	l--;
	matriz = (char **)realloc(matriz,  l* sizeof(char*)); //removendo uma nova linha, com o nº padrão de colunas atuais nesta
}

void removeColuna(char **&matriz, int &l, int &c){
	c--;
	for (int i = 0; i < l; i++) //para cada linha existente, adicionar coluna... 
         matriz[i] = (char *)realloc(matriz[i], c * sizeof(char)); //adicionando coluna em cada linha existente...
}

// Usada em testes para popular uma matriz
void populaMatriz(char **&matriz, int &l, int &c, char ch){
	for (int i = 0; i <  l; i++){
		for (int j = 0; j < c; j++){
			matriz[i][j] = ch; 
		}
	}
}

// Imprimem uma matriz char ou int na tela

void imprimirMatriz(char **&matriz, int &l, int &c){
	for (int i = 0; i <  l; i++){
    	for (int j = 0; j < c; j++){
        	printf("[%c]", matriz[i][j]); 
		}
		cout << endl;	
	}
	cout << endl;	
}

void imprimirMatriz(int **&ascii, int &l, int &c){
	for (int i = 0; i <  l; i++){
    	for (int j = 0; j < c; j++){
        	printf("[%03d]", ascii[i][j]); 
		}
		cout << endl;	
	}
	cout << endl;	
}


