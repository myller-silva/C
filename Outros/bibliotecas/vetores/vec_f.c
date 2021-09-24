#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *random_vec_f(int tam, float LS, float LI){
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

int x_in_vec_f(float *v, int tam, float x){
	for(int c=0; c<tam; c++){
		if(v[c] == x){
			return 1;
		}
	}
	return 0;
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
/* 
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
*/

// BUG:
// vetor de modas:
// beginning
float *moda_vec_f(float *v, int tam, int *qt){
	float *moda = NULL; 
	float *cont = malloc( sizeof(float)*tam );
	int c=0, k=0, i=0;
	
	for(c=0; c<tam; c++){
		for(k=0; k<tam; k++){
			if(v[c]==v[k]){
				cont[c]++;			
			}
		}
	}
	int max = max_vec_f(cont, tam);
	for(c=0; c<tam; c++){
		if(cont[c] == max ){
			i++;				
		}
	}
	moda = malloc( sizeof(float)*i );
	int aux=0;
	for(c=0; c<tam; c++){
		if(cont[c] == max){
			moda[aux++] = v[c];	
		}
	}
	free(cont);
	
	int aux2=0;
	float *moda2 = malloc(sizeof(float));
	for(int c=0; c<aux; c++){
		if(c==0){
			moda2[aux2++] = moda[c];
		}
		if( !x_in_vec_f(moda2, aux2, moda[c]) ){
			moda2 = realloc(moda2, sizeof(float)*(aux2+1));
			moda2[aux2++] = moda[c];
		}
	}
	if(aux2==tam){
		*qt = 0;
		// moda2 = NULL;
		return NULL;
	}
	*qt = aux2;
	return moda2;
}
// finish



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
