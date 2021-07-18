#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define INTERVALO 10
#define N 3

void gerar_mxm(int *, int );
int  exibir_1(int *, int) ;
void contagem_regressiva(int );
void exibir_v(int *, int );
void msg_n2();
void gerar_resposta(int *v, int tam);
void win(int *v1, int*v2, int tam);

int main(){
    int v[N*N] = {0};
    int gab[N*N] = {0};
    int resp[N*N] = {0};

    srand(time(NULL));
    system("cls");
    msg_n2();
    sleep(9);
    printf("O desafio comeca em: ");
    contagem_regressiva(10);

    for(int c=0;c<N*N; c++){
        system("cls");
        msg_n2();
        gerar_mxm(v, N);
        gab[c] = exibir_1(v, N);
    }
    gerar_resposta(resp, N*N);
    system("cls");
    printf("\n\n\n\n\nSua resposta:\t");
    exibir_v(resp, N*N);
    printf("Sabarito:\t");
    exibir_v(gab, N*N);
    win(gab, resp, N*N);
    return 0;
}
void gerar_mxm(int *m, int dim){
    int c=0;
    for(c=0; c<dim*dim; c++){
        m[c] = rand() % INTERVALO;
    }
}
int exibir_1(int *m, int dim){
    int pos;
    pos = rand()%(INTERVALO-1);

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
    printf("\n\n\ntempo: ");
    contagem_regressiva(N-1);
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
    for(int c=t; c>=0; c--){
        printf("%d ", c);
        sleep(1);
    }
    puts("");
}
void msg_n2(){
    printf("\n\nBem vindo ao Nivel 2.\n\n");
    printf("\nNeste nivel, ira aparecer numeros aleatorios em posicoes aleatorias. \n\n");
    printf("\nSeu objetivo eh decorar a sequencia dos NUMEROS exibidos.\n\n");
    printf("\nVoce tera %d segundos para decorar cada valor.\n\n\n", (N-1));
}
void gerar_resposta(int *v, int tam){
    int c=0;
    for(c=0; c<tam; c++){
        system("cls");
        msg_n2();
        printf("sua resposta: ");
        exibir_v(v, c);
        scanf("%d", &v[c]);
    }
}
void win(int *v1, int*v2, int tam){
    int c=0; 
    int p=0;
    for(c=0; c<tam; c++){
        if(v1[c] != v2[c]){
            p=1;
        }
    }
    if(!p){
        printf("\n\n\tParabens!!! Voce venceu!\n\n");
    }else{
        printf("\n\n\tPoxa, cara. Nao foi dessa vez.\n\n");
    }
}