#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    system("cls");
    char nome1[] = {"mac"};
    char nome2[] = {"myller"};

    if( !strcmp(nome1, nome2) ){
        puts("iguais");
    }else{
        puts("diferentes");
    }

    

    return 0;
}