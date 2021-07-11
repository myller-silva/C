#include <stdio.h>
#include <stdlib.h>

void soma(int , int , int *);
void mult(int , int , int *);

int main(int argc, char *argv[]){
  int x, y, z, op;
  if (argc!=4){
    printf("\nFormato:\n\t%s <num1> <num2> <op>\nop: \n\t[1]: soma\n\t[2]: multiplicação.\n", *argv);
    exit(1);
  }
  x = atoi( *(argv+1) );
  y = atoi( *(argv+2) );
  op = atoi( *(argv+3) );
  switch(op){
    case 1:
      soma(x, y, &z);
      break;
    case 2:
      mult(x, y, &z);
      break;
    default:
      printf("\nFormato:\n\t%s <num1> <num2> <op>\nop: \n\t[1]: soma\n\t[2]: multiplicação.\n", *argv);
      exit(2);
  }
  printf("%d", x);
  (op==1)?printf(" + ") : printf(" x ");
  printf("%d = %d\n", y, z);
  
  return 0;
}
void soma(int a, int b, int *r){
  *r = a+b;
}
void mult(int a, int b, int *r){
  *r = a*b;
}