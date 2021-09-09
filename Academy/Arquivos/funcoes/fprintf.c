#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char nome[50];
	int idade;

	if (!(fp = fopen("fprintf.txt","w"))){
		perror(NULL);
		exit(1);
	}

	puts("Digite seu nome: ");
	fscanf(stdin, "%s", nome);
	getchar();
	puts("Digite sua idade: ");
	fscanf(stdin, "%d", &idade);

	// Escrever no arquivo
	fprintf(fp, "A idade de %s é %d\n",nome,idade);


	fclose(fp);
	return 0;


}