#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Formato: \n\t%s <NomeArquivo.txt>\n", argv[0]);
        exit(1);
    }

    FILE *a;

    a = fopen(argv[1], "r");
    if(!a){
        puts("Erro ao abrir o arquivo.");
        exit(2);
    }




    return 0;
}