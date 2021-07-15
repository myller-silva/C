#include <stdio.h>
void contagem_regressiva(int n);

int main(){
  int x;
  printf("Digite um numero: ");
  scanf("%d", &x);
  contagem_regressiva(x);
  return 0;
}

void contagem_regressiva(int n){
  int c=0;
  for(c=n; c>0; c--){
    printf("%d ", c);
  }
  puts("");
}