#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void preencher_tab(char *tab, int dim);
void inserir(char *tab, int pos, int jogador);
void exibir_tabuleiro(char *tab, int tam);
int win(char *tab, int dim);

int main(){    
    system("cls");
    char tab[9];
    int pos;
    preencher_tab(tab, 3);
    exibir_tabuleiro(tab, 3);

    int play=0;
    while(1){
        do{
            printf("\nJogador %c: ",  play%2 ? 'O' : 'X');
            scanf("%d", &pos);
            if( (tab[pos]!='_') || (pos<0) || (9<=pos)  ) puts("Posicao invalida. Tente novamente.");
            else break;
        }while( 1 );

        inserir(tab, pos, play);
        system("cls");
        if( win(tab, 3) ){
            break;
        }
        play++;
        exibir_tabuleiro(tab, 3);
        if(play>8) break;
    }
    system("cls");
    exibir_tabuleiro(tab, 3);

    (play>8)? puts("\nEmpate") : printf("\nVencedor: jogador %c\n", play%2 ? 'O' : 'X' );

    return 0;
}

void preencher_tab(char *tab, int dim){
    for(int c=0; c<dim*dim; c++){
        tab[c] = '_';
    }
}


void inserir(char *tab, int pos, int jogador){
    tab[pos] = jogador%2 ? 'O' : 'X';
}

void exibir_tabuleiro(char *tab, int dim){
    for(int c=0; c<dim*dim; c++){        
        if( !(c%dim) ){
            puts("");
        }        
        printf("%c ", tab[c]);
    }
    puts("");
}

int win(char *tab, int dim){
    for(int c=0; c<dim*dim; c+=3){ 
        if( (tab[c]!='_') && tab[c] == tab[c+1] && tab[c+1] == tab[c+2]){
            return 1;
        }
    }
    for(int c=0; c<dim*dim; c++){ 
        if( (tab[c]!='_') && tab[c] == tab[c+dim] && tab[c+dim] == tab[c+dim*2]){
            return 1;
        }
    }
    if((tab[0]!='_') &&tab[0] == tab[4] && tab[4]==tab[8]){
        return 1;
    }
    if((tab[2]!='_') && tab[2] == tab[4] && tab[4]==tab[6]){
        return 1;
    }

    return 0;
}