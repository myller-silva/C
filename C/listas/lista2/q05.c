#include <stdio.h>
  // Fazer um programa que receba um valor n no teclado e determine o maior e o menor termo fornecido.
  // A condi ̧c ̃ao de termino do programa  ́e quando o usu ́ario digitar zero.
int main(void) {
  int n = 0, maior = 0, menor = 0, cont = 0;
  do{
    printf("Digite um numero: ");
    scanf("%i", &n);
    (cont == 0)? maior = menor = n :
    (n > maior)? maior = n :
    (n<menor)&&(n!=0)? menor = n : -1;
    ++cont;
    // if (cont == 0){
    //   maior = menor = n;
    // }else{
    //   if(n>maior){
    //     maior = n;        
    //   }else{
    //     if (n < menor) {
    //       menor = n;          
    //     }
    //   }
    // }
  }while (n != 0);
  printf("Maior: %i\nMenor: %i\n", maior, menor);
  return 0;
}