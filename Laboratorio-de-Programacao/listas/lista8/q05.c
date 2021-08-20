#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TAM 3
#define INTERVALO 100

typedef struct node{
  int x;
  int y;
  struct node *prox;
} NODE;

void menu(NODE *n, int qt);
void msg_remover_ou_inserir();
void remover(NODE *n, int qt, int);
void inserir(NODE *n, int qt, int);

int main(){
  int qt = TAM;
  char *esc[]={};
  NODE *n = malloc(sizeof(NODE)*qt);

  srand(time(NULL));
  system("clear");
  // preencher:
  for(int c=0; c<TAM; c++){
    (n+c)->x = rand()%INTERVALO;
    (n+c)->y = rand()%INTERVALO;    
  }
  // n1 -> n2 -> n3 -> n1
  for(int c=0; c<TAM; c++){
    if(c==TAM-1){
      (n+c)->prox = n;   
    }
    (n+c)->prox = (n+c+1); 
  }


  menu(n, qt);
  do{
    msg_remover_ou_inserir();
    scanf("%s", esc[0]);    
  }while(*esc[0]!='0'&& *esc[0]!='1');
  
  int pos=-1;
  if( *esc[0] == '0'){
    printf("Node a ser removido: ");
    scanf("%s", esc[0]);
    remover(n, qt, pos);
    --qt;    
    menu(n, qt);
  }else{
    inserir(n, qt, pos);
    ++qt;
  }
  return 0;
}

void menu(NODE *n, int qt){
  int c=0;
  system("clear");
  for (c=0; c<qt; c++){
    printf("node %d:\t(%2d, %2d)\n", c, (n+c)->x, (n+c)->y);
  }
  puts("");
}
void msg_remover_ou_inserir(){
  puts("Remover[0] ");
  puts("Inserir[1] ");
  printf("---> ");
}

void remover(NODE *n, int qt, int pos){
  NODE *temp = malloc(sizeof(NODE)*(qt-1));
  int c=0; 

  puts("removendo");
  sleep(1);
  for(c=3; c>0; c++){
    printf("%d ", c);
    sleep(1);
  }

  for(c=0; c<qt; c++){
    if (c==pos){
      continue;
    }
    *(temp+c) = *(n+c);
  }
  n = realloc(n, sizeof(NODE)*(qt-1));
  for(c=0; c<qt-1; c++){
    *(n+c) = *(temp+c);
  }
  free(temp);
}

void inserir(NODE *n, int qt, int pos){  
  NODE *temp = malloc(sizeof(NODE)*(qt-1));
  int c=0; 

  puts("inserindo");
  sleep(1);
  for(c=3; c>0; c++){
    printf("%d ", c);
    sleep(1);
  }
  for(c=0; c<qt; c++){
    if (c==pos){
      continue;
    }
    *(temp+c) = *(n+c);
  }
  n = realloc(n, sizeof(NODE)*(qt-1));
  for(c=0; c<qt-1; c++){
    *(n+c) = *(temp+c);
  }
  free(temp);
}