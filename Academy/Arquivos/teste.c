#include <stdio.h>
#include <stdlib.h>
#define MX 80

int main(){
    char nomeArq[MX] ;
    char contArq[MX] ;
    FILE *pa;
    
    system("cls");

    printf("Nome do arquivo: ");
    scanf("%s", nomeArq);  
    getchar();
    // validacao:
    pa = fopen(nomeArq, "w");
    if(pa == NULL){
        puts("erro ao abrir arquivo.");
        exit(1);
    }
    // escrita:
    puts("Digite o conteudo do arquivo: ");
    do{
        fgets(contArq, MX-1, stdin);
        fputs(contArq, pa);
    }while(  contArq[0] != '\n' );
    // rebubinar:
    rewind(pa);

    system("cls");
    // ler dados:
    puts("Conteudo:");
    puts(pa->_ptr);
    // puts(pa->_base);
    
    fclose(pa);

    return 0;
}