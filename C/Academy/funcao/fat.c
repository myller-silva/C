#include <stdio.h>
int fat(int n);

int main(){
  int n=0;
  printf("Digite um numero: ");
  scanf("%d", &n);
  printf("%d! = %d\n", n, fat(n));
  return 0;
}

int fat(int n){
  int f=1;
  int c=0;
  for(c=n; c>1; c--){
    f *= c;
  }
  return f;
}

// Codifique a função fat(n), que devolve o fatorial de n
