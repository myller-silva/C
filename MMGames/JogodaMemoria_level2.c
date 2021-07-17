#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define INTERVALO 10
#define N 3

void gerar_mxm(int *, int );
void exibir_mxm(int *, int );
int  exibir_1(int *, int) ;
void contagem_regressiva(int );
void exibir_v(int *, int );

int main(){
    int v[N*N] = {0};
    int v2[N*2] = {0};

    srand(time(NULL));
    system("cls");
    gerar_mxm(v, N);

    for(int c=0;c<N*2; c++){
        system("cls");
        // exibir_mxm(v, N);    
        // puts("");
        v2[c] = exibir_1(v, N);
    }

    printf("valores: ");
    exibir_v(v2, N*2);
    // for(int c=0; c<N*2; c++){
    //     printf("%d ", v2[c]);
    // }
    return 0;
}

void gerar_mxm(int *m, int dim){
    int c=0;
    for(c=0; c<dim*dim; c++){
        m[c] = rand() % INTERVALO;
    }
}

void exibir_mxm(int *m, int dim){
    int c=0; 
    for(c=0; c<dim*dim; c++){
        if( !(c%dim) ){
            puts("\n");
        }
        printf("%d\t", m[c]);
    }
    puts("");
}

int exibir_1(int *m, int dim){
    int pos;
    pos = rand()%(INTERVALO-1);
    // printf("pos: %d\nm[pos]: %d\n", pos, m[pos]);

    for(int c=0; c<dim*dim; c++){
        if( !(c%dim) ){
            puts("\n");
        }
        if(pos==c){
            printf("%d\t", m[pos]);
        }else{
            printf("_\t");
        }
    }
    contagem_regressiva(2);
    return m[pos];
}
void exibir_v(int *v, int tam){
    int c=0;
    for(int c=0; c<tam; c++){
        printf("%d ", v[c]);
    }
    puts("");
}
void contagem_regressiva(int t){
    printf("\n\n\n\ntempo: ");
    for(int c=t; c>=0; c--){
        printf("%d ", c);
        sleep(1);
    }
    puts("");
}

