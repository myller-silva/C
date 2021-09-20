#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *random_vec_f(int tam, int LS, int LI){
	srand(time(NULL));
	float *v=malloc(sizeof(float)*tam) ;  
  for(int c=0; c<tam; c++){
    *(v+c) = ((float)rand() / (float)RAND_MAX) * (LS-LI) + LI;
  }
	return v;
}

void show_vec_f(float *v, int tam, char *formatacao){
	for(int c=0; c<tam; c++){
		printf(formatacao, *(v+c));
	}
}

void show_matriz_f(float *matriz, int lin, int col, char *formatacao){
	for(int i=0; i<lin*col; i++){
		if( !(i%col) && (i!=0) ){
			puts("");
		}
		printf(formatacao, matriz[i] );
	}
}

float min_vec_f(float *v, int tam){
	float min = *v;
	for(int c=1; c<tam; c++){
		if( min > *(v+c) ){
			min = *(v+c);
		}
	}
	return min;
}

float max_vec_f(float *v, int tam){
	float max = *v;
	for(int c=1; c<tam; c++){
		if( max < *(v+c) ){
			max = *(v+c);
		}
	}
	return max;
}

float media_vec_f(float *v, int tam){
	float me=0;
	for(int c=0; c<tam; c++){
		me += *(v+c);
	}
	me /= tam;
	return me;
}

float mediana_vec_f(float *v, int tam ){
	float *temp=malloc( sizeof(float)*tam );
	for(int c=0; c<tam; c++){
		temp[c] = v[c];
	}
	// ordenar:
	int k, j;
	float aux;
	for(k = tam-1; k>0; k--){
		for (j = 0; j < k; j++) {
			if (*(temp+j) > *(temp+j+1)) {
				aux = *(temp+j);
				*(temp+j) = *(temp+j+1);
				*(temp+j+1) = aux;
			}
		}
	}
	return (tam%2)?temp[tam/2] : (temp[tam/2] + temp[(tam/2)-1]) / 2.0 ;
}

float moda_vec_f(float *v, int tam){
	float *repeticoes = malloc( sizeof(float)*tam );
	int *cont = malloc( sizeof(int)*tam );
	// contar repeticoes:	
	for(int c=0; c<tam; c++){
		for(int k=0; k<tam; k++){
			if(v[c]==v[k]){
				repeticoes[c]++;
			}
		}
	}
	// maior quantidade de repeticoes:
	int e = max_vec_f( repeticoes, tam );
	free(repeticoes);
	// verificar numero que mais se repetiu:
	for(int c=0; c<tam; c++){
		for(int k=0; k<tam; k++){
			if(v[c]==v[k]){
				cont[c]++;
			}
		}
	}
	for(int c=0; c<tam; c++){		
		if(cont[c]==e){
			return v[c];
		}
	}
	
	exit(1);
}
// vetor de modas:




// ordenacao:
float *bubble_sort_f(float *v, int tam){
	float *temp = malloc( sizeof(float)*tam );
	float aux;
	int k, j;

	for(int c=0; c<tam; c++){
		temp[c] = v[c];
	}
	
  for (k = tam - 1; k > 0; k--) {
		for (j = 0; j < k; j++) {
			if (*(temp+j) > *(temp+j+1)) {
				aux = *(temp+j);
				*(temp+j) = *(temp+j+1);
				*(temp+j+1) = aux;
			}
		}
  }
	return temp;
}
float *sort_f(float *v, int tam){
	float *temp = malloc( sizeof(float)*tam );
	float aux;

	int c, j;

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
