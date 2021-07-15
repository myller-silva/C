#include <stdio.h>
#include <math.h>
/*
  Escrever um programa que calcule e apresente o somat ́orio do n ́umero de gr ̃aos de trigo que se pode
  obter num tabuleiro de xadrez, obedecendo `a seguinte regra: colocar um gr ̃ao de trigo no primeiro
  quadro e nos quadros seguintes o dobro do quadro anterior. Ou seja, no primeiro quadro coloca-se um
  gr ̃ao, no segundo quadro colocam-se dois gr ̃aos (tendo neste momento trˆes gr ̃aos), no terceiro quadro
  colocam-se quatro gr ̃aos (tendo neste momento sete gr ̃aos), no quarto quadro colocam-se oito gr ̃aos
  (tendo-se ent ̃ao quinze gr ̃aos) at ́e atingir o sexag ́esimo quarto quadro.
*/
int main(void) {
  double somag = 0 ;
  for (int c = 0 ; c<64 ; c++){
    somag += pow(2, c) ;
    printf("no quadro %i totaliza %.0lf graos\n", c+1, somag);
  }
  


  return 0;
}