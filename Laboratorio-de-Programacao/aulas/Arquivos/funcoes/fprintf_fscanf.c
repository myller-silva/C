#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastro
{
    char nome[31];
    int idade;
    float peso; 
};
void ler_do_arq_p(FILE *, char *, struct cadastro *);

int main(int argc, char *argv[]){
    system("cls");
    puts("");
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
    scanf("%d", &c1.idade);
    printf("Peso: ");
    scanf("%f", &c1.peso);    
    // abrir arquivo:
    p_arq = fopen(argv[1], "w");
    // escrever no arquivo:
    fprintf(p_arq, "%s\n", c1.nome);
    fprintf(p_arq, "%d\n", c1.idade);
    fprintf(p_arq, "%f\n", c1.peso);
    // fechar:
    fclose(p_arq);    
    // ler do arquivo:
    struct cadastro lido;
    ler_do_arq_p(p_arq, argv[1], &lido);
    // exibir:
    puts("\n\nDados Prenchidos:");
    printf("Nome: %s\n", lido.nome);
    printf("Idade: %d\n", lido.idade);
    printf("Peso: %.2fKg\n", lido.peso);
    return 0;
}
void ler_do_arq_p(FILE *p, char *nomearq, struct cadastro *l){    
    p = fopen(nomearq, "r");
    char temp[50];
    char c=0;
    int cont=0;
    for(int k=0; k<3; k++){        
        c=0;   
        cont=0;

        while(1){
            c = getc(p);
            if(c=='\n')break;
            temp[cont++] = c;
        }
        switch(k){
        case 0:
            temp[cont] = 0;
            strcpy(l->nome, temp);
            break;  
        case 1:
            l->idade = atoi(temp);
            break;
        case 2:
            l->peso = atof(temp);
        }
    }
    // while(1){
    //     c = getc(p);
    //     if(c=='\n')break;
    //     temp[cont++] = c;
    // }
    // temp[cont] = 0;
    // strcpy(l->nome, temp);
    // cont=0;
    // while(1){
    //     c = getc(p);
    //     if(c=='\n'){
    //         break;
    //     }
    //     temp[cont++] = c;
    // }
    // l->idade = atoi(temp);
    // cont=0;
    // while(1){
    //     c = getc(p);
    //     if(c=='\n'){
    //         break;
    //     }
    //     temp[cont++] = c;
    // }
    // l->peso = atof(temp);
    fclose(p);
}