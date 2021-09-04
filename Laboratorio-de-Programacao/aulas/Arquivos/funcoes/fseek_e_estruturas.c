#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define I 100


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

    struct coord v[TAM];
    FILE *fp;
    
    srand(time(NULL));

    // gerar valores das estruturas:   
    for(int c=0; c<TAM; c++){
        (v+c)->x = rand()%I;
        (v+c)->y = rand()%I;;
    }

    // exibir valores das estruturas:
    puts("\n\n\n>>> coordenadas <<<\n");
    for(int c=0; c<TAM; c++){
        printf("%d: (%d, %d)\n", c, (v+c)->x, (v+c)->y);
    }
    // abrir:
    fp = fopen(argv[1], "w+b");
    if(!fp){
        printf("Erro ao abrir arquivo: %s", argv[1]);
        exit(1);
    }
    // escrever estrutura completa:
    fwrite(&v, sizeof(v), 1, fp);

    int pos;
    P:
    printf("\n\nDigite a coordenada que voce quer ver: ");
    scanf("%d", &pos);
    if( pos>TAM-1 || pos<0 ){
        printf("A coordenada %d eh invalida, tente novamente", pos);
        goto P;
    }

    // reposicionar o ponteiro para leitura:
    fseek(fp, pos*sizeof(struct coord), SEEK_SET);

    struct coord coord_lido;
    // ler:
    fread(&coord_lido, sizeof(coord_lido), 1, fp);
    printf("\n\n%d: (%d, %d)\n\n", pos, coord_lido.x, coord_lido.y);


    return 0;
}