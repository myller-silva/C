#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char cp='a';

    
    if(argc!=2){
        printf("Formato:\n\t %s <nomeArquivo>", argv[0]);
        exit(1);
    }

    system("cls");

    // fp = fopen(argv[1], "w"); //abrir para escrita
    // if(fp==NULL){
    //     puts("Erro: o arquivo nao pode ser aberto.");
    //     exit(2);
    // }
    if(   (fp=fopen(argv[1], "w")) == NULL   ){
        puts("Erro: o arquivo nao pode ser aberto.");
    } 

    do{
        cp = getchar();
        getchar();
        putc(cp, fp);
    }while(cp!='$');
    
    fclose(fp);

    return 0;
}