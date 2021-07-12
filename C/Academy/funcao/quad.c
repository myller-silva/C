#include <stdio.h>
int quad(int n);

int main(){
  int x;
  printf("Digite um numero: ");
  scanf("%d", &x);
  printf("%d^2 = %d\n", x, quad(x));
  return 0;
}

int quad(int n){
  int q=0;
  int i=1;
  int cont=0;
  for(cont=0; cont<n; cont++){
    q+=i;
    i+=2;
  }
 return q; 
}