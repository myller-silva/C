#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct est{
  int qt_elementos;
  int p;
} EST;

int main(int argc, char *argv[]) {
  
  return 0;
}

int indice_do_maior(EST *x, EST *y, int tam){
  int i_maior = 0;
  int maior = x[0].p - y[0].p;

  if(maior < 0){
    maior *= (-1);
  }
  
  for(int i=1; i<tam; i++){
    int valor_atual = x[i].p - y[i].p;    
    if(valor_atual < 0){
      valor_atual *= (-1);
    }
    if(maior<valor_atual){
      maior = valor_atual;
      i_maior = i;
    }  
  }
  return i_maior;
}

