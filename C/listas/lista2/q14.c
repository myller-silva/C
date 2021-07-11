#include <stdio.h>
/*
Elabore um programa que apresente a quantidade de n ́umeros divis ́ıveis por 3 pertencentes a faixa
A,B especificada pelo usu ́ario. O programa deve funcionar tanto para A > B quanto para B > A.
*/
int main(void) {
  int  a = 0, b = 0, tot = 0;
  printf("Digite um numero para A: ");
  scanf("%i", &a);
  printf("Digite um numero para B: ");
  scanf("%i", &b);
  if (a<b){
    for (int cont = a ; cont <= b ; cont++){
      if (cont%3 == 0){
        tot += 1;
      }
    }
  }else{
    for (int cont = b ; cont <= a ; cont++){
      if (cont%3 == 0){
        tot += 1;
      }
    }
  }
  printf("Total de divisiveis por 3: %i\n", tot);  
  return 0;
}