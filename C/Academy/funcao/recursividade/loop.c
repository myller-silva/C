#include <stdio.h>
void loop();

int main(){
  loop();
  return 0;
}
void loop(){
  printf("Loop ");
  loop();
}