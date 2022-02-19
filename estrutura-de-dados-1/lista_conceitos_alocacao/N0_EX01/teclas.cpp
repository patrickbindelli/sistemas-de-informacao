
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include <iostream>
#include <conio.h>

using namespace std;

// lê o input de uma tecla
char leTecla(){
	char tecla = getch();
	return tecla;
}

// imprime no console a tecla pressionada e o código ASCII da mesma
void mostraTecla(char tecla){
		cout << "Caractere: " << tecla << "| Dec. ASCII: " << (int)tecla << endl << endl;
}

