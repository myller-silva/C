#include <stdio.h>

int main(){
    int idade = 18;             //essa variavel idade
    for (int c=0; c<20; c++){   
        int idade = c;          //é diferente dessa
    }                           //logo, num programa de validação de idade, por exemplo,
    return 0;                   //poderia gerar  um bug
}