#include <stdio.h>
#include <stdlib.h>

int main(){
    system("cls");
    FILE *a;
    


    a = fopen("arq.txt", "r");
    if(!a){
        perror("Erro 1");
        exit(1);
    }
    // ler frase inteira:
    char ch;
    while(ch!='\n'){
        fread(&ch, sizeof(char), 1, a);
        printf("%c", ch);
    }

    // ler uma palavra:
    // char *p;
    // fscanf(a, "%s", p);
    // puts(p);

    // ler um caractere:
    // char c;
    // fscanf(a, "%c", &c);
    // printf("%c\n", c);
    // fscanf(a, "%c", &c);
    // printf("%c\n", c);
    // fscanf(a, "%c", &c);
    // printf("%c\n", c);
    
    
    return 0;

}