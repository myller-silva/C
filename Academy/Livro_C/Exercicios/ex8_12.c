#include <stdio.h>
#include <stdlib.h>
typedef struct cadastro
{
    char nome[31];
    float salario;
}CAD;


int main(int argc, char *argv[]){
    if(argc!=2){
        printf("formato: \n\t%s <NomeArquivo>", argv[0]);
        exit(1);
    }

    CAD c1;
    FILE *a;
    a = fopen(argv[1], "w+b");
    if(a==NULL){
        printf("Erro ao abrir o arquivo: %s\n", argv[1]);
        exit(2);
    }
    system("cls");

    puts("\n\n\n\n>>> Digite um ponto final para finalizar cadastro <<<\n");
    int cont =0;
    while (1){
        printf("Nome: ");
        scanf("%s", c1.nome);

        if( c1.nome[0] == 46 ) break;

        printf("Salario: ");
        scanf("%f", &c1.salario);
        fwrite(&c1, sizeof(c1), 1, a); 
        cont++;            
    }
    puts("_>_>_> Cadastro finalizado <_<_<_\n\n");
    
    rewind(a);

    CAD lido;
    puts("\n\n>>> LEITURA <<<");
    for(int c=0; c<cont; c++){
        fread(&lido, sizeof(lido), 1, a);
        printf("nome: %s\nsalario: R$%.2f\n\n", lido.nome, lido.salario);
    }

    int e;
    printf("\n\nDeseja verificar qual cad astro: ");
    scanf("%d", &e);
    
    fseek(a, e*sizeof(CAD), SEEK_SET);
    CAD seg;
    fread(&seg, sizeof(seg), 1, a);
    printf("\n\n>>> Cadastro numero %d<<<\n", e);
    printf("nome: %s\nsalario: R$%.2f\n\n", seg.nome, seg.salario);
    

    

    
    

    return 0;    
}