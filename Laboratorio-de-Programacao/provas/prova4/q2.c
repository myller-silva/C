#include <stdio.h>
#include <stdlib.h>
#define TAM 3
struct func{
	int x;
	int y;
};

int main(void) {
	struct func v[TAM];
  	return 0;
}

// Crie uma fun ̧c ̃ao que receba um vetor de Estruturas com dois campos: x (inteiro) e y (inteiro). A fun ̧c ̃ao
// deve salvar o vetor recebido em um arquivo (bin ́ario). Crie a struct. N ̃ao precisa criar a fun ̧c ̃ao
// main().

void gravar_vec_struct(struct func *v, char *nome_arq){
	FILE *p;
	p = fopen(nome_arq, "wb");	
	if(!p){
		printf("Erro ao abrir arquivo %s.\n", nome_arq);
		exit(1);
	}
	fwrite(&v, sizeof(v), 1, p);
	fclose(p);
}