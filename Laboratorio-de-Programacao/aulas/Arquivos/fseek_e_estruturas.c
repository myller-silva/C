#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct coord
{
    int x;
    int y;
};


int main(int argc, char *argv[]){
    system("cls");
    if(argc!=2){
        printf("Formato:\n\t%s <NomeArquivo>\n", argv[0]);
        exit(1);
    }

    int v[TAM];
    FILE *fp;

    // gerar sequencia de fibonacci:    
    for(int c=0; c<TAM-2; c++){
        v[c+2] =v[c] + v[c+1];
    }
    // exibir:
    puts("\n\n>>> Sequencia de fibonacci <<<");
    for(int c=0; c<TAM; c++){
        printf("%d ", v[c]);
    }
    puts("\n");

    // abertura:
    fp = fopen("sequencia_de_fibonacci.txt", "w+b");
    if(!fp){
        puts("Erro ao abrir arquivo.");
        exit(1);
    }
    // escrever:
    fwrite(&v, sizeof(v), 1, fp);

    int pos;
    printf("Digite a posicao do elemento da sequencia que voce quer ver: ");
    scanf("%d", &pos);
    // reposicionar o ponteiro para leitura:
    fseek(fp, pos*sizeof(int), SEEK_SET);
    int valor_lido;
    fread(&valor_lido, sizeof(int), 1, fp);
    printf("O elemento na posicao %d eh o %d\n\n", pos, valor_lido);


    return 0;
}