#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define I 100

typedef struct par_xy{
    float x;
    float y;
} XY;
void gerar_xy_float(XY *, int );
void exibirsoma(XY *, int);

int main(){
    XY v[N]={};
    srand(time(NULL));
    system("cls");
    
    gerar_xy_float(v, N);
    exibirsoma(v, N); 
    
    return 0;
}

void gerar_xy_float(XY *v, int tam){
    int c=0;
    for(c=0; c<tam; c++){
        (v+c)->x = ( (float) rand() / (float) RAND_MAX ) * I;
        (v+c)->y = ( (float) rand() / (float) RAND_MAX ) * I;        
    }
}
void exibirsoma(XY *v, int tam){
    int c=0;
    for(c=0; c<tam; c++){
        printf("%2d : (x: %2.2f, y: %2.2f) ______ x+y: %2.2f\n", c+1, (v+c)->x, (v+c)->y, ((v+c)->x + (v+c)->y) );
    }
}
