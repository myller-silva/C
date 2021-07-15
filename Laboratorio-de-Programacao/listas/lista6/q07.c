#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define TAM 10
void erro_medio_ab(int *, int, float*);
void erro_medio_quadratico(float *, int , float *);
void preencher_v(int *v, int tam, int);

int main(){
  int a[N], b[N], c=0;
  float soma_abA=0, soma_abB=0, soma_eqA = 0, soma_eqB = 0; // somatorios
  float errom_ab_A[N], errom_ab_B[N]; //erro medio absoluto
  float errom_q_A[N], errom_q_B[N]; //erro medio quadrático

  // preencher vetores com valores pseudoaleatorios
  srand(time(NULL)); //semente
  preencher_v(a, N, TAM);
  preencher_v(b, N, TAM);
  
  //erro medio absoluto
  erro_medio_ab(a, N, errom_ab_A);  
  erro_medio_ab(b, N, errom_ab_B);
  // erro medio quadrático
  erro_medio_quadratico( errom_ab_A, N, errom_q_A);
  erro_medio_quadratico(errom_ab_B, N, errom_q_B);

  // exibir vetores
  printf("\nA[%d] : ", N);
  for(c=0; c<N; c++){
    printf("   %d", a[c]);
  }
  printf("\nB[%d] : ", N);
  for(c=0; c<N; c++){
    printf("   %d", b[c]);
  }

  // exibir erro medio absoluto
  puts("\n\nErro medio absoluto(A):");
  for(c=0; c<N; c++){
    printf("%.2f", errom_ab_A[c]);
    soma_abA += errom_ab_A[c]; //somatorio
    (c==(N-1))?printf(" = %.2f", soma_abA) : printf(" + ");
  }
  puts("\nErro medio absoluto(B):");
  for(c=0; c<N; c++){
    printf("%.2f", *(errom_ab_B+c));
    soma_abB += *(errom_ab_B+c); //somatorio    
    (c==(N-1))?printf(" = %.2f", soma_abB) : printf(" + ");
  }
  // exibir erro medio quadrático
  puts("\n\nErro medio quadrático(A): ");
  for(c=0; c<N ;c++){
    printf("%.2f", *(errom_q_A+c));
    soma_eqA += *(errom_q_A+c);
    (c==(N-1))?printf(" = %.2f", soma_eqA) : printf(" + ");
  }
  puts("\nErro medio quadrático(B): ");
  for(c=0; c<N ;c++){
    printf("%.2f", *(errom_q_B+c) );
    soma_eqB += *(errom_q_B+c);
    (c==(N-1))?printf(" = %.2f", soma_eqB) : printf(" + ");
  }
  puts("");

  return 0;
}
void erro_medio_ab(int *v, int tam, float ab[]){
  float media=0;
  int  c=0;
  // media
  for (c=0; c<tam; c++){
    media += *(v+c);
  }
  media/=tam;
  // {erro medio absoluto}
  // prencher vetor do erro medio absoluto
  for(c=0; c<tam; c++){    
    if ( (*(v+c)-media) < 0){
      *(ab+c) = ( media - (float)*(v+c) );
    }else{
      *(ab+c) = ( (float)*(v+c) - media );
    }
  }
}
void erro_medio_quadratico(float *erro_medio_absoluto, int tam, float *v_erro_medio_quadratico){
  int c=0;
  for(c=0; c<tam; c++){
    v_erro_medio_quadratico[c] = erro_medio_absoluto[c]*erro_medio_absoluto[c];
  }  
}
void preencher_v(int *v, int tam, int intervalo){
  int c=0;  
  for(c=0; c<tam; c++){
    *(v+c) = rand()%intervalo;
  }
}