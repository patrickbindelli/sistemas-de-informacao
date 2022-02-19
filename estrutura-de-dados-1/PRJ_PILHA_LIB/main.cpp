#include <iostream>
#include <conio.h>
#include <locale>
#include "pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	Lista* l; 
 	l = criaPilha(); // inicializa a pilha com NULL;
 	
 	cout << "Tamanho atual da pilha: " << size(l) << endl;
	cout << "Elemento no topo da pilha: " << top(l) << endl;
	cout << "A pilha está vazia?: " << (isEmpty(l) ? "Sim" : "Não") << endl << endl;
	
	
 	l = push(l, 1); // insere na lista o elemento 1
	l = push(l, 2); // insere na lista o elemento 2
	l = push(l, 3); // insere na lista o elemento 3
	
	mostrar(l);
	cout << endl;	
	
	cout << "Tamanho atual da pilha: " << size(l) << endl;
	cout << "Elemento no topo da pilha: " << top(l) << endl;
	cout << "A pilha está vazia?: " << (isEmpty(l) ? "Sim" : "Não") << endl << endl;
	
	l = pop(l); // remove o elemento no topo da pilha
	l = pop(l); // remove o elemento no topo da pilha
	
	mostrar(l);
	cout << endl;
	
	cout << "Tamanho atual da pilha: " << size(l) << endl;
	cout << "Elemento no topo da pilha: " << top(l) << endl;
	cout << "A pilha está vazia?: " << (isEmpty(l) ? "Sim" : "Não") << endl << endl;
	
	l = push(l, 4); // insere na lista o elemento 4
	l = push(l, 5); // insere na lista o elemento 5
	l = push(l, 6); // insere na lista o elemento 6
	
	mostrar(l);
	cout << endl;	
	
	cout << "Tamanho atual da pilha: " << size(l) << endl;
	cout << "Elemento no topo da pilha: " << top(l) << endl;
	cout << "A lista está vazia?: " << (isEmpty(l) ? "Sim" : "Não") << endl << endl;	
	
	cout << "Pressione para continuar...";
	getch();
	return 0;
}

	
