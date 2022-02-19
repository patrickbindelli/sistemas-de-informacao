//
// Patrick Venancio Bindelli - 2001130029 - nov/2021
//

#include <iostream>
#include <locale>
#include <math.h>
using namespace std;

bool checaParada(int n, float *X, float *Xant, float erro);

int main(){
	
	setlocale(LC_ALL, "");
	
	// � possivel que o locale troque o . pela , em algumas m�quinas
	// Foi utilizado um erro de 0.001 nos exerc�cios
	

	int n = 0;
	float erro = 0;

	
	cout << "\nOrdem do sistema: ";
	cin >> n;
	
	float X[n] = {0};
	float solucao[n] = {0};
	
	float A[n][n], b[n];
	float B[n][n] = {0};
	float g[n];

	float XAnt[n] = {0};
	int cont = 0;
	
	// Usando a condi��o de parada por compara��o a um erro
	cout << "\nErro aceitavel (0.001): ";
	cin >> erro;
	
	// Como o vetor X ser� incializado
	cout << "\nChute inicial em linha: ";
	for(int i = 0; i < n; i++) {
        cin>>X[i];
    }
	
	// O programa ir� receber as linhas da vers�o matricial do sistema desejado
	cout<<"\nEntre com os valores linha por linha : \n\n";
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n; j++) {
            cin>>A[i][j];
        }
    }
    
    // Checando convergencia
    // Precisa de otimiza��o
    
    float somaLinhas[n] = {0};
	
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != j){
				// Obtendo a soma das linhas, exceto o elemento da diagonal principal
				somaLinhas[i] += fabs(A[i][j]);
			}		
		}
	}
	
	
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				// Caso o elemento da diagonal principal seja menor que a soma dos seus vizinhos
				// o m�todo n�o ir� convergir para um resultado correto
				if (fabs(A[i][j]) < somaLinhas[i]){
					cout << "\nN�o converge\n";
					exit (1);
				}
			}		
		}
	}
	// Checando convergencia

    
    cout<<"\nEntre com os resultados de cada, em linha : \n\n";
    for(int i = 0; i < n ; i++) {
        cin >> b[i];
    }
    
	
	for(int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			// Obtendo a matriz B
			if(i != j){
				
				B[i][j] = (A[i][j] / A[i][i]) * -1;
			}
			
			// Obtendo a matriz g
			g[i] = b[i]/A[i][i];
		}
	}
	
	
	printf("\n\nF�rmula: X(k+1) = B * X(k) + g\n");
	
	for(int i = 0; i < n; i++){
		printf("( ");
		for (int j = 0; j < n; j++){
			printf("[%5.2f] ", B[i][j]);
		}
		printf("* [X%d] ) ", i);
		printf("+ [%5.2f] ", g[i]);
		cout << endl;
	}
	
	cout << endl << endl;
	 
	cout << endl;
	for(int i = 0; i < n; i++){
		printf("X%d \t", i);
	}
	cout << endl;
	
	// Ir� calcular novos valores para o vetor X enquanto o erro n�o for satisfeito
	do{
		
		float R[n] = {0};
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				R[i] += X[j] * B[i][j];
			}
		}
		
		
		for(int i = 0; i < n; i++){
			XAnt[i] = X[i];
			X[i] = R[i] + g[i];
			printf("%.4f \t", X[i]);
		}
		printf("\n");
		
		
		cont++;
		
	}while(checaParada(n, X, XAnt, erro)); 
	
	cout << fixed;
	cout.precision(4);
	cout << endl;
	for(int i = 0; i < n; i++){
		cout << "X" << i << ": " << X[i] << endl;
	}
	
	cout << endl << "Itera��es: " << cont << endl << endl;	
	
	float sol[n] = {0};
	
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sol[i] += A[i][j] * X[j];
		}
	}
	
	printf("\nTeste de solu��o:\n");
	for (int i = 0; i < n; i++){
		cout << sol[i] << endl;
	}

	system("pause");
	return 0;
}

bool checaParada(int n, float *X, float *XAnt, float erro){
	float temp[n], tempResult, maior[2] = {0};
	
	// Checa  se |Xn - Xn-1| / |Xn| < Erro
	
	for(int i = 0; i < n; i++){
		temp[i] = X[i] - XAnt[i];
	}
	
	for(int i = 0; i < n; i++){
		
		// Testamos para o maior valor do vetor X e X anterior
		// Por isso obtemos o maior valor de ambos
		
		if(fabs(temp[i]) > maior[0]){
			maior[0] = temp[i];
		}
		
		if(fabs(X[i]) > maior[1]){
			maior[1] = X[i];
		}
		
	}
	
	float Er = fabs(maior[0])/fabs(maior[1]);
	
	// Caso sim, retorna false (quebrando o do-while)
	if( Er < erro){
		return false;
	}
	
	// Caso n�o, o do-while pode continuar
	return true;
	
}



