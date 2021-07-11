#include <stdio.h>
#include <stdlib.h>
void multiplicar(int, int, int*);
void dividir(int, int, int*);
void sub(int , int , int *);
void soma(int , int , int *);

typedef void (*Func) ();

int main(int argc, char *argv[]){
  // verificação
  if (argc!=4){
    printf("\nFormato\n\t%s <num1> <num2> <cod_op>\n", argv[0]);
    exit(1);
  }

  void (*oper)(int, int, int*) = NULL;
  int a, b, op, r;

  a = atoi(argv[1]); 
  b = atoi(argv[2]);
  op = atoi(argv[3]) ;    

  // vetor de ponteiros para funcoes
  Func v[2] = {dividir, multiplicar};  
  oper = (op%2 ==0)? v[0] : v[1];
  // oper = v[op];
  (*oper)(a, b, &r);  
  oper = (op%2) ? v[1] : v[0];
  printf("%d \n", r);
  return 0;

}

void multiplicar(int n1, int n2, int *resp){
  *resp = n1*n2;  
}
void dividir(int n1, int n2, int *resp){
  *resp = n1/n2;  
}
// void sub(int n1, int n2, int *resp){
//   *resp = n1-n2;  
// }
// void soma(int n1, int n2, int *resp){
//   *resp = n1+n2;  
// }
//Escreva um programa que receba x, y e z por linha de comando. Se z for par, execute a multiplicacao de x por y e se z for impar, calcule a divisao de x por y. Use vetor de ponteiros para funções. Use o operador ternário. 