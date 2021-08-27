#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#define I 100
typedef struct est{
    int *vetor;
    int qt;
    int maior;
}EST;

void gerar_v_aleatorio(int *, int , int );
void exibir_v(int *, int );
int maior_v(int *, int );


int main(){
    // EST pv;
    EST pv;
    int *v = malloc(sizeof(int)*N);

    system("cls");

    srand(time(NULL));
    gerar_v_aleatorio(v, N, I);
    exibir_v(v, N);

    pv.vetor = v;
    pv.qt = N;
    pv.maior = maior_v(v, N);

    printf("\nquantidade de valores: %d\n", pv.qt);
    printf("maior valor: %d\n", pv.maior);


    return 0;
}

void gerar_v_aleatorio(int *v, int tam, int intervalo){
    int c=0; 
    for(c=0; c<tam; c++){
        *(v+c) = rand()%intervalo;
    }
}

void exibir_v(int *v, int tam){
    int c=0; 
    for(c=0; c<tam; c++){
        printf("v[%d] = %d \n", c, *(v+c) );
    }
}

int maior_v(int *v, int tam){
    int c = 0;
    int maior = *v; 
    for (c=1; c<tam; c++){
        if( *(v+c) > maior ){
            maior = *(v+c);
        }
    }
    return maior;
}












// Escreva um programa em C que organize em uma Estrutura o endere ̧co de um vetor alocado dinami-
// camente, a quantidade de elementos desse vetor e o maior valor presente no vetor. Para obter o maior
// valor, crie uma fun ̧c ̃ao o mais gen ́erica (reutiliz ́avel) poss ́ıvel. Observe que o vetor n ̃ao  ́e um elemento
// da Estrutura.