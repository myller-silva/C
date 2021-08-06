// Crie uma Estrutura disciplina em que um dos campos corresponde tambem a uma estrutura pro-
// fessor.
#include <stdio.h>
#include <stdlib.h>

struct disciplina
{
    char nome[20];
    struct professor
    {
        char nome[20];
    };
};
int main(){

    return 0;
}