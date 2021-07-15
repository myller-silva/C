#include <stdio.h>
#include <stdlib.h>

void gerar_v(int *v, int tam);

int main(int argc, char *argv[]) {
  if(argc!=3){
    printf("\nFormat:\n\t%s <k> <m>", *argv);
    exit(1);
  }
  int k = atoi(argv[1]) , m = atoi(argv[2]);
  int a[k], b[m], i=0;
  int tam=0;

  printf("\nVetor A:\n");
  gerar_v(a, k);
  
  printf("\nVetor B:\n");
  gerar_v(b, m);
  // vetor C:
  for(int c=0; c<k; c++){
    for(int c2=0; c2<k; c2++){
      if (a[c] == b[c2]){
        i++;
      }
    }      
  }
  int vec_c[k-i];  
  for(int c=0; c<k; c++){
    for(int c2=0; c2<m; c2++){ //K? 
      if(a[c]!=b[c2]){
        c2++;
      }else{
        vec_c[c2] = a[c];
      }
    }
  }
  

  printf("\nVetor C:\n");
  for(int c=0; c<k-i; c++){
    printf("[%d] = %d\n", c, vec_c[c]);
  }  
	return 0;
}





void gerar_v(int *v, int tam){
  int c=0;
  for(c=0; c<tam; c++){
    printf("[%d]\t:\t", c);
    scanf("%d", &*(v+c));
  }
}

