#include <stdio.h>
int fib(int n);

int main(){
  int n;
  printf("\n>>>\tSerie de Fibonacci\t<<<\n");
  printf("Digite um numero: ");
  scanf("%d", &n);
  printf("%dº termo:\t%d\n", n, fib(n));
  return 0;
}

int fib(int n){
  if(n<3){
    return 1;
  }
  int c;
  int n1=1, n2=1;
  int f;
  for(c=2; c<n; c++){
    f = n1 + n2;
    n1 = n2;
    n2 = f;
  }
  return f;
}