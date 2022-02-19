
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>


using namespace std;

typedef struct // Cria uma STRUCT para armazenar os dados de uma LIVRO
{
    char nome[50];
    int cod;
    char autor[50];
    int anoPub;
    
} LIVRO; 

void cadastrarLivro(LIVRO *&l, int &tam);
void realocar(LIVRO *&l, int tam);
void adicionarLivro(LIVRO *&l, int tam, LIVRO add);
void imprimirLivros(LIVRO *&l, int tam);
void gravaArquivo(LIVRO *&l, int tam);
void leArquivo(LIVRO *&l, int &tam);
