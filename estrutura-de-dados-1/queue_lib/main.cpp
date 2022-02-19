#include <iostream>
#include <conio.h>
#include <locale>
#include "fila.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	Lista *l;
	l = criaFila();
	
	cout << "Tamanho atual da fila: " << size(l) << endl;
	cout << "Elemento na frente da fila: " << front(l) << endl;
	cout << "A fila está vazia?: " << (isEmpty(l) ? "Sim" : "Não") << endl << endl;
	
 	enqueue(l, 1); // insere na lista o elemento 1
	enqueue(l, 2); // insere na lista o elemento 2
	enqueue(l, 3); // insere na lista o elemento 3
	
	mostrar(l);
	cout << endl;	
	
	cout << "Tamanho atual da fila: " << size(l) << endl;
	cout << "Elemento na frente da fila: " << front(l) << endl;
	cout << "A fila está vazia?: " << (isEmpty(l) ? "Sim" : "Não") << endl << endl;
	
	dequeue(l); // remove o elemento na frente da fila
	dequeue(l); // remove o elemento na frente da fila
	
	mostrar(l);
	cout << endl;
	
	cout << "Tamanho atual da fila: " << size(l) << endl;
	cout << "Elemento na frente da fila: " << front(l) << endl;
	cout << "A fila está vazia?: " << (isEmpty(l) ? "Sim" : "Não") << endl << endl;
	
	enqueue(l, 4); // insere na lista o elemento 4
	enqueue(l, 5); // insere na lista o elemento 5
	enqueue(l, 6); // insere na lista o elemento 6
	
	mostrar(l);
	cout << endl;	
	
	cout << "Tamanho atual da fila: " << size(l) << endl;
	cout << "Elemento na frente da fila: " << front(l) << endl;
	cout << "A lista está vazia?: " << (isEmpty(l) ? "Sim" : "Não") << endl << endl;	
	
	cout << "Pressione para continuar...";
	getch();
	
	return 0;
}
