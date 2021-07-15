#include <stdio.h>
#include <math.h>
/*
  Um pal ́ındromo  ́e um n ́umero, ou frase textual, que pode ser lido da mesma forma da esquerda para
  a direita e vice-versa. Por exemplo, cada um dos seguintes inteiros de cinco d ́ıgitos  ́e um pal ́ındromo:
  12321, 55555, 45554 e 11611. Escreva um programa que leia um inteiro de cinco d ́ıgitos e determine se
  ele  ́e ou n ̃ao um pal ́ındromo. [Dica: use os operadores de divis ̃ao e m ́odulo para separar o n ́umero em
  seus d ́ıgitos individuais.]
*/

int main(void) {
  float resto = 0, nf =0, separar = 0;
  int n0 = 0;
  printf("Digite um numero de 5 digitos: ");
  scanf("%i", &n0);
  float g = n0;

  for(float cont = 1, c = 4 ; cont <=5 && c>=0 ; cont++ && c--){
    resto = n0%10;
    separar = resto * pow(10, c);
    n0 /= 10;
  }
  (nf!=g) ? printf("%f != %.0f. Logo, não é um palindromo.\n", g, nf):
  printf("%f = %.0f. Logo, é um palindromo.\n", g, nf);
      
  return 0;
}