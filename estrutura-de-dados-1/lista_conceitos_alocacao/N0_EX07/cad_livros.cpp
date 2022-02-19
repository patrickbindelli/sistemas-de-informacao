
// Patrick Venancio Bindelli - 2021 - Sistemas de Informação - FeMASS - 2001130029

#include "cad_livros.h"

void cadastrarLivro(LIVRO *&l, int &tam){

	if(tam == 0){
		l = (LIVRO *) malloc(sizeof(LIVRO));
	}	
	tam++;
	realocar(l, tam);
	
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
	
	adicionarLivro(l, tam, cad);
	
	system("cls");
	cout << "Cadastro Efetuado !\n\nPressione para continuar..." << endl;
	getch();
	
}

void realocar(LIVRO *&l, int tam){
	if(l == NULL){
		l = (LIVRO *) malloc(tam * sizeof(LIVRO));
	
		if(l == NULL){
	       cout<< "ERRO AO ALOCAR MEMORIA\n"; 
	       
	       exit(0);
   		}
	}
	
	l = (LIVRO *) realloc(l, tam * sizeof(LIVRO));
}

void adicionarLivro(LIVRO *&l, int tam, LIVRO add){
	// (tam - n) -> n-1 (indice do vetor)
	l[tam - 1] = add;
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
	 
	fstream dados;
   	dados.open("Arquivo.txt", ios::ate | ios::out);
   	
   	
   	dados.write( (char *)l, tam * sizeof(LIVRO));
	
   	dados.close();
   	cout << "Arquivo salvo." << endl;
}

void leArquivo(LIVRO *&l, int &tam){
	fstream dados;
	dados.open("Arquivo.txt", ios::ate | ios::in);
	
	if (dados.tellg() == 0) {   
		system("cls");
  		cout << "ERRO: [Base de dados vazia]" << endl << endl;
  		dados.close();
  		return;
	}
	
	
	if(tam == 0){
		tam = dados.tellg() / sizeof(LIVRO);
		realocar(l, tam);
		
		dados.seekg(0);
		
		dados.read( (char *)l, tam * sizeof(LIVRO));
		
		system("cls");
		cout << "Arquivo carregado com sucesso !" << endl << endl;
		
	}else{
		system("cls");
		cout << "ERRO: [Não foi possível carregar o arquivo]" << endl << endl;	
	}
	
	dados.close();
}

