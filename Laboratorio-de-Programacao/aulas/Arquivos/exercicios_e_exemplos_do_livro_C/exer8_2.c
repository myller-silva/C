// transformar para minusculo ou maiusculo
/* Implemente um programa para ler um texto da entrada padrao, converte-lo em maiusculas ou minusculas e exibi-lo na saida padrao. O tipo de conversao dever ser especificado atraves de uma chave(+ para maiuscula ou - para minuscula), passada como argumewnto por linha de comandos. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MX 100

void for_m_or_M(char *, char );

int main(int argc, char *argv[]) {
	if(argc!=3){
		printf("Formato: \n\t%s <palavra> <+ ou ->\n", argv[0]);
		exit(1);
	}
	FILE *a;
	char palavra[MX] ;
    char esc = *argv[2];
	strcpy(palavra , argv[1]);

	a=fopen("palavra.txt", "w+b");
	// escrever:
	// 		1ª forma:
    // for(int c=0; c<strlen(palavra); c++){
    //     fwrite(&palavra[c], sizeof(char), 1, a);
    // }
	// char t='\n';
	// fwrite(&t, sizeof(char), 1, a);
	// 		2ª forma:
	fprintf(a, "%s\n", palavra);
	// 		3ª forma:
	// fputs(palavra, a);

    for_m_or_M(palavra, esc);
	fputs(palavra, a);
	printf("\n\n%s\n\n", palavra);

	fclose(a);
	return 0;
}


void for_m_or_M(char *p, char c){
	if(c=='+'){
		for(int k=0; k<strlen(p); k++){
			if(p[k]>=97 && p[k]<=122) p[k] -= 32;
		}
	}else if(c=='-'){
		for(int k=0; k<strlen(p); k++){
			if(p[k]>=65 && p[k]<=90) p[k] += 32;
		}
	}else{
		puts("Caractere invalido");
		exit(2);
	}
}