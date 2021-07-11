//================================================================
// Descrição: Lê um número decimal e imprime a sua forma binária
//================================================================
  
// Libs
#include <stdio.h>
#include <stdlib.h>
  
// Função Main
int main() {
  int n; // Número de entrada
  int r; // Resultado do deslocamento
  int i; // Contador
  int quant1  = 0;
 // Lê o número
 printf("Digite o numero: ");
 scanf("%d", &n);
  
 // Utiliza um número de 32 bits como base para a conversão.
 printf("%i em decimal equivale a ", n);
 for(i = 31; i >= 0; i--) {
    // Executa a operação shift right até a 
    // última posição da direita para cada bit.
    r = n >> i;
         
    // Por meio do "e" lógico ele compara se o valor 
    // na posição mais à direita é 1 ou 0 
    // e imprime na tela até reproduzir o número binário.
    if(r < 1) {
      printf("1");
      quant1++;
    } else {
      (quant1 != 0) ? printf("0") : -1;
    }
 }
  
 printf(" em binario.\n");
  
 //system("pause");
}