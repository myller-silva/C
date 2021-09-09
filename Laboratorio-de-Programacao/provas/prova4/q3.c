// Quest ̃ao 3: [21/2 pontos]
// Crie uma fun ̧c ̃ao que receba o nome do arquivo salvo na quest ̃ao anterior e um inteiro q. A fun ̧c ̃ao deve
// ler o arquivo e retornar a estrutura salva localizada na posi ̧c ̃ao q do vetor. N ̃ao precisa criar a fun ̧c ̃ao
// main().
#include <stdio.h>
#include <stdlib.h>
struct func{
	int x;
	int y;
};

int main(){

	return 0;
}

struct func pos_vec_struct(char *nome_arq, int p){
	struct func s;
	FILE *e = fopen(nome_arq, "rb");
	if(!e){
		printf("Erro ao abrir arquivo %s.\n", nome_arq);
		exit(1);
	}
	fseek(e, p*sizeof(struct func), SEEK_SET);
	fread(&s, sizeof(struct func), 1, e);
	fclose(e);
	return s;
} 