
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include "cad_livros.h"
#include <locale>
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	int op;
	
	LIVRO *livros;
	int num_comp = 0;
	
	
	do{
		cout << "Tela Principal" << endl << endl;
		cout << "1- Cadastrar livro" << endl;
		cout << "2- Consultar todos os livros" << endl;
		cout << "3- Sair" << endl;
		
		cout << endl << "Opção: ";
		fflush(stdin);
		cin >> op;
		
		switch(op){
			case 1:
				system("cls");
				num_comp++;
				cadastrarLivro(livros, num_comp);
				system("cls");
				break;
			case 2:
				imprimirLivros(livros, num_comp);
				system("cls");
				break;
			case 3:
				gravaArquivo(livros, num_comp);
				break;
		}
		
	}while(op != 3);
	
	cout << endl << "Programa finalizado !" << endl;
	return 0;
}
