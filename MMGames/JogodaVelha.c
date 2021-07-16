// jogo da velha
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exibir_j(int *);
void contagem_regressiva(int );
int verificar_lcd(int *);

int main(){
    int n=1;
    int cont=0;
    int e=0;

    int j[9]={0};
    int esc=0;

    do{
        system("cls");
        puts("\n\t  JOGO DA VELHA");   
        exibir_j(j);

        printf("\nJogador %d: ", (n%2==0) ? 2 : 1 );
        scanf("%d", &esc );

        if( (j[esc-1]==0) && (0<esc) && (esc<10) ){
            j[esc-1] = (n%2==0) ? 2 : 1 ;
            cont++;

// obs
            e = verificar_lcd(j);
            if((e==1)&&(cont>2)) {
                break;
            }
// obs
        }else{
            puts("Posicao indisponivel. Tente novamente.");
            n--;
            contagem_regressiva(3);
        }
        // e = verificar_lcd(j);
        // if(e==1){
        //     break;
        // }
        n++;
    }while(cont!=9);


    system("cls");
    puts("\n\t  JOGO DA VELHA"); 
    exibir_j(j);
    if(e==1){
        printf("Vencedor: %d\n", (n%2==0) ? 2 : 1 );
    }
    return 0;
}

void contagem_regressiva(int k){
    int c=0;
    for(c=k; c>0; c--){
        printf("%d... ", c);
        sleep(1);
    }
}
void exibir_j(int *j){
    int c=0;
    for(c=0; c<9; c++){
        if(c%3==0){
            printf("\n\n\t");
        }
        if(j[c]==1){
            printf("X\t");
        }else if(j[c]==2){
            printf("O\t");
        }else{
            printf("_\t");
        }
    }
    puts("");
}


int verificar_lcd(int *j){
    // int c=0;
    int r=0;
    if  (   (j[0] == j[1] == j[2]) || (j[0] == j[3] == j[6]) || (j[0] == j[4] == j[8])   ) {
        r = 1;
    }

    return r;
}

