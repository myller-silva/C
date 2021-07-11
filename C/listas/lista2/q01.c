#include <stdio.h>
#include <stdlib.h>
/* 1)
  Implemente um programa que tenha como entrada um n ́umero (1-7) que corresponde a um dos dias
  da semana e imprima na tela o nome do dia correspondente (domingo, segunda, ter ̧ca, quarta, quinta,
  sexta, śabado). Se o n ́umero lido n ̃ao estiver no intervalo 1-7, imprima: “N ́umero de dia n ̃ao v ́alido”. O
  programa deve permanecer executando at ́e que o usuario tecle o numero 0. (Utilize obrigatoriamente
  teste no inıcio).
*/
int main() {
  int n = 0;
  char dom[] = "domingo", seg[] = "segunda", ter[] = "terça", qua[] = "quarta", qui[] = "quinta", sex[] = "sexta", sab[] = "sabado", inv[] = "invalido";
  while (1){
    printf ("\nDigite um numero: \n");
    scanf("%i", &n);
    if (n == 0){
      printf("\nFim do programa.\n");
      break;
    }else{
    printf("Voce digitou %i que corresponde a: %s", n, (n == 1 ) ? dom : (n == 2 ) ? seg :(n == 3 ) ? ter :(n == 4 ) ? qua :(n == 5 ) ? qui :(n == 6 ) ? sex :(n == 7 ) ? sab : inv);}
  }
  
  //char dia[7];
/*
 printf("Digite um numero: ");
 scanf("%i", &n);
  if ((n <=7) && ( n >= 1 )){
    dia[] = (n == 1) ? "domingo" : 
            (n == 2) ? "segunda" : 
            (n == 3) ? "terça"   : 
            (n == 4) ? "quarta"  : 
            (n == 5) ? "quinta"  : 
            (n == 6) ? "sexta"   : 
            (n == 7) ? "sabado"  : "invalido";
  }
*/
  return 0;
}