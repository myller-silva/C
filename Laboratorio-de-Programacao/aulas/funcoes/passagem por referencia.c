#include <stdio.h>
#include <stdlib.h>

void soma(float, float, float *);
void sub(float, float, float *);
void mult(float, float, float *);
void divi(float, float, float *);

int main(int argc, char *argv[]) {
  float n1, n2, op;
  int n3;
  if (argc!=4){
    printf("Formato:\n\t%s <num1> <num2> <op>\n", argv[0]);
    exit(1);
  }
  n1 = atof(argv[1]);
  n2 = atof(argv[2]);
  n3 = atoi(argv[3]);

  switch(n3){
    case 1:
      soma(n1, n2, &op);
      break;
    case 2:
      sub(n1, n2, &op);
      break;
    case 3:
      mult(n1, n2, &op);
      break;
    case 4:
      divi(n1, n2, &op);
      break;
    default:
      puts("Operação invalida");
      exit(2);
  }
  printf("%.2f", op);
    
  return 0;
}


void soma(float a , float b, float *c){
  *c = a + b;
}
void sub(float a , float b, float *c){
  *c = a - b;
}
void mult(float a , float b, float *c){
  *c = a * b;
}
void divi(float a , float b, float *c){
  *c = a / b;
}
