#include <stdio.h>
#include <stdlib.h>

void exibir_v(int *v, int tam_v);
void gerar_v(int *v, int tam_v);
void *p_v_menos_y(int *v, int *y, int tam_v, int tam_y, int *tam_z );

int main(int argc, char *argv[]){
  if(argc!=3){
    printf("Formato:\n\t%s <k> <m>\n", argv[0]);
    exit(1);
  }
  int *a=NULL, *b=NULL, *c=NULL ;  
  int k=0, m=0, tam_c=0 ;

  k = atoi(argv[1]);
  m = atoi(argv[2]);
  a = realloc(a, k*sizeof(int));
  b = realloc(b, m*sizeof(int));

  printf("\nDigite os valores de A:\n"); 
  gerar_v(a, k);
  printf("\nDigite os valores de B:\n"); 
  gerar_v(b, m);
  c = p_v_menos_y(a, b, k, m, &tam_c);

  printf("\nA:\t"); 
  exibir_v(a, k);
  printf("\nB:\t");
  exibir_v(b, m);  
  printf("\nC:\t");
  (c!=NULL) ? exibir_v(c, tam_c) : printf("A = B\n");
  
  
  return 0;
}
void exibir_v(int *v, int tam_v){
  int c=0; 
  for(c=0; c<tam_v; c++){
    printf("%d\t", v[c]);
  }
  puts("");
}
void gerar_v(int *v, int tam_v){
  int c=0; 
  for(c=0; c<tam_v; c++){
    printf("[%d]\t:\t", c);
    scanf("%d", &v[c]);
  }
}

// retornar ponteiro
void *p_v_menos_y(int *v, int *y, int tam_v, int tam_y, int *tam_z ){
  int c=0; 
  int i=0;
  int t=0;
  int *v_t = NULL;

  v_t = realloc(v_t, tam_v*sizeof(int));

  for(c=0; c<tam_v; c++){
    int e=0;
    for(i=0; i<tam_y; i++){
      if(v[c]==y[i]){
        e=1;
      }
    }    
    if(e==0){
      v_t[t] = v[c];
      t++;
    }
  }

  *tam_z = t;
  return v_t;
}
