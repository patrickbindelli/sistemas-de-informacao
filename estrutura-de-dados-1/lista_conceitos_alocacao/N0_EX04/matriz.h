
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void inicializaMatriz(char **&matriz, int &l, int &c);
void inicializaMatriz(int **&ascii, int &l, int &c);

void adicionaLinha(char **&matriz, int &l, int &c);
void adicionaColuna(char **&ascii, int &l, int &c);

void removeLinha(char **&matriz, int &l, int &c);
void removeColuna(char **&matriz, int &l, int &c);

void populaMatriz(char **&matriz, int &l, int &c, char ch);

void imprimirMatriz(char **&matriz, int &l, int &c);
void imprimirMatriz(int **&ascii, int &l, int &c);



