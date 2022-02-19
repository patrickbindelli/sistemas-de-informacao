
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
		cout << "(Um arquivo será salvo ao fechar o programa pelo menu)" << endl;
		cout << "Tela Principal" << endl << endl;
		cout << "1- Cadastrar livro" << endl;
		cout << "2- Consultar todos os livros" << endl;
		cout << "3- Carregar base de dados do arquivo" << endl;
		cout << "4- Sair" << endl;
		
		cout << endl << "Opção: ";
		fflush(stdin);
		cin >> op;
		
		switch(op){
			case 1:
				system("cls");
				cadastrarLivro(livros, num_comp);
				system("cls");
				break;
			case 2:
				cout << num_comp;
				imprimirLivros(livros, num_comp);
				system("cls");
				break;
			case 3:
				leArquivo(livros, num_comp);
				break;
			case 4:
				gravaArquivo(livros, num_comp);
				free(livros);
				exit(0);
				break;
			default:
				system("cls");
				break;
		}
		
	}while(true);
	
	cout << endl << "Programa finalizado !" << endl;
	free(livros);
	return 0;
}
