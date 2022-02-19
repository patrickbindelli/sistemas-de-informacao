
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct // Cria uma STRUCT para armazenar os dados de uma USUARIO
{
    char nome[50];
    char rg[50];
    char cpf[50];
    char endereco[50];
} USUARIO; // Define o nome do novo tipo criado

void realocar(USUARIO *&usuarios, int tam);
void adicionar(USUARIO *&usuarios, int tam);
void imprimirVetor(USUARIO *&usuarios, int tam);

