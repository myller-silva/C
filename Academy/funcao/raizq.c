#include <stdio.h>
float raizq(float n);

int main(){
  float n;
  printf("Digite um numero: ");
  scanf("%f", &n);
  printf("raizq(%.2f) = %.2f\n", n, raizq(n));

  return 0;
}

float raizq(float n){
  float r=1;
  float e=0;
  X:
  e = (r*r - n) ;
  if (e<0){
    e *= (-1) ;
  }
  if ( e < 0.001){
    return r;
  }else{
    r = (r*r + n)/(2*r);
    goto X;
  }
  return r;
}