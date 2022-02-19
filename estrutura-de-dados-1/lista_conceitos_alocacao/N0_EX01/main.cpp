
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include "teclas.h"

using namespace std;

int main(int argc, char** argv) {
	
	char tecla;
	do{
		cout << "Digite tecla: ";
		tecla = leTecla();
		cout << endl;
		mostraTecla(tecla);
		
	}while((int)tecla != 27);
	
		
	cout << "Fim de programa, tecla ESC foi pressionada!";
	getch();
	return 0;
}

