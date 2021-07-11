#include <stdio.h>
#include <stdlib.h>

void exibir_v(int v[], int tam_v);
void gerar_v(int v[], int tam_v);
// void gerar_c(int v[], int y[],int z[], int tam_v, int tam_y, int *tam_z);
void v_menos_y(int v[], int y[], int tam_v, int tam_y);
int main(int argc, char *argv[]){
  if(argc!=3){
    printf("Formato:\n\t%s <k> <m>", argv[0]);
    exit(1);
  }
  int k=0, m=0, j=0;
  k = atoi(argv[1]);
  m = atoi(argv[2]);
  int *a=NULL, *b=NULL, *c=NULL;
  a = realloc(a, k*sizeof(int));
  b = realloc(b, m*sizeof(int));

  printf("\nDigite os valores de A:\n"); 
  gerar_v(a, k);  
  printf("\nDigite os valores de B:\n"); 
  gerar_v(b, m);
  // ok

  v_menos_y(a, b, k, m);

 
  printf("\nA:\t"); 
  exibir_v(a, k);
  printf("\nB:\t");
  exibir_v(b, m);
  
  return 0;
}

void exibir_v(int v[], int tam_v){
  int c=0; 
  for(c=0; c<tam_v; c++){
    printf("%d\t", v[c]);
  }
  puts("");
}
void gerar_v(int v[], int tam_v){
  int c=0; 
  for(c=0; c<tam_v; c++){
    printf("[%d]\t:\t", c);
    scanf("%d", &v[c]);
  }
}




void v_menos_y(int v[], int y[], int tam_v, int tam_y){
  int c=0; 
  int i=0;
  int t=0;
  int *temp = NULL;
  temp = realloc(temp, tam_v*sizeof(int));
  puts("");
  for(c=0; c<tam_v; c++){
    int e=0;
    printf("A[%d]\t:\t%d\tin", c, v[c]);
    for(i=0; i<tam_y; i++){
      printf("\t%d", y[i]);
      if(v[c]==y[i]){
        e=1;
      }
    }    
    puts(" ?");
    if(e==0){
      temp[t] = v[c];
      t++;
    }
  }
  printf("C = A-B = ");
  exibir_v(temp, t);
}
