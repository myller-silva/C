#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibir_v(int * , int );
void bubble_sort(int *, int);
void media_v(int *, int, float*);
void mediana_v(int *, int , float* );
void moda_v(int *, int , int);


int main(int argc, char *argv[]){
  if (argc<2){
    printf("Formato:\n\t%s <v[1]> <v[2]> ... v[n-1]\n", *(argv+0));
    exit(1);
  }

  float media=0, mediana=0, moda=0;
  int c, *v=NULL, tam = (argc-1) ;
  v = realloc(v, tam*sizeof(int)); //alocação dinamica
  for (c=0; c<tam; c++){
    *(v+c) = atoi(argv[c+1]);
  }
  printf("\nvetor: ");
  exibir_v(v, tam); 

  bubble_sort(v, tam);  
  printf("ordenado: ");
  exibir_v (v,  tam);
  media_v (v, tam, &media);
  mediana_v (v,  tam,  &mediana);
  printf("Media: %f\nMediana: %f\n", media, mediana);  
  //moda_v (v, tam, moda);  OBS
  return 0;
}


void mediana_v(int *v, int tam, float *mediana){
  if (tam%2==0){
    *mediana = ( (float)(v[tam/2])+(float)( v[(tam/2)-1] ))/2  ;
  }else{
    *mediana = (float)(v[tam/2])  ;
  }
}
void media_v(int *v, int tam, float *med){
  int c=0, somatorio=0;
    for(c=0; c<tam; c++){
      somatorio += *(v+c);
    }
  *med = ( ((float)(somatorio)) / tam );  
}
void exibir_v(int *v, int tam){
  int c;
  for (c=0; c<tam; c++){
    printf("%d ", *(v+c));
  }  
  puts("");
}
void bubble_sort(int *v, int tam){
  int k, j, auxiliar;
  for (k = tam - 1; k > 0; k--) {
    for (j = 0; j < k; j++) {
      if (*(v+j) > *(v+j+1)) {
        auxiliar = *(v+j);
        *(v+j) = *(v+j+1);
        *(v+j+1) = auxiliar;
      }
    }
  }
}

void moda_v(int *v, int tam, int moda){
  int c=0, cont=0;
  // quantidade de valores repetidos
  for(c=0; c<tam; c++){
    if ( (c==0)&&(*(v+c) == *(v+c+1)) ){
      cont++;
    }else{
      if ( (*(v+c) == *(v+c+1)) && (*(v+c) != *(v+c-1)) ){
        cont++;
      }
    }    
  }

  int **x = NULL;
  int *y = NULL;
  x = realloc(x, cont*sizeof(int));   
  y = realloc(y, cont*sizeof(int));
  for (c=0; c<tam; c++){
    if( (*(v+c) == *(v+c+1)) && (c=0) ){
      x = &v + c;
    }else{
      if( (*(v+c) == *(v+c+1)) && (*(v+c) != *(v+c-1)) ){  
        x = &v + c;
      }  
    }
  }  
  printf("\ncont: %d\n", cont);
  printf("enderecos de v:\n");
  for(c=0; c<tam; c++){
    printf("[%p] %d\n", v+c, *(v+c) );
  }
  printf("\nenderecos de x:\n");
  for(c=0; c<cont; c++){
    printf("[%p] %d\n", *x+c, **(x+c) );
  }  
}