// Escreva um programa em C que leia dados de diferentes usu ́arios e grave em um arquivo csv.
// Pesquise sobre a organiza ̧c ̃ao de um arquivo csv.
#include <stdio.h>
#include <stdlib.h>
#define MX 30
#define TAM 3

typedef struct csv{
    char nome[MX]; 
    int idade;
    float peso;
}CSV;

void preencher(char *, int *, float *);
void imprimir_na_tela(CSV *);
void imprimir_no_arquivo(CSV *, FILE *, char *);

int main(){
    system("cls");
    char *e[5] = {"primeiro", "segundo", "terceiro", "quarto", "quinto"};
    CSV u[TAM];
    FILE *fp;
    for(int c=0; c<TAM; c++){
        printf("\n%s cadastro:\n", e[c]);
        preencher(u[c].nome, &u[c].idade, &u[c].peso);        
        imprimir_no_arquivo(&u[c], fp, "cvs.txt");
    }
    puts("\n\t\t>>> Dados prenchidos <<<");
    for(int c=0; c<TAM; c++){
        imprimir_na_tela(&u[c]);
    }


    return 0;
}
void preencher(char *nome, int *idade, float *peso){
    printf("Nome: ");
    scanf("%s", nome);
    printf("Idade: ");
    scanf("%d", idade);
    printf("Peso: ");
    scanf("%f", peso);
}
void imprimir_na_tela(CSV *u){
    printf("Nome: %s\t Idade: %d\t Peso: %.2f\n", u->nome, u->idade, u->peso);
}
void imprimir_no_arquivo(CSV *u, FILE *fp, char *nome_arq){
    fp = fopen(nome_arq, "a");
    if(!fp){
        perror("Erro ao abrir arquivo.");
        exit(1);
    }
    fprintf(fp,"Nome: %s\nIdade: %d\nPeso: %.2f\n", u->nome, u->idade, u->peso);
    fclose(fp);
}