
// Patrick Venancio Bindelli - 2021 - Sistemas de Informa��o - FeMASS - 2001130029

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "matriz.h"

using namespace std;	

int main(int argc, char** argv) {
	
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// !Deve funcionar com o TDM-GCC padr�o do Dev-CPP, mas talvez seja melhor usar outro compilador!
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	// Inicializando uma matriz 0x0;
	char **matriz;	
	int l = 1, c = 0;
	
	inicializaMatriz(matriz, l, c);
	
	char tecla;
	int index_col = 0;
	
	cout << "[ESC] - Encerrar" << endl;
	cout << "Digite: " << endl << endl;
	
	do{
		tecla = getch();
		
		// Caso o usu�rio pressione ESC, o loop � quebrado
		if((int)tecla == 27) break;
		
		// Caso o usu�rio pressione RETURN (ENTER), � adicionada uma linha na matriz (quebra de linha)
		// Nesse caso n�o estou salvando o caractere relativo a quebra de linha
		if((int) tecla == 13){
			adicionaLinha(matriz, l, c);
			index_col = 0; // Contador que controla onde estamos na matriz
			cout << endl;
			continue;
		}
		
		// Caso o usu�rio pressione a tecla BACKSPACE
		// Se o usu�rio estiver na primeira linha da matriz, o programa apenas libera uma coluna (Evita que a matriz cres�a muito em colunas vazias)
		// Se o usu�rio estiver em outra linha, preenche a coluna com um espa�o em branco
		if((int)tecla == 8){
			if(l == 1 || index_col == c) removeColuna(matriz, l, c);
			else matriz[l - 1][index_col - 1] =  ' ';
			index_col--; // Contador que controla onde estamos na matriz
			cout << "\b" ; // Volta um caractere, infelizmente n�o consegui fazer apagar o caractere anterior sem muito trabalho
			continue;
		}
		
		// Caso n�o caia em nenhuma das outras condi��es
		if(index_col == c) adicionaColuna(matriz, l, c); // Caso ja esteja na utima coluna da matriz, adiciona uma nova
		matriz[l-1][index_col] = tecla; // Adiciona a tecla digitada na matriz
		cout << matriz[l-1][index_col]; // Retorna em tela a tecla adicionada
		index_col++; // Contador que controla onde estamos na matriz
		
	}while(true);
	
	// Inicializando uma matriz para guardar a vers�o ascii do texto
	int **ascii;
	inicializaMatriz(ascii, l, c);
	
	// Copiando os valores da matriz de caracteres como inteiros para a nova matriz (Seus codigos ASCII)
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			ascii[i][j] = (int) matriz[i][j];
		}
	}
	
	// Prints finais em tela
	cout << "Matriz Gerada: ";
	cout << endl << endl;
	imprimirMatriz(matriz, l, c);
	
	cout << "Em ASCII: ";
	cout << endl << endl;
	imprimirMatriz(ascii, l, c);
	
	// Liberando ambas as matrizes din�micas da mem�ria
	free(matriz);
	free(ascii);
	
	cout << "Fim de programa, tecla ESC foi pressionada!" << endl;
	return 0;
}

