#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void exibir(char *);
int win(char *);
int main(){
    char j[9] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
    int esc = 0, c = 0;
    for(c=0; c<9; c++){
        system("cls");
        exibir(j);
        T:
        printf("Player N%d: ", c%2==0 ? 1 : 2);
        scanf("%d", &esc);
        if(j[esc-1]=='_'){
            j[esc-1] = c%2==0 ? 'X' : 'O';
            if( win(j) ){
                break;
            }
        }else{
            puts("Posicao invalida. Tente novamente.");
            sleep(1);
            goto T;
        }
    }    
    system("cls");
    exibir(j);
    if(win(j)==0){
        puts("\n\tEmpate.");
    }else{
        printf("\n\tVencedor: Player N%d\n", c%2 ? 2:1 );
    }
    return 0;
}
void exibir(char *j){
    int c=0;
    puts("\n\t>>>JOGO DA VELHA<<<");
    for(c=0; c<9; c++){
        if( c%3==0 ){
            printf("\n\n\t");
        }
        printf(" %c\t", j[c]);
    }
    puts("\n");
}
int win(char *j){
    int c=0;
    // linhas:
    for(c=0; c<9; c+=3){
        if( (j[c] != '_') && (j[c] == j[c+1]) && (j[c+1] == j[c+2]) ){
            return 1;
        }
    }
    // colunas:
    for(c=0; c<3; c++){
        if( (j[c] != '_') && (j[c] == j[c+3]) && (j[c+3] == j[c+6]) ){
            return 1;
        }
    }
    // diagonais:
    if(  (j[0] != '_') && (j[0] == j[4]) && (j[4] == j[8])  ){
        return 1;
    }else if(  (j[2] != '_') && (j[2] == j[4]) && (j[4] == j[6])  ){
        return 1;
    }    
    return 0;
}