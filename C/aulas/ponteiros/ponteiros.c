#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  int v[2]= {10, 20};

  printf("[%p] %d\n", &v[0], v[0]);
  printf("[%p] %d\n", v+0, *(v+0)); 
  puts("");
  printf("[%p] %d\n", &v[1], v[1]);
  printf("[%p] %d\n", v+1, *(v+1)); 
}