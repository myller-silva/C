#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int *, int);
int max(int *, int);
void normalizacao(int *, float *, int);
void exibir_v_int(int *, int);
void exibir_v_float(float *, int); 

int main(int argc, char *argv[]){  
  if(argc==1){
    printf("Formato:\n\t%s <x[0]> <x[1]> ... <x[n-1]>\n", *argv);
    exit(1);
  }
  int c=0, *x = NULL;
  float *x2 = NULL; 

  // alocação dinamica  
  x = realloc(x, (argc-1)*sizeof(int)); //tamanho : (argc-1)
  x2 = realloc(x2, (argc-1)*sizeof(int)); 

  // preencher
  for(c=0; c<(argc-1); c++){
    x[c] = atoi(argv[c+1]);
  }
  normalizacao(x, x2, (argc-1)); 
  
  // exibir  
  printf("\nX : ");
  exibir_v_int(x, (argc-1));
  printf("\nX': ");
  exibir_v_float(x2, (argc-1));
  puts("");

  return 0;
}

void normalizacao(int *v1, float *v2, int tam){
  int c=0;;
  float maior , menor;
  maior = menor = *v1;
  for(c=0; c<tam; c++){
    if(v1[c]<menor){
      menor = v1[c];
    }
    if(v1[c]>maior){
      maior = v1[c];
    }
  }
  for(c=0; c<tam; c++){
    *(v2+c) = (*(v1+c) - menor) / (maior - menor) ;
  }
}
void exibir_v_int(int *v, int tam){
  int c=0;
  for(c=0; c<tam; c++){
    printf("%d ", *(v+c));
  }
}
void exibir_v_float(float *v, int tam){
  int c=0;
  for (c=0; c<tam; c++){
    printf("%.2f ", v[c]);
  }

}
int max(int *v, int tam){
  int c=0, maior = *(v+0);
  for(c=1; c<tam; c++){
    if(maior < v[c]){
      maior = v[c];
    }
  }
  return maior;
}
int min(int *v, int tam){
  int c=0, menor = *v;
  for(c=1; c<tam; c++){
    if(menor > v[c]){
      menor = v[c];
    }
  }
  return menor;
}