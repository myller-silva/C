#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    // char vetor[10][50], aux[50];
    char vetor[10][30] = {"maca", "banana", "legume", "tomate", "uva", "laranja", "verde", "pimenta", "abacaxi", "kiwi"};
    char aux[30];
    int i, j;
    system("cls");

    // for(i=0;i<10;i++){
    //     printf("String %d: ", i);
    //     fgets(vetor[i], 50, stdin);
    // }
    for(int c=0; c<10; c++){
        printf("%s ", vetor[c]);     
    }
    puts("\n");

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(strcmp(vetor[i], vetor[j]) < 0){
                strcpy(aux, vetor[i]);
                strcpy(vetor[i], vetor[j]);
                strcpy(vetor[j], aux);
            }
        }
    }
    for(i=0;i<10;i++){
        printf("%s ", vetor[i]);  
    }
    puts("\n");
    
    system("pause");

    return(0);
}