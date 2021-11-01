#include <stdio.h>
#include <stdlib.h>

int *sort_i(int *v, int tam);
void show_vec_i(int *v, int tam, char *formatacao);

int main(int argc, char *argv[]){

	int B[] = {71, 84, 52, 81, 89, 72, 80, 67, 120, 90, 80, 78, 69, 91, 71, 75, 75, 88, 78, 73,
86, 78, 75, 73, 80, 78, 73, 81, 77, 82};
	int *ord = NULL;

	// ordenado:
	ord = sort_i(B, 30);

	show_vec_i(ord, 30, "%d ");



	return 0;
}


void show_vec_i(int *v, int tam, char *formatacao){
	for(int c=0; c<tam; c++){
		printf(formatacao, *(v+c));
	}
}

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
