#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define I 100

typedef struct est{
    int x;
    int y;
} EST;

EST * enderecomenordistancia(EST *, int);


int main(){
    EST *vetor=malloc(sizeof(EST)*N);
    EST *end_menor_dist=NULL;
    
    srand(time(NULL));
    // gerar pseudo-aleatorios:
    for(int c=0; c<N; c++){
        (vetor + c)->x = rand()%I;
        (vetor + c)->y = rand()%I;        
    }   
    // exibir: 
    puts("\n");
    for(int c=0; c<N; c++){
        printf("[%p] _____ x: %d, y: %d\n", (vetor+c), (vetor+c)->x, (vetor+c)->y); 
    }

    end_menor_dist = enderecomenordistancia(vetor, N);
    printf("end menor: %p\n", end_menor_dist );    

    return 0;
}

EST * enderecomenordistancia(EST *vetor, int tam){
    int c=0;
    int menor_dist = (vetor->x - vetor->y);
    EST *temp;

    if (menor_dist<0){
        menor_dist *= -1;
        temp = vetor;
    }

    for(c=1; c<tam; c++){
        int dist_atual = (vetor+c)->x - (vetor+c)->y;

        if(dist_atual<0){
            dist_atual *= -1;
        }

        if(dist_atual < menor_dist){
            menor_dist = dist_atual;
            temp = vetor + c;
        }
    }   
    return temp;
}