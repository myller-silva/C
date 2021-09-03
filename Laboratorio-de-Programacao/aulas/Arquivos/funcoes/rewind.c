#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 80

int main(int argc, char *argv[]){
    FILE *fp;
    char str[TAM]={};

    // validacao:
    if(argc!=2){
        printf("Formato:\n\t %s <nomeArquivo>", argv[0]);
        exit(1);
    }

    system("cls"); 
    // abrir arquivo:
    if(   (fp=fopen(argv[1], "w+")) == NULL   ){
        puts("Erro: o arquivo nao pode ser aberto.");
    } 
    // escrever dados no arquivo:
    do{
        puts("Digite uma string: ");
        fgets(str, 79, stdin);
        fputs(str, fp);
    }while(*str!='\n');
    // reposicionar o indicador de arquivo:
    rewind(fp);
    // leitura de dados do arquivo:
    puts(">>> Dados do Arquivo <<<");
    while( !feof(fp) ){
        fgets(str, 79, fp);
        printf("%s", str);
    }
    // fechar arquivo:
    fclose(fp);

    return 0;
}