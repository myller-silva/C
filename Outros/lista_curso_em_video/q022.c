/* 022 - Analisador de textos
Crie um programa que leia o nome completo de uma pessoa e mostre: em lestras maiúsculas, minúsculas, a quantidade de letras sem espaço, e quantas letras tem o primeiro nome */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
char *str_capital(char *nome);
char *str_small(char *nome);

struct nome
{
    char nome[TAM];
    char maiuscula[TAM];
    char minuscula[TAM];
    int qt_sem_espaco;
    int qt_primeiro_nome;
};
int qt_primeiro_nome(char *nome);
int qt_sem_esp(char *nome);

int main(){
    char *nome = "maria eridan da silva";
    struct nome n;

    strcpy(n.nome, nome);

    n.qt_primeiro_nome = qt_primeiro_nome(n.nome);
    n.qt_sem_espaco = qt_sem_esp(n.nome);
    strcpy(n.maiuscula, str_capital( n.nome ));
    strcpy(n.minuscula, str_small( n.nome ));

    puts(n.nome);
    puts(n.maiuscula);
    puts(n.minuscula);
    printf("qt primeiro nome: %d\n", n.qt_primeiro_nome);
    printf("qt sem espaco: %d\n", n.qt_sem_espaco);
    



    return 0;
}

int qt_primeiro_nome(char *nome){
    int c=0;
    int qt=0;
    while(1){
        if( nome[c]==' ' || nome[c]=='\0' ){
            break;
        }
        c++;
        qt++;
    }
    return qt;
}

int qt_sem_esp(char *nome){
    int c=0;
    int qt=0;
    while(1){
        if(nome[c]==' '){
            c++;
            continue;
        }
        if(nome[c]=='\0'){
            break;
        }
        
        c++;
        qt++;
    }
    return qt;
}

char *str_capital(char *nome){
    char *temp = malloc( sizeof(char) );
    int i=0;
    int c=0;

    while(nome[i])
    {
        if( 97<=nome[i] && nome[i]<=122){
            temp[c++] = nome[i]-32;    
        }else{
            temp[c++] = nome[i];
        }
        temp = realloc(temp, sizeof(char)*(c+1));

        i++;
    }
    temp[c] = 0;
    return temp;
}

char *str_small(char *nome){
    char *temp = malloc( sizeof(char) );
    int i=0;
    int c=0;

    while(nome[i])
    {

        if( 65<=nome[i] && nome[i]<=90 ){
            temp[c++] = nome[i]+32;
        }else{
            temp[c++] = nome[i];
        }
        temp = realloc(temp, sizeof(char)*(c+1)); 
        i++;

    }
    temp[c] = 0;
    return temp;
}

