#include "lista.h"
#include <locale>
#include <conio.h>


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	Lista* l;
	l = inicializa();
	
	int op;
	
	do{
		cout << "[Manipulação de Lista Encadeada Simples]" << endl;
		cout << "----------------------------------------" << endl << endl;
			
		cout << "[ Menu Principal ]" << endl << endl;
		
		cout << "1. Inserir no início" << endl;
		cout << "2. Inserir no fim"<< endl;
	
		cout << "3. Remover início"<< endl;
		cout << "4. Remover fim"<< endl;
		cout << "5. Remover por busca"<< endl;
		
		cout << "6. Buscar"<< endl;
		cout << "7. Checar todas as ocorrências"<< endl;
		cout << "8. Imprimir lista completa"<< endl;
		cout << "9. Imprimir Números de componentes"<< endl << endl;
		cout << "-------------------------------------------"<< endl;
		cout << "0. Sair"<< endl << endl;
		
		cout << "Opção: ";
		cin >> op;
		
		system("cls");
		int v;
		switch(op){
			case 1:
				cout << "[ Inserir no início ]" << endl << endl;
				cout << "Adicionar valor: ";
				cin >> v;
				
				l = insere(l, v);
				
				cout << endl << "> Valor adicionado !" << endl;
				system("cls");
				break;
				
			case 2:
				cout << "[ Inserir no final ]" << endl << endl;
				cout << "Adicionar valor: ";
				cin >> v;
				
				l = insereFim(l, v);
				
				cout << endl << "> Valor adicionado !" << endl;
				system("cls");
				break;
				
			case 3:
				system("cls");
				l = removeInicio(l);
				
				cout << endl << "> Valor Removido !" << endl;
				
				break;
				
			case 4:
				system("cls");
				l = removeFim(l);
				
				cout << endl << "> Valor Removido !" << endl;
				break;
				
			case 5:
				cout << "[ Remover por busca ]" << endl << endl;
				cout << "Remover valor: ";
				cin >> v;
				
				l = retira(l, v);
				cout << "Pressione para continuar...";
				getch();
				
				system("cls");
				break;
				
			case 6:
				cout << "[ Buscar ]" << endl << endl;
				cout << "Buscar valor: ";
				cin >> v;
				
				l = busca(l, v);
				cout << "Pressione para continuar...";
				getch();
				system("cls");
				break;
				
			case 7:
				cout << "[ Buscar Ocorrências ]" << endl << endl;
				cout << "Buscar valor: ";
				cin >> v;
				
				if(ocorrencias(l, v) == 0){
					cout << endl << "Valor não encontrado !" << endl << endl;
				}else{
					cout << endl << "O valor aparece: " << ocorrencias(l, v) << " vezes" << endl << endl;
				}
				
				cout << "Pressione para continuar...";
				getch();
				system("cls");
				break;
				
			case 8:
				system("cls");
				imprime(l);
				cout << "Pressione para continuar...";
				getch();
				system("cls");
				break;
				
			case 9:
				cout << endl << "A lista possui " << tamanho(l) << " elementos" << endl << endl;
				
				cout << "Pressione para continuar...";
				getch();
				system("cls");
				break;
				
			case 0:
				break;
			default:
				cout << "[Opção inválida]" << endl;
		}
		
	}while(op != 0);
	

	system("cls");
	cout << "Programa finalizado" << endl;
	
	return 0;
}
