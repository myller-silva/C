#include <stdio.h>
#define DIARIA 50.25
/*
  Uma empresa contrata um vendedor a R$ 50,25 por dia. Crie um programa que solicite o ńumero de
  dias trabalhados pelo vendedor e imprima o valor l ́ıquido a ser pago ao mesmo, sabendo que se ele
  trabalhou at ́e 10 dias nao tem direito `a gratifica ̧c ̃ao, se ele trabalhou acima de 10 dias e at́e 20 dias
  tem direito `a gratificacao de 20%, se ele trabalhou acima de 20 dias tem direito `a gratifica ̧c ̃ao de 30%.
  Sempre s ̃ao descontados 10% de imposto de renda em cima do valor bruto.
*/

int main(void) {
  float tot = 0, dias = 0;

  printf("Quantidades de dias trabalhados: ");
  scanf("%f", &dias);
  tot = DIARIA * dias;
  if ((dias > 10) && (dias < 20)){
    tot = tot*120/100;
  }else{
    if (dias >= 20){
      tot = tot*130/100;
    }
  }
  printf("Total sem imposto: R$%.2f\n", tot);
  printf("Total com imposto: R$%.2f\n", tot * 9/10);
  return 0;
}
