#include <stdio.h>
#include <stdlib.h>
#include "vec_f.h"
#include "vec_i.h"

#define LS 99.99998
#define LI 99.99997

int main(int argc, char *argv[]){
	if(argc!=3){
		printf("Formato:\n\t%s <lin> <col>\n", argv[0]);
		exit(1);
	}

	int lin = atoi(argv[1]);
	int col = atoi(argv[2]);
	// float *v = malloc( sizeof(float)*lin*col );
	float v[] = {9.9, 7.5, 8.3, 9.9, 1.3, 9.1, 4.2, 0.3, 9.2};
	float *ord = NULL;

	// v = random_vec_f(lin*col, LS, LI);
	puts("\n");
	show_vec_f(v, lin*col, "%f ");
	puts("");
	// ordenado:
	ord = sort_f(v, lin*col);
	show_vec_f(v, lin*col, "%f ");
	puts("");

	printf("\nmedia: %f\n", media_vec_f(v, lin*col));
	printf("mediana: %f\n", mediana_vec_f(v, lin*col));

	printf("moda: ");
	float *moda = malloc(sizeof(float)*lin*col);
	for(int c=0; c<lin*col; c++){
		moda[c] = v[c];
	}
	show_vec_f(moda, lin*col, "%f ");
	puts("");

	printf("maior: %f\n", max_vec_f(v, lin*col));
	printf("menor: %f\n", min_vec_f(v, lin*col));
	float n;
	printf("Digite um numero para verificar se esta no vetor: ");
	scanf("%f", &n);
	
	if(x_in_vec_f(v, lin*col, n)){
		printf("%f esta em V\n", n);
	}else{
		printf("%f nao esta em V\n", n);
	}

	

	


	return 0;
}
