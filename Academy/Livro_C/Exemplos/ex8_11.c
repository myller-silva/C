// exibindo o conteudo de um arquivo em video
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

void main(int argc, char *argv[]){
    if(argc!=2){
        printf("Formato:\n\t%s <NomeArquivo>\n", argv[0]);
        exit(1);
    }
    FILE *e;
    char nome[TAM];
    int c;
    strcpy(nome, argv[1]);
    // abrir:
    e = fopen(nome, "r");
    if(!e){
        perror("Erro ao abrir arquivo");
        exit(2);
    }
    // ler:
    while(!feof(e)){
        c = fgetc(e);
        putc(c, stdout);
    }
    fclose(e);
}
