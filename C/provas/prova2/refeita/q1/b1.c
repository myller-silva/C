#include <stdio.h>
#include <stdlib.h>

void gerar_v(int *v, int tam);
void gerar_c(int a[], int b[],int c[], int tam_a, int tam_b, int *tam_c);
void exibir_v(int *v, int tam);


int main(int argc, char *argv[]) {
  if(argc!=3){
    printf("\nFormat:\n\t%s <k> <m>\n", *argv);
    exit(1);
  }
  int k = atoi(argv[1]) , m = atoi(argv[2]);
  int a[k], b[m];  
  int *c, t_c=0;

  printf("\nVetor A:\n");
  gerar_v(a, k);  
  printf("\nVetor B:\n");
  gerar_v(b, m);
  
  printf("\nVetor A:");
  exibir_v(a, k);
  printf("\nVetor B:");
  exibir_v(b, m);
  printf("\nVetor C:");
  gerar_c(a, b, c, k, m, &t_c);
  // exibir_v(c, t_c);
  
	return 0;
}

void gerar_v(int *v, int tam){
  int c=0;
  for(c=0; c<tam; c++){
    printf("[%d]\t:\t", c);
    scanf("%d", &*(v+c));
  }
}

void exibir_v(int v[], int tam){
  int c=0;
  for(c=0; c<tam; c++){
    printf("\t%d", v[c]);
  }
  puts("");
}

void gerar_c(int a[], int b[], int c[],int tam_a, int tam_b, int *tam_c ){
  int k=0, j=0;
  int e=0;
  int temp[tam_a];
  for(  k=0; k<tam_a; k++   ){
    for(  j=0; j < tam_b; j++   ){
      if (  a[k]==b[j]  ){
        temp[e] = a[k];
        e++;
      }
    }
  }  
  // ok
  //
  for(k=0; k<tam_a; k++){
    c[k] = a[k];
  } 
  for(  k=0; k<tam_a; k++   ){
    for(  j=0; j < tam_b; j++   ){
      if (  c[k]==temp[j]  ){
        c[k] = 0;
      }
    }
  }  
  for(k=0; k<e; k++){
    printf("\t%d", temp[k]);
  }
  puts("");
  for(k=0; k<tam_a-e; k++){
    printf("\t%d", c[k]);
  }
  puts("");
  
  *tam_c = (tam_a-e);
}