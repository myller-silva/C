 // Considerando a defini ̧c ̃ao da estrutura desenvolvida na Quest ̃ao 2 e o arquivo (bin ́ario) com as estruturas
// salvas, crie uma fun ̧c ̃ao que receba um inteiro q, o nome do arquivo e um vetor v com dois inteiros. Sua
// fun ̧c ̃ao deve atualizar os campos (x, y) da Estrutura salva na posi ̧c ̃ao q com os dois valores do vetor,
// respectivamente. N ̃ao precisa criar a fun ̧c ̃ao main().
#include <stdio.h>
#include <stdlib.h>
struct func {
	int x;
	int y;
};
int main(){
	int v[2] = {4, 5};

	return 0;
}
void f(int q, char *nome_arq, int *v){
	struct func atualizado;
	atualizado.x = v[0];
	atualizado.y = v[1];
	FILE *e = fopen(nome_arq, "wb");
	if(!e){
		printf("Erro ao abrir arquivo %s.\n", nome_arq);
		exit(1);
	}
	fseek(e, q*sizeof(struct func), SEEK_SET);
	fwrite(&atualizado, sizeof(struct func), 1, e);
	fclose(e);	
}