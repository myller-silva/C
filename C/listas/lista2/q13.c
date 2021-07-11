#include <stdio.h>
/*
  Elabore um programa que calcule o somat ́orio de todos os n ́umeros pares pertencentes a faixa A,B
  especificada pelo usu ́ario. O programa deve funcionar tanto para A > B quanto para B > A.
*/
int main(void) {
  int  a = 0, b = 0, somapar = 0;
  printf("Digite um numero para A: ");
  scanf("%i", &a);
  printf("Digite um numero para B: ");
  scanf("%i", &b);
  if (a<b){
    for (int cont = a ; cont <= b ; cont++){
      if (cont%2 == 0){
        somapar += cont;
      }
    }
  }else{
    for (int cont = b ; cont <= a ; cont++){
      if (cont%2 == 0){
        somapar += cont;
      }
    }
  }
  /*
    if (a<=b){
      while(a <= b){
        if (a%2 == 0){
          somapar += a;
        }
        a++;
      }
    }else{
      if (a>=b){
        while(a >= b){
          if (b%2 == 0){
            somapar += b;
          }
          b++;        
        }
      }
    }
  */
  printf("Soma dos pares: %i\n", somapar);  
  return 0;
}