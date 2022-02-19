
// Patrick Venancio Bindelli - 2021 - Sistemas de Informa��o - FeMASS - 2001130029


#include <locale>
#include "cad_usuarios.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	USUARIO* usuarios; //definindo o ponteiro v
    int num_comp = 0;
    realocar(usuarios, num_comp);
				
	int op;
	cout << "1- Cadastrar Usu�rio" << endl;
	cout << "2- Exibir usu�rio(s) cadastrados" << endl;
	cout << "3- Exibir quantidade de usu�rios cadastrados" << endl;
	cout << "4- Remover �ltimo usu�rio cadastrado" << endl;
	cout << "5- Sair" << endl << endl;
	
	do{
		cout << "Op��o: ";
		fflush(stdin);
		cin >> op;
	
		switch(op){
			case 1:
				num_comp++;
				adicionar(usuarios, num_comp);
				break;
			case 2:
				imprimirVetor(usuarios, num_comp);
				break;
			case 3: 
				cout << "N�meros cadastrados: " << num_comp << endl;
				break;
			case 4:
				num_comp--;
				if(num_comp <= 0) num_comp = 0;
				realocar(usuarios, num_comp);	
				break;
			default:
				if(op != 5) cout << "Op��o Inv�lida" << endl;
		}
		cout << endl;
	}while(op != 5);

	
	free(usuarios);
	return 0;
}
