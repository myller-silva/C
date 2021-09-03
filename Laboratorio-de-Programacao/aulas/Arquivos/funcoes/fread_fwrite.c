#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Formato:\n\t%s <NomeArquivo>\n", argv[0]);
        exit(1);
    }
    system("cls");

    FILE *fp;
    double d = 7.45;
    int i = 2;

    fp = fopen(argv[1], "wb");
    if(fp == NULL){
        puts("Erro ao abrir arquivo");
        exit(2);
    }
    fwrite(&d, sizeof(d), 1, fp);
    fwrite(&i, sizeof(i), 1, fp);
    

    
    return 0;
}