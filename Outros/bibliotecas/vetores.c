#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *gerar_v(int tam , int intervalo){
	srand(time(NULL));
	int *v=malloc(sizeof(int)*tam);
	for(int c=0; c<tam; c++){
		v[c] = rand()%intervalo;
	}
	return v;
}

void exibir_vetor(int *v, int tam){
	for(int c=0; c<tam; c++){
		printf("%2.2d ", *(v+c));
	}
}

void exibir_matriz(int *matriz, int lin, int col, char *formatacao){
	for(int i=0; i<lin*col; i++){
		if( !(i%col) && (i!=0) ){
			puts("");
		}
		printf(formatacao, matriz[i] );
	}
}

int min_vec(int *v, int tam){
	int menor = *v;
	for(int c=1; c<tam; c++){
		if( menor > *(v+c) ){
			menor = *(v+c);
		}
	}
	return menor;
}

int max_vec(int *v, int tam){
	int maior = *v;
	for(int c=1; c<tam; c++){
		if( maior < *(v+c) ){
			maior = *(v+c);
		}
	}
	return maior;
}
