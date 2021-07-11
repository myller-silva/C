#include <stdio.h>
/*
  Uma loja vende seus produtos no sistema entrada mais duas presta ̧c ̃oes, sendo a entrada maior do que
  ou igual `as duas presta ̧c ̃oes; estas devem ser iguais, inteiras e as maiores poss ́ıveis. Por exemplo, se o
  valor da mercadoria for R$ 270,00, a entrada e as duas presta ̧c ̃oes s ̃ao iguais a R$ 90,00; se o valor da
  mercadoria for R$ 302,75, a entrada  ́e de R$ 102,75 e as duas presta ̧c ̃oes s ̃ao iguais a R$ 100,00. Escreva
  um programa que receba o valor da mercadoria e forne ̧ca o valor da entrada e das duas presta ̧c ̃oes, de
  acordo com as regras acima.
*/
int main(void) {
  float tot = 0, entrada = 0;
  unsigned int p1 = 0, p2 = 0;
  printf("Valor do produto: ");
  scanf("%f", &tot);

  for (int cont = 0 ; cont <= (tot/3) ; cont++)
    p1 = p2 = cont;

  entrada = tot - p1 - p2;
  printf("Entrada: R$%.2f \n1ª parcela: R$%i.00\n2ª parcela: R$%i.00\n", entrada, p1, p2);
  
  return 0;
}