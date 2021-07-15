#include <stdio.h>
/*
  Refa ̧ca a quest ̃ao 11, considerando que os limites da faixa (A e B) sejam fornecidos pelo usu ́ario. O
  programa deve funcionar tanto para A > B quanto para B > A.
*/
int main(void) {
  int a = 0, b = 0;
  printf("Digite um valor para A: ");
  scanf("%i", &a);
  printf("Digite um valor para B: ");
  scanf("%i", &b);

  if (b > a){
    int n = a;
    while ((a<=n)&&(n<=b)){
      if (n%4==0) 
        printf("%i\n", n);
      n++;
    }
  }else{  
    if (a > b){
    int n = b;
    while ((b<=n)&&(n<=a)){
      if (n%4==0) 
        printf("%i\n", n);
      n++;
      } 
    }
  }
  return 0;
}