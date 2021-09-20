#include <stdio.h>
#include <stdlib.h>
#include "vec_i.h"
#define LS 100
#define LI 50

int *moda(int *v, int tam, int *qt);
int verificar_valor(int *v, int tam, int valor);

int main(int argc, char *argv[]){
	if(argc!=3){
		printf("Formato:\n\t%s <lin> <col>\n", argv[0]);
		exit(1);
	}

	int lin = atoi(argv[1]);
	int col = atoi(argv[2]);
	int *v = malloc( sizeof(int)*lin*col );

	v = random_vec_i(lin*col, LS,LI);
	show_vec_i(v, lin*col, "%d ");
	puts("");
	v = sort_i(v, lin*col);
	show_vec_i(v, lin*col, "%d ");
	puts("");

	int qt;
	int *m = moda(v, lin*col, &qt);
	show_vec_i(m, qt, "%d ");
	puts("");


	return 0;
}


int *moda(int *v, int tam, int *qt){
	int *moda = NULL; 
	int *cont = malloc( sizeof(int)*tam );
	int c=0, k=0, i=0;
	for(c=0; c<tam; c++){
		for(k=0; k<tam; k++){
			if(v[c]==v[k]){
				cont[c]++;			
			}
		}
	}
	int max = max_vec_i(cont, tam);
	for(c=0; c<tam; c++){
		if(cont[c] == max ){
			i++;				
		}
	}
	moda = malloc( sizeof(int)*i );
	int aux=0;
	for(c=0; c<tam; c++){
		if(cont[c] == max){
			moda[aux++] = v[c];	
		}
	}
	
	int aux2=0;
	int *moda2 = malloc(sizeof(int));
	for(int c=0; c<aux; c++){
		if(c==0){
			moda2[aux2++] = moda[c];
		}
		if( !verificar_valor(moda2, aux2, moda[c]) ){
			moda2 = realloc(moda2, sizeof(int)*(aux2+1));
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



int verificar_valor(int *v, int tam, int valor){
	for(int c=0; c<tam; c++){
		if(v[c] == valor){
			return 1;
		}
	}
	return 0;
}