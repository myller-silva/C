#include <stdio.h>

int main(){
    int jose = 150, pedro = 110, anos=0;
    while(jose>pedro){
        jose += 2;
        pedro+=1;
        ++anos;
    }
    printf("Em %i ano(s) Pedro será maior que José", anos);
    return 0;
}