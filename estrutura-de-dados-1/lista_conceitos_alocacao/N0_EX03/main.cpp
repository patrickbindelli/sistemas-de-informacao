//Autor: Patrick Venancio Bindelli

#include <iostream>
#include <stdlib.h>
#include <locale>
#include "vet_din.h"
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	float *v; //definindo o ponteiro v
    int num_comp(0);
    float num;
	
	int op;
	cout << "1- Cadastrar número" << endl;
	cout << "2- Exibir número(s) cadastrados" << endl;
	cout << "3- Exibir quantidade de números cadastrados" << endl;
	cout << "4- Remover último número cadastrado" << endl;
	cout << "5- Sair" << endl << endl;
	
	do{
		cout << "Opção: ";
		cin >> op;
		cout << endl;
	
		switch(op){
			case 1:
				num_comp++;
				realocar(num_comp, v);	
				
				cout << "Adicionar: ";
				cin >> num;
		
				adicionar(num_comp, v, num);
				break;
			case 2:
				imprimirVetor(num_comp, v);
				break;
			case 3: 
				cout << "Números cadastrados: " << num_comp << endl;
				break;
			case 4:
				if(num_comp > 0){
					num_comp--;
					realocar(num_comp, v);
				}	
				break;
			case 5:
				free(v);
				cout << endl << "Programa finalizado." << endl;
				exit(0);
			default:
				cout << "Opção Inválida" << endl;
		}
		cout << endl;
	}while(true);

	
	free(v);
	return 0;
}
