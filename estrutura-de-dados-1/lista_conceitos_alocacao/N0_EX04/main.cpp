
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "matriz.h"

using namespace std;	

int main(int argc, char** argv) {
	
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// !Deve funcionar com o TDM-GCC padrão do Dev-CPP, mas talvez seja melhor usar outro compilador!
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
		
		// Caso o usuário pressione ESC, o loop é quebrado
		if((int)tecla == 27) break;
		
		// Caso o usuário pressione RETURN (ENTER), é adicionada uma linha na matriz (quebra de linha)
		// Nesse caso não estou salvando o caractere relativo a quebra de linha
		if((int) tecla == 13){
			adicionaLinha(matriz, l, c);
			index_col = 0; // Contador que controla onde estamos na matriz
			cout << endl;
			continue;
		}
		
		// Caso o usuário pressione a tecla BACKSPACE
		// Se o usuário estiver na primeira linha da matriz, o programa apenas libera uma coluna (Evita que a matriz cresça muito em colunas vazias)
		// Se o usuário estiver em outra linha, preenche a coluna com um espaço em branco
		if((int)tecla == 8){
			if(l == 1 || index_col == c) removeColuna(matriz, l, c);
			else matriz[l - 1][index_col - 1] =  ' ';
			index_col--; // Contador que controla onde estamos na matriz
			cout << "\b" ; // Volta um caractere, infelizmente não consegui fazer apagar o caractere anterior sem muito trabalho
			continue;
		}
		
		// Caso não caia em nenhuma das outras condições
		if(index_col == c) adicionaColuna(matriz, l, c); // Caso ja esteja na utima coluna da matriz, adiciona uma nova
		matriz[l-1][index_col] = tecla; // Adiciona a tecla digitada na matriz
		cout << matriz[l-1][index_col]; // Retorna em tela a tecla adicionada
		index_col++; // Contador que controla onde estamos na matriz
		
	}while(true);
	
	// Inicializando uma matriz para guardar a versão ascii do texto
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
	
	// Liberando ambas as matrizes dinãmicas da memória
	free(matriz);
	free(ascii);
	
	cout << "Fim de programa, tecla ESC foi pressionada!" << endl;
	return 0;
}

