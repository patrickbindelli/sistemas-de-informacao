#include "lista.h"
#include <locale>
#include <conio.h>

void continuar(){
	cout << endl << "Pressione para continuar...";
	getch();
	system("cls");
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	Lista* l;
	l = inicializa();
	
	int op;
	
	do{
		cout << "[Manipula��o de Lista Encadeada Simples]" << endl;
		cout << "----------------------------------------" << endl << endl;
			
		cout << "[ Menu Principal ]" << endl << endl;
		
		cout << ">>> Inser��o:" << endl << endl;
		cout << "1. Inserir no in�cio" << endl;
		cout << "2. Inserir no fim"<< endl;
		cout << endl;
	
		cout << ">>> Remo��o:" << endl << endl;
		cout << "3. Remover in�cio"<< endl;
		cout << "4. Remover fim"<< endl;
		cout << "5. Remover elemento"<< endl;
		cout << endl;
		
		cout << ">>> Impress�o:" << endl << endl;
		cout << "6. Buscar elemento"<< endl;
		cout << "7. Mostra in�cio"<< endl;
		cout << "8. Mostra Fim"<< endl;
		cout << "9. Checar todas as ocorr�ncias"<< endl;
		cout << "10. Imprimir lista completa"<< endl;
		cout << "11. Imprimir N�meros de componentes"<< endl;
		cout << endl;
		
		cout << "12. Liberar lista"<< endl;
		cout << "13. Verificar se a lista est� vazia"<< endl << endl;
		
		cout << "-------------------------------------------"<< endl << endl;
		cout << "0. Sair"<<  endl << endl;
		
		cout << "Op��o: ";
		cin >> op;
		
		system("cls");
		int v;
		switch(op){
			case 1:
				cout << "[ Inserir no in�cio ]" << endl << endl;
				cout << "Adicionar valor: ";
				cin >> v;
				
				l = insereInicio(l, v);
				system("cls");
				break;
				
			case 2:
				cout << "[ Inserir no final ]" << endl << endl;
				cout << "Adicionar valor: ";
				cin >> v;
				
				l = insereFim(l, v);
				system("cls");
				break;
				
			case 3:
				system("cls");
				l = removeInicio(l);
				continuar();
				break;
				
			case 4:
				system("cls");
				l = removeFim(l);
				continuar();
				break;
				
			case 5:
				cout << "[ Remover Valor ]" << endl << endl;
				cout << "Buscar valor: ";
				cin >> v;
				retira(l, v);
				continuar();
				break;
				
			case 6:
				cout << "[ Buscar ]" << endl << endl;
				cout << "Buscar valor: ";
				cin >> v;
				printf("%s", (busca_dado(l, v) ? "\Valor existe na lista\n" : "\nValor n�o encontrado\n"));
				continuar();
				break;
				
			case 7:
				system("cls");
				if(mostraInicio(l) == NULL) cout << "Lista vazia!" << endl;
				else cout << "Inicio: " << mostraInicio(l)->info << endl;
				continuar();
				break;
				
			case 8:
				system("cls");
				if(mostraInicio(l) == NULL) cout << "Lista vazia!" << endl;
				else cout << "Fim: " << mostraFim(l)->info << endl;
				continuar();
				break;
				
			case 9:
				cout << "[ Buscar Ocorr�ncias ]" << endl << endl;
				cout << "Buscar valor: ";
				cin >> v;
				cout << endl << "O valor aparece: " << ocorrencias(l, v) << " vezes" << endl;
				continuar();
				break;
				
			case 10:
				system("cls");
				imprime(l);
				continuar();
				break;
				
			case 11:
				cout << endl << "A lista possui " << tamanho(l) << " elementos" << endl;
				continuar();
				break;
				
			case 12:
				l = libera(l);
				continuar();
				break;
				
			case 13:
				printf("%s", (vazia(l) ? "A lista est� vazia" : "A lista n�o est� vazia"));
				continuar();
				break;
				
				
			case 0:
				break;
				
			default:
				cout << "[Op��o inv�lida]" << endl;
		}
		
	}while(op != 0);
	
	free(l);
	system("cls");
	cout << "Programa finalizado" << endl;
	
	return 0;
}
