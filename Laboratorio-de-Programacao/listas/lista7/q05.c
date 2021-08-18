// Crie uma Estrutura disciplina em que um dos campos corresponde tambem a uma estrutura professor.
#include <stdio.h>
#include <stdlib.h>

struct professor
  {
    char nome[20];
  };
struct disciplina
{
  char nome[20];
  struct professor prof;
};

int main(){
  return 0;
}