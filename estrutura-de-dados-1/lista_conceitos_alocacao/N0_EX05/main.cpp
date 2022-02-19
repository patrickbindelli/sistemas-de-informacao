
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029


#include <locale>
#include "cad_usuarios.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	USUARIO* usuarios; //definindo o ponteiro v
    int num_comp = 0;
    realocar(usuarios, num_comp);
				
	int op;
	cout << "1- Cadastrar Usuário" << endl;
	cout << "2- Exibir usuário(s) cadastrados" << endl;
	cout << "3- Exibir quantidade de usuários cadastrados" << endl;
	cout << "4- Remover último usuário cadastrado" << endl;
	cout << "5- Sair" << endl << endl;
	
	do{
		cout << "Opção: ";
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
				cout << "Números cadastrados: " << num_comp << endl;
				break;
			case 4:
				num_comp--;
				if(num_comp <= 0) num_comp = 0;
				realocar(usuarios, num_comp);	
				break;
			default:
				if(op != 5) cout << "Opção Inválida" << endl;
		}
		cout << endl;
	}while(op != 5);

	
	free(usuarios);
	return 0;
}
