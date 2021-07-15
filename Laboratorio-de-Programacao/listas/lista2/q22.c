#include <stdio.h>

int main(void) {
  unsigned long int n0 = 0, cont = 0;
  printf("Digite um numero inteiro: ");
  scanf("%li", &n0);
  while(1){
    printf("\nn0 = %li\nCont = %li\n", n0, cont);
    ((n0 % 10) == 7) ? cont++ : -1; 
    n0 /= 10;
    
    if (n0 == 0){
      break;
    }
  }
  printf("\nTotal de digitos ""7"": %li", cont);


  return 0;
}