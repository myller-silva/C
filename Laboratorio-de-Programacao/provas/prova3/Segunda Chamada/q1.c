#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct aluno_notas{
  float *notas;
  float media;
  int qt;

}NOTAS;

float media(float *v, int tam);

int main(int argc, char *argv[]){
  if (argc!= 2){
    printf("Formato:\n\t%s <qt de notas>", argv[0]);
    exit(1);
  }

  NOTAS aluno[TAM];

  for(int k=0; k<TAM; k++){

    aluno[k].qt = atoi(argv[1]);  
    aluno[k].notas = malloc(sizeof(float)*aluno[k].qt);
    
    printf("\n>>>Aluno %d\n", k+1);
    for(int c=0; c<aluno[k].qt; c++){
      printf("Nota %d: ", c+1);
      scanf("%f", &aluno[k].notas[c]);
    }    
    aluno[k].media = media(aluno[k].notas, aluno[k].qt);
    printf("Media: %.2f\n", aluno[k].media);
  }  
  return 0;
}

float media(float *v, int tam){
  int c=0; 
  float med = 0; 
  for(c=0; c<tam; c++){
    med += v[c];
  }
  
  med /=((float) tam);

  return med;
}



// Defina uma Estrutura para armazenar notas de alunos e sua m ́edia aritm ́etica. A quantidade de notas
// deve ser especificada pelo usu ́ario por linha de comando. Organize um vetor com 10 elementos dessas
// Estruturas. Crie uma fun ̧c ̃ao para calcular a m ́edia dos alunos. Utilize o typedef e #define.