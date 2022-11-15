#include <stdio.h>
#include <stdlib.h>

/*
[2,5 pontos] Escreva um programa em C que receba dois vetores de inteiros A e B com dimens ̃oes k e m, 
respectiva- mente. 
Os valores de k e m devem ser fornecidos por linha de comando (argc e argv). 
Crie um vetor C com os elementos de A que n ̃ao pertencem a B. 
Se A e B forem iguais, uma mensagem deve ser exibida.
*/


void gerar_v(int *v, int tam){
  int c=0;
  for(c=0; c<tam; c++){
    printf("[%d]\t:\t", c);
    int val = scanf("%d", &v[c]);
  }
}

void printar_vetor(int *v, int tam){
    for(int c =0; c<tam; c++){
        printf("%d ", v[c]);
    }
    printf("\n");
}

int qtd_de_elementos_iguais(int *vetor_a, int tam_a, int *vetor_b, int tam_b){
    int qtd = 0;
    for(int i = 0; i<tam_a; i++ ){
        for(int j=0; j<tam_b; j++){
            if(vetor_a[i]==vetor_b[j]){
                qtd++;
            }
        }
    }
    return qtd;
}

int* v1_menos_v2(int *v1, int tam_v1, int *v2, int tam_v2){
    int tam_v = tam_v1 - qtd_de_elementos_iguais(v1, tam_v1, v2, tam_v2);
    int *vetor = malloc( sizeof(int)*tam_v );
    int pos=0;
    for(int i=0; i<tam_v1; i++) {
        int equal = 0; 
        for(int j=0; j<tam_v2; j++){
            if(v1[i]==v2[j]){
                equal = 1;
                break;
            }
        }
        if(equal==0){
            *(vetor+pos) = v1[i];
            pos = pos+1;
        }
    }
    return vetor;
}



int main (int argc, char *argv[])
{
    if(argc!=3)
    {
        printf("\nFormat:\n\t%s <k> <m>\n", *argv);
        exit(1);
    }
    int k = atoi(argv[1]) , m = atoi(argv[2]); 
    int vetor_a[k], vetor_b[m];
    
    gerar_v(vetor_a, k);
    gerar_v(vetor_b, m);

    printf("vetor a: ");
    printar_vetor(vetor_a, k);
    printf("vetor b: ");
    printar_vetor(vetor_b, m);

    int tam_c = k - qtd_de_elementos_iguais(vetor_a, k, vetor_b, m);
    int *vetor_c = v1_menos_v2(vetor_a, k, vetor_b, m);

    printf("vetor c: ");
    printar_vetor(vetor_c, tam_c);
    
    return 0;
}
