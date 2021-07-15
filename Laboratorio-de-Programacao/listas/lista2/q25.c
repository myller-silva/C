#include <stdio.h>
#define LIMITE 1000
/*
    Calcule o valor de π a partir da s ́erie infinita
    π = 4 −
    4
    3
    +
    4
    5
    −
    4
    7
    +
    4
    9
    −
    4
    11
    + ... (1)
    Imprima uma tabela que mostre o valor de π aproximado por um termo dessa s ́erie, e depois por dois
    termos, trˆes termos, e assim por diante.
*/
int main(void) {
  double pi = 0 ;
  long int rodada = 1;
  for (float denominador = 1 ; denominador <= LIMITE ; denominador+=2){
    if (rodada%2==0){
      pi -= 4/denominador;
    }else{
      pi += 4/denominador;      
    }
    printf("\npi = %.5lf : denominador = %.0f : rodada: %li", pi, denominador, rodada);
    rodada++;
  }
  return 0;
}