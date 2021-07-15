#include <stdio.h>
#include <stdlib.h>

void soma(int a, int b, int *r);
void sub(int a, int b, int *r);
void mult(int a, int b, int *r);
void divi(int a, int b, int *r);

typedef void (*Func)();

int main(int argc, char *argv[]){
  if (argc!=4){
    printf("\nFormato:\n\t%s <num1> <num2> <op>\n",*argv /* ou >argv[0]< */);
    exit(1);
  }
  int n1 = atoi(argv[1]) ;
  int n2 = atoi(argv[2]) ;
  int op = atoi(argv[3]) ;
  int r = 0 ;

  // vetor de ponteiros de funcoes:
  Func v[4] = {soma, sub, mult, divi}; // Func definida na linha 9
  // ou:
  // void *x[4]={soma, sub, mult, divi};

  void(*oper)(int, int, int *); //declaracao do ponteiro para funcao
  
  oper = v[op];
  // oper(n1, n2, &r);
  (*oper)(n1, n2, &r);

  // printf("\n%d\n", *(&r));
  printf("\nr = %d\n", r);

  return 0;
}

void soma(int a, int b, int *r){
  *r = a+b;
}
void sub(int a, int b, int *r){
  *r = a-b;
}
void mult(int a, int b, int *r){
  *r = a*b;
}
void divi(int a, int b, int *r){
  *r = a/b;
}