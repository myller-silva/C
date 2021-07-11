#include <stdio.h>
#include <stdlib.h>

void gerar_v(int *v, int tam);

int main(int argc, char *argv[]) {
  if(argc!=3){
    printf("\nFormat:\n\t%s <k> <m>\n", *argv);
    exit(1);
  }
  int k = atoi(argv[1]) , m = atoi(argv[2]);
  int a[k], b[m];  
  int t=0;

  printf("\nVetor A:\n");
  gerar_v(a, k);
  
  printf("\nVetor B:\n");
  gerar_v(b, m);

  for(int c=0; c<k; c++){       //ok
    for(int i=0; i<m; i++){
      if(a[c]==b[i]){
        t++;
      }
    }
  }  
  int temp[t];                  //ok
  int vec_c[k-t];               //ok
  

  for(int c=0; c<k; c++){
    for(int i=0; i<m; i++){
      if(a[c]==b[i]){
        *(temp+c) = a[c];
      }
    }
  } 
  for(int c=0; c<t; c++){
    printf("\n%d == ", temp[c]);
    for(int i=0; i<k; i++){
      printf("%d ", a[i]);
      if(temp[c]==a[i]){
        continue;
      }else{
        
      }
    }
    puts("?");
  }

  printf("\ntemp:\n");
  for(int c=0; c<t; c++){
    printf("[%d]\t:\t%d\n", c, temp[c]);
  }
  // printf("\nvec_c:\n");
  // for(int c=0; c<k-t; c++){
  //   printf("[%d]\t:\t%d\n", c, vec_c[c]);
  // }





  // printf("\nVetor C:\n");
  // for(int c=0; c<k-t; c++){
  //   printf("[%d] = %d\n", c, vec_c[c]);
  // }  
	return 0;
}





void gerar_v(int *v, int tam){
  int c=0;
  for(c=0; c<tam; c++){
    printf("[%d]\t:\t", c);
    scanf("%d", &*(v+c));
  }
}

