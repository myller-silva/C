#include <stdio.h>
int pot(int x, int n);

int main(){
  int x, n;
  printf("Digite dois numeros:\n");
  scanf("%d%d", &x, &n);
  printf("%d^%d = %d\n", x, n, pot(x, n));
  return 0;
}

int pot(int x, int n){
  int p=1;
  int c=0;
  for (c=n; c>0; c--){
    p *= x;
  }
  return p;
}