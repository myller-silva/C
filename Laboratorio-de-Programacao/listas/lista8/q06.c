// Exemplifique, com c´odigo, Enumera¸c˜oes em C.#include <stdio.h>
#include <stdlib.h>

enum dias_em_ingles{
  sunday=1, monday, tuesday, wednesday, thursday, friday, saturday
};

int main(){
  char *semana[8] = {"", "domingo", "segunda", "terca", "quarta", "quinta", "sexta", "sabado"};

  system("clear");
  printf("\nsunday é:\t\t%s\n", semana[sunday]);
  printf("monday é:\t\t%s\n", semana[monday]);
  printf("tuesday é:\t\t%s\n", semana[tuesday]);
  printf("wednesday é:\t%s\n", semana[wednesday]);
  printf("thursday é:\t\t%s\n", semana[thursday]);
  printf("friday é:\t\t%s\n", semana[friday]);
  printf("saturday é:\t\t%s\n", semana[saturday]);
  
  return 0;
}
