#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define INTERVALO 10

void exibir_mxm(int *v, int dim);
void gerar_mxm(int *v, int dim);
void contagem_regressiva(int n);
void resposta(int *v, int dim);
int pontos(int *v1, int *v2, int dim);

int main(int argc, char *argv[]){    
    system("cls");
    if(argc!=2){
        printf("Formato:\n\t%s <dim>", argv[0]);
	    exit(1);
    }

    srand(time(NULL)); //semente

    int *v1=NULL, *v2=NULL;
    int n = atoi( argv[1] );
    int pontuacao = 0;

    v1 = realloc(v1, n*n*sizeof(int));
    v2 = realloc(v2, n*n*sizeof(int));

    gerar_mxm(v1, n);
    exibir_mxm(v1, n);    
    printf("\nDecore a sequencia!\n");
    contagem_regressiva(10);
    system("cls");

    printf("Sua resposta: ");
    resposta(v2, n);

    exibir_mxm(v1, n);
    exibir_mxm(v2, n);   
    pontuacao = pontos(v1, v2, n); 

    if(pontuacao==n*n){
        printf("\nPARABENS!!! Voce venceu!\n");
    }else{
        printf("\nVoce acertou: %d\n", pontuacao);
        printf("Poxa, cara. Nao foi dessa vez, continue tentando. Valeu!\n");
    }
    return 0;
}

void gerar_mxm(int *v, int dim){
    int c=0;
    for(c=0; c<dim*dim; c++){
        v[c] = rand()%INTERVALO;
    }
}

void exibir_mxm(int *v, int dim){    
    int c=0;
    for(c=0; c<dim*dim; c++){
        if(c%dim==0){
            puts("\n");
        }
        printf("%5d", v[c]);
    }
    puts("");
}

void contagem_regressiva(int n){
    int c=0;
    for(c=n; c>0; c--){
        printf("%d... ", c);
        sleep(1);
    }
    puts("");
}

void resposta(int *v, int dim){
    int c=0;
    for(c=0; c<dim*dim; c++){
        scanf("%d", &v[c]);
        system("cls");
        printf("Sua resposta: ");
        for(int i=0; i<=c; i++){
            printf("%d ", v[i]);
        }
    }    
}

int pontos(int *v1, int *v2, int dim){
    int c=0, p=0;
    for( c=0; c<dim*dim; c++ ){
        if( v1[c] == v2[c] ){
            p++;
        }
    }
    return p;
}
