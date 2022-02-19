
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include "cad_livros.h"

void cadastrarLivro(LIVRO *&l, int &tam){	
	// Struct temporário para guardar os dados a serem adicionados
	LIVRO cad;

	cout << "Cadastrar Livro" << endl << endl;
				
	cout << "Informe nome: ";
	fflush(stdin);
	fgets(cad.nome, 50, stdin);
	cad.nome[strcspn(cad.nome, "\n")] = 0;
				
	cout << "Informe cod.: ";
	fflush(stdin);
	cin >> cad.cod;
				
	cout << "Informe autor: ";
	fflush(stdin);
	fgets(cad.autor, 50, stdin);
	cad.autor[strcspn(cad.autor, "\n")] = 0;
				
	cout << "Informe ano pub.: ";
	fflush(stdin);
	cin >> cad.anoPub;
	
	// Realoca-se o vetor e em seguida adiciona-se um elemento
	realocar(l, tam);
	l[tam - 1] = cad;
	
	system("cls");
	cout << "Cadastro Efetuado !\n\nPressione para continuar..." << endl;
	getch();
	
}

void realocar(LIVRO *&l, int tam){
	if(l == NULL){
		l = (LIVRO *) malloc(sizeof(LIVRO));
	
		if(l == NULL){
	       cout<< "ERRO AO ALOCAR MEMORIA\n"; 
	       
	       exit(0);
   		}
	}
	
	l = (LIVRO *) realloc(l, tam * sizeof(LIVRO));
}

void imprimirLivros(LIVRO *&l, int tam){
	if(tam == 0){
		cout << "Nenhum livro cadastrado !";
	}else{
		printf("Nomes Livros \tCodigo \tAutor \tAno\n\n");
		for (int i = 0; i < tam; i++){
			printf("%-12s \t%03d \t%-5s \t%04d\n", l[i].nome, l[i].cod, l[i].autor, l[i].anoPub);
		}  
	}
	
	cout << endl << endl;
	system("Pause");
}

void gravaArquivo(LIVRO *&l, int tam){
	if(tam == 0) return;
	FILE* arquivo = fopen("Arquivo.txt", "w");

	fprintf(arquivo, "Nomes Livros \tCodigo \tAutor \tAno\n\n");
	
	for (int i = 0; i < tam; i++){
		fprintf(arquivo, "%-9s \t%03d \t%-9s \t%04d\n", l[i].nome, l[i].cod, l[i].autor, l[i].anoPub); 
	}
	
	cout << endl << "Os livros foram salvos em livros.txt" << endl;
	fclose(arquivo);
}

