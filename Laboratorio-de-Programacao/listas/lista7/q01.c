// Escreva um programa em C que utilize uma Estrutura aluno para conter duas notas, lidas do
// usu ́ario, e sua m ́edia.

#include <stdio.h>
#include <stdlib.h>
#define QTN 10

struct aluno{
  char nome[QTN];
  double notas[2];
  float med;  
};

int main(){  
  struct aluno fulano;
  // entrada  
  printf("Nome do aluno: ");
  scanf("%s", fulano.nome );
  // ler notas: 
  for (int c=0; c<2; c++){
    printf("nota %d: ", c+1);
    scanf("%lf", &fulano.notas[c] );
  }
  // media:
  fulano.med = (fulano.notas[0] + fulano.notas[1]) / 2.0 ;
  
  // saída
  puts("\nnome / nota1 / nota2 / media\n");
  printf("%s\t\t\t%.2lf\t%.2lf\t%.2lf\n", fulano.nome, fulano.notas[0], fulano.notas[1], fulano.med);
  
  return 0;
}