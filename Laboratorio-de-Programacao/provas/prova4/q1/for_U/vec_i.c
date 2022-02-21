#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *random_vec_i(int tam , int max, int min){
	srand(time(NULL));
	int *v=malloc(sizeof(int)*tam);
	for(int c=0; c<tam; c++){
		v[c] = rand()%(max-min) + min;
	}
	return v;
}

void show_vec_i(int *v, int tam, char *formatacao){
	for(int c=0; c<tam; c++){
		printf(formatacao, *(v+c));
	}
}

void show_matriz_i(int *matriz, int lin, int col, char *formatacao){
	for(int i=0; i<lin*col; i++){
		if( !(i%col) && (i!=0) ){
			puts("");
		}
		printf(formatacao, matriz[i] );
	}
}

int min_vec_i(int *v, int tam){
	int menor = *v;
	for(int c=1; c<tam; c++){
		if( menor > *(v+c) ){
			menor = *(v+c);
		}
	}
	return menor;
}

int max_vec_i(int *v, int tam){
	int max = *v;
	for(int c=1; c<tam; c++){
		if( max < *(v+c) ){
			max = *(v+c);
		}
	}
	return max;
}

int x_in_vec_i(int *v, int tam, int x){
	for(int c=0; c<tam; c++){
		if(v[c] == x){
			return 1;
		}
	}
	return 0;
}

float media_vec_i(int *v, int tam){
	float me=0;
	for(int c=0; c<tam; c++){
		me += *(v+c);
	}
	me /= tam;
	return me;
}

float mediana_vec_i(int *v, int tam ){
	int *temp=malloc( sizeof(int)*tam );
	for(int c=0; c<tam; c++){
		temp[c] = v[c];
	}
	// ordenar:
	int k, j, aux;
	for(k = tam-1; k>0; k--){
		for (j = 0; j < k; j++) {
			if (*(temp+j) > *(temp+j+1)) {
				aux = *(temp+j);
				*(temp+j) = *(temp+j+1);
				*(temp+j+1) = aux;
			}
		}
	}
	return (tam%2)?temp[tam/2] :  ((float)temp[tam/2] + temp[tam/2 -1])/2.0;
}

// ordenacao por selecao:
int *sort_i(int *v, int tam){

	int *temp = malloc( sizeof(int)*tam );
	int c, j, aux;

	for(int c=0; c<tam; c++){
		temp[c] = v[c];
	}  
	for( c=0; c<tam-1; c++ ){
    for( j=c+1; j<tam; j++ ){
      if( *(temp+j) < *(temp+c) ){
        aux = *(temp+j) ;
        *(temp+j) = *(temp+c) ;
        *(temp+c) = aux ;
      }
    }
  }

	return temp;
}
