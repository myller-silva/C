#include <stdio.h>
/*
  Escreva um programa que transforme o computador numa urna eletrˆonica para elei ̧c ̃ao para presidente
  de um certo pa ́ıs, `as quais concorrem os candidatos 5-Paulo e 7-Renata. Cada voto deve ser dado pelo
  n ́umero do candidato, permitindo-se ainda o voto 0 para voto em branco. Qualquer voto diferente dos
  j ́a citados  ́e considerado nulo; em qualquer situa ̧c ̃ao, o eleitor deve ser consultado quanto `a confirma ̧c ̃ao
  do seu voto. No final da elei ̧c ̃ao o programa deve emitir um relat ́orio contendo as porcentagens de
  vota ̧c ̃ao de cada candidato, votos em branco, votos nulos e o candidato eleito. Obs.: O c ́odigo para
  finalizar a urna (vota ̧c ̃ao)  ́e o usu ́ario digitar algum n ́umero negativo.
*/
int main(void) {
  int bonero = 0, lula_molusco = 0, voto = 0, branco = 0, nulo = 0;
  printf("\n>>>ELEIÇÕES 2022<<<\n");
  while (voto >= 0){
    printf("\nDigite: \n\t> 17 para Bonero.\n\t> 13 para Lula Molusco.\n\t> 0 para branco.\n\t> outro para nulo.\n\t> numero negativo para sair. ");
    scanf("%i",&voto);
    int confirmacao = -1;
    do{
      printf("Voce digitou %i. ", voto);
      printf("Confirma? [1=sim / 0=não] ");
      scanf("%i", &confirmacao);
    }while((confirmacao != 1)&&(confirmacao!= 0));
    if (confirmacao == 0){
      printf(">>>CANCELADO<<<\n");
      continue;
    }
    (voto == 17) ? bonero += 1 : 
    (voto == 13) ? lula_molusco += 1: 
    (voto == 0) ? branco += 1 : 
    (voto != 17)&&(voto != 13)&&(voto != 0)&&(voto>0) ? nulo += 1 : -1; 
  }
  float tot = bonero + lula_molusco + branco + nulo;
  printf("\n\n>>>RESULTADO<<< \nBonero: %.1f%%\nLula Molusco: %.1f%%\nBranco: %.1f%%\nNulos: %.1f%%\n", (bonero/tot)*100, (lula_molusco/tot)*100, (branco/tot)*100, (nulo/tot)*100);
  (bonero>lula_molusco) ? printf("\nVENCEDOR: >>>Bonero<<<") : 
  (bonero<lula_molusco) ? printf("\nVENCEDOR: >>>Lula Molusco<<<") : -1;

  return 0;
}