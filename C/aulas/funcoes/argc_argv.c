#include <stdio.h>
#include <stdlib.h>

float soma(float, float);
float sub(float, float);
float mult(float, float);
float divi(float, float);

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
      op  = soma(n1, n2);
      break;
    case 2:
      op = sub(n1, n2);
      break;
    case 3:
      op = mult(n1, n2);
      break;
    case 4:
      op = divi(n1, n2);
      break;
    default:
      puts("Operação invalida");
      exit(2);
  }
  printf("%.2f\n", op);
    
  return 0;
}

float soma(float a , float b ){
  return (a + b);
}
float sub(float a , float b ){
  return (a - b);
}
float mult(float a , float b ){
  return (a * b);
}
float divi(float a , float b ){
  return (a / b);
}
