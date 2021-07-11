#include <stdio.h>
/*
  A linguagem C pode representar letras maiusculas, letras minusculas e uma grande variedade de
  sımbolos especiais. O C usa internamente pequenos inteiros para representar cada caractere diferente.

  O conjunto de caracteres que um computador utiliza e as representacoes dos ńumeros inteiros corres-
  pondentes `aqueles caracteres  ́e chamado conjunto de caracteres do computador. Vocˆe pode imprimir

  o n ́umero inteiro equivalente `a letra mai ́uscula A, por exemplo, executando a instru ̧c ̃ao

  printf(”%d”, ’A’);

  Escreva um programa em C que imprima os inteiros equivalentes a algumas letras mai ́usculas, letras
  min ́usculas e s ́ımbolos especiais. No m ́ınimo, determine os n ́umeros inteiros equivalentes ao conjunto
  seguinte: A BCabc 0 12 $ * + / e o caractere espa ̧co em branco.
*/

int main(void) {
  printf("A: %d\nB: %d\nC: %d\na: %d\nb: %d\nc: %d\n0: %d\n1: %d\n2: %d\n$: %d\n*: %d\n+: %d\n/: %d\nespaço em branco: %d\n", 'A', 'B', 'C', 'a', 'b', 'c', '0', '1', '2', '$', '*', '+', '/', ' ');

  return 0;
}