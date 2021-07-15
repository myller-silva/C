#include <stdio.h>
/*
  Desenvolva um programa que calcule o salario liquido de um professor. Para elaborar o programa,  ́e
  necessario possuir alguns dados, tais como o valor da hora aula, 
  n ́umero de horas trabalhadas no mˆes e
  percentual de desconto do INSS. Em primeiro lugar, deve-se estabelecer o seu sal ario bruto para fazer
  o desconto e ter o valor do salario liquido. Obs.: o programa deve informar o salario bruto e salario
  liquido do professor.
*/
int main(void) {
  int h_mes = 0  ;
  float valor_hora = 0, sal_bruto = 0, sal_liquido = 0;
  printf("Valor da hora: R$");
  scanf("%f", &valor_hora);
  printf("Horas trabalhadas no mês: ");
  scanf("%i", &h_mes);
  sal_bruto = (h_mes * valor_hora);  
  /*
    if (sal_bruto <= 1100){
      sal_liquido = sal_bruto - sal_bruto * 7.5/100;
    }else{
      if((sal_bruto > 1100)&&(sal_bruto <= 2203.48)){
        sal_liquido = sal_bruto - sal_bruto * 9/100;
      }else{
        if((sal_bruto > 2203.48)&&(sal_bruto <= 3305.22)){
          sal_liquido = sal_bruto - sal_bruto * 12/100;
        }else{
          if((sal_bruto > 3305.22)&&(sal_bruto < 6433.57)){
            sal_liquido = sal_bruto - sal_bruto * 14/100;
          }  
        }
      }
    }
  */
  sal_liquido = (sal_bruto <= 1100) ? (sal_bruto - sal_bruto * 7.5/100) :
    ((sal_bruto > 1100)&&(sal_bruto <= 2203.48))    ? (sal_bruto - sal_bruto * 9/100) :
    ((sal_bruto > 2203.48)&&(sal_bruto <= 3305.22)) ? (sal_bruto - sal_bruto * 12/100) :
    ((sal_bruto > 3305.22)&&(sal_bruto < 6433.57))  ? (sal_bruto - sal_bruto * 14/100) : -1;

  (sal_liquido == -1) ? printf("ERRO\n") : printf("Salario bruto: R$%.2f\nSalario liquido: R$ %.2f\n", sal_bruto, sal_liquido);
  return 0;
}