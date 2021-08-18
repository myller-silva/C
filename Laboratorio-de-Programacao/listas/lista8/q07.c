/*
Uma uniao é um tipo especial de estrutura capaz de armazenar um unico membro por vez. Ao contrario da estrutura normal, os membros de uma uniao nao ocupam posicoes consecutivas. Na verdade, todos eles sao armazenados a partir do mesmo endereço de memoria  e por esse motivo , apenas um deles pode existir em um dado momento.
*/
#include <stdio.h>
#include <stdlib.h>

typedef union{
  char a;
  int b;
  float c;
}Mutante;

int main(){
  Mutante num;  
  
  system("clear");
  // usando o numero 7 como exemplo:
  num.a = '7';
  printf("\nchar:\t%d\n", num.a); //em ASCII
  num.b = 7;  
  printf("int:\t%d\n", num.b);
  num.c = 7.0;  
  printf("float:\t%f\n", num.c);
  // aqui, todos foram imprimidos corretamente pois a impressao é chamada antes que o valor da uniao seja modificado.
  
  printf("\nchar:\t%d\n", num.a); //em ASCII
  printf("int:\t%d\n", num.b);
  printf("float:\t%f\n", num.c);
  // apenas o ultimo valor foi impresso corretamente, pois num.c foi o ultimo a ser modificado. Todos os outros foram perdidos.


  // quando aloca espaco para uma variavel do tipo uniao, o compilador sempre se baseia no tamanho do seu maior membro. 
  // por exemplo, para "num" deve-se ser alocado 4 bytes, pois o maior membro é float, o qual precisaria de 4 bytes. 
  printf("\ntamanho alocado: %lu\n", sizeof(num));

  // por mais que em um dado momento voce utilize um membro de tamanho menor(como o "char"), o tamanho alocado da uniao sempre será o do maior.
  num.a = '7';
  printf("\ntamanho alocado: %lu\n", sizeof(num));  //continua sendo 4 bytes, por mais que esteja usando char neste momento.

  return 0;
}