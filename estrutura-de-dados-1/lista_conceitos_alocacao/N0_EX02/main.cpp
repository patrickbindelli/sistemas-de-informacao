
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include "lib_vetor.h"
#include <stdlib.h>
#include <conio.h>
#include <locale>

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");

	int tam = 10;
	int op, vetor[tam] = {0};
	
	for(int i = 0; i < tam; i++){
		cout << "Inserir número " << 1 + i << ": ";
		cin >> vetor[i];
	} 
	
	cout << endl;
	cout << "1) Exibir vetor informado" << endl;
	cout << "2) Exibir elementos ímpares" << endl;
	cout << "3) Exibir elementos pares no vetor" << endl;
	cout << "4) Encerrar o programa" << endl;
		
	do{	
		cout<< endl << "Opção: ";
		cin >> op;
		cout << endl;
		
		switch(op){
			case 1:
				exibeVetor(tam, vetor);
				break;
			case 2:
				exibeImpares(tam, vetor);
				break;
			case 3:
				exibePares(tam, vetor);
				break;
			case 4:
				cout << "Programa finalizado." << endl;
				exit(0);
			default: 
				//system("cls");
				cout << "Opção Inválida" << endl;
				continue;
		}
		
		cout << endl;
		
	}while(true);
	
	return 0;
}
