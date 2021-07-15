#include <stdio.h>
#include <math.h>
#define LIMITE 500
/*
  Um triˆangulo retˆangulo pode ter lados que s ̃ao valores inteiros. O conjunto de trˆes valores inteiros para
  os lados de um triˆangulo retˆangulo  ́e chamado de tripla de Pit ́agoras. Esses trˆes lados precisam satisfazer
  o relacionamento de que a soma do quadrado de dois catetos  ́e igual ao quadrado da hipotenusa. Ache
  todas as triplas de Pit ́agoras n ̃ao superiores a 500 para cateto1, cateto2 e hipotenusa. Este  ́e um exemplo
  de computa ̧c ̃ao por for ̧ca bruta. Isso n ̃ao  ́e esteticamente atraente para muitas pessoas. Mas existem
  muitos motivos para essas t ́ecnicas serem importantes. Em primeiro lugar, com o poder da computa ̧c ̃ao
  aumentando em um ritmo t ̃ao fenomenal, solu ̧c ̃oes que levariam anos, ou mesmo s ́eculos, para serem
  produzidas com a tecnologia de alguns anos atr ́as, agora podem ser produzidas em horas, minutos ou
  mesmo segundos. Os chips microprocessadores recentes podem processar um bilh ̃ao de instru ̧c ̃oes por
  segundo! Em segundo lugar, como vocˆe descobrir ́a mais adiante no Curso de Ciˆencias da Computa ̧c ̃ao,
  existem in ́umeros problemas interessantes para os quais n ̃ao existe uma t ́ecnica algor ́ıtmica conhecida
  al ́em da simples for ̧ca bruta.
*/
int main(void) {
  int tot = 0;
  for (int hipotenusa = 1 ; hipotenusa <= LIMITE ; hipotenusa++){    
    for (int c1 = 1 ; c1 <= LIMITE ; c1++){
      for (int c2 = 1 ; c2 <= LIMITE ; c2++){
        int h = sqrt(c1*c1+c2*c2);
        if (h*h == c1*c1 + c2*c2){
          tot += 1;
          // printf("%i^2(h) = %i^2(c1) + %i^2(c2) = %i     >>> tot+=1: %i \n", h, c1, c2, (c1*c1 + c2*c2) , tot);
        }
      }
    }
  }
  printf("\nTotal de tripla de Pitágoras catetos e hipotenusa entre [1, %i]: %i", LIMITE, tot);
  return 0;
}