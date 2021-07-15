#include <stdio.h>
int main(){
    int n=0;
    printf("Quantos pontos quer verificar?"); //criterio de repeticao
    scanf("%d", &n);

    float x=0, y=0;

    for(int cont=0; cont<n; cont++){          //idá se repetir n vezes
        printf("\nDigite o valor da Abscissa: ");
        scanf("%f", &x);
        printf("\nDigite o valor da Ordenada: ");
        scanf("%f", &y);

        ( ( x>=0 ) && ( y>=0 ) && ((x*x + y*y)<=1) ) ? printf("(%.1f, %.1f) pertence a H.\n", x, y) : printf("(%.1f, %.1f) não pertence a H.\n", x, y);
    }
    return 0;
}   