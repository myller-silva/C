#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro
{
    char nome[31];
    int idade;
    float peso; 
};


int main(int argc, char *argv[]){
    system("cls");
    puts("\n\n\n");
    if(argc!=2){
        printf("Formato: \n\t %s <NomeArquivo>\n", argv[0]);
        exit(1);
    }
    FILE *p_arq;
    struct cadastro c1;
    // prencher:
    printf("Nome: ");
    scanf("%s", c1.nome);
    printf("Idade: ");
    scanf("%d", c1.idade);
    printf("Peso: ");
    scanf("%f", c1.peso);

    // exibir:
    system("cls");
    puts("\n\nDados Prenchidos:");
    printf("Nome: %s\n", c1.nome);
    printf("Idade: %d\n", c1.idade);
    printf("Peso: %.2f\n", c1.peso);


    // abrir arquivo:
    p_arq = fopen(argv[1], "w");
    // escrever no arquivo:
    fprintf(p_arq, "%s\n", c1.nome);
    fprintf(p_arq, "%d\n", c1.idade);
    fprintf(p_arq, "%f\n", c1.peso);
    // fechar:
    fclose(p_arq);

    return 0;
}