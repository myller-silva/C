// Escreva um programa em C que modifique a Quest ̃ao 1 para conter um array com 3 alunos. Escreva
// uma fun ̧c ̃ao para calcular a m ́edia dos alunos.

#include <stdio.h>
#include <stdlib.h>
#define QT 3 //quantidade de alunos
#define QTN 10 //quantidade maxima de caracteres para nomes de alunos

struct aluno{
  char nome[QTN];
  double notas[2];
  float med;  
};

int main(){  
  struct aluno alunos[QT];
  // entrada:  
  for(int c=0; c<QT; c++){
    printf("Nome do aluno: ");
    scanf("%s", alunos[c].nome );
    // ler notas: 
    for (int c2=0; c2<2; c2++){
      printf("nota %d: ", c2+1);
      scanf("%lf", &alunos[c].notas[c2] );
    }
    // media:
    alunos[c].med = (alunos[c].notas[0] + alunos[c].notas[1]) / 2.0 ;
  }
  // saída:
  puts("nome\t\tnota1\tnota2\tmedia");
  for(int c=0; c<QT; c++){
    printf("%s\t\t%.2lf\t%.2lf\t%.2lf\n", alunos[c].nome, alunos[c].notas[0], alunos[c].notas[1], alunos[c].med);
  }
  return 0;
}