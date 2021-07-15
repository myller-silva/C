// ponteiros para funcoes
#include <stdio.h>

int myFunc(int); //declaração de funcao 

// obs:
//   os parenteses em "(*pF)" sao obrigatorios
//   pois se remover os parenteses ficaria: >>> int *pF(int); <<<
//   pF seria uma funcao que recebe um int e devolve um int*(ponteiro int)

int main(){
  int (*pF)(int); //declaração de ponteiro para funcao
  int x;

  // atribuicao:
  pF = myFunc;      //em outras palavras, agora pF aponta para myFunc;
  x = myFunc(10);   //1ª tradicional, usando o nome da propria funcao
  // ou
  x = pF(10);       //2ª usando o ponteiro como se fosse uma funcao
  // ou 
  x = (*pF)(10);    //3ª usando a sintaxe de ponteiro
  // internamente, ambas opcoes sao equivalentes, mas os programadores preferem a ultima, pois ela deixa claro que pF é um ponteiro para função

  // vantagens:
  // 1 - se voce usa ponteiros para funcoes, voce pode passar o ponteiro de uma função para outras funções.
  // 2 - pode retornar. pode ter uma funcao que retorna um ponteiro para outra funcao.
  // 3 - pode armazenar em uma matriz; imagine que voce tem um vetor de ponteiros onde cada elemento é o endereco de uma funcao(um ponteiro de uma funcao).



  return 0;
}