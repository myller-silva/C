#include <stdio.h>
#include <stdlib.h>
int func(char *s, char c, char *p);
// int main(){
//   char *s = {"Ola, mundo"};
//   char c = 'm';
//   char *p=NULL;
//   int cont=0;

//   cont = func(s, c, p);

//   printf("%s\n", s);
//   printf("%c\n", c);  
//   printf("Cont: %d\n", cont);
//   printf("%s\n", p);

//   return 0;
// }

int func(char *s, char c, char *p){
  int i = 0;
  while(s[i]!=c){
    if(s[i]=='\0'){
      break;
    }
    i++;
  }  
  char temp[i];  
  for(int c=0; c<i; c++){
    *(temp+c) = *(s+c);
  }
  // printf("%s\n", temp);
  p = realloc(p, i*sizeof(char));

  for(int c=0; c<i; c++){
    *(p+c) = *(temp+c) ;
  }
  return i;
}