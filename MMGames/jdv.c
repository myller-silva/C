// jogo da velha
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void exibir_j(int *);
void contagem_regressiva(int );
int verificar_l(int *);

int main(){
    int n=1;
    int cont=0;
    int e=0;
    int esc=0;
    int j[9]={0};

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
            e = verificar_l(j);
            if(e==1){
                break;
            }
        }else{
            puts("Posicao indisponivel. Tente novamente.");
            n--;
            contagem_regressiva(3);
        }
        n++;
    }while(cont!=9);

    system("cls");
    puts("\n\t  JOGO DA VELHA"); 
    exibir_j(j);
    if(e==1){
        printf("\nJogador %d venceu!\n\n", (n%2==0) ? 2 : 1 );
    }else{
        printf("\nEmpate.\n\n");
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

// obs
int verificar_l(int *j){
    int c=0;
    int r=0;

    // 0 1 2
    // 3 4 5
    // 6 7 8

    // linha:
    // (j[0] == j[1] == j[2]) 
    // (j[3] == j[4] == j[5])
    // (j[6] == j[7] == j[8])
    for(c=0; c<=6; c+=3){
        if( (j[c]!= 0) && (j[c+1]!= 0) && (j[c+2]!=0) ){            
            if(j[c] == j[c+1] == j[c+2]){
                r = (j[c] == j[c+1] == j[c+2]) ? 1 : 0;
                break;
            }
        }
    }


    // coluna:
    // (j[0] == j[3] == j[6]) 
    // (j[1] == j[4] == j[7]) 
    // (j[2] == j[5] == j[8]) 
    for(c=0; c<3; c++){
        if( (j[c]!= 0) && (j[c+3]!= 0) && (j[c+6]!=0) ){
            if(j[c] == j[c+3] == j[c+6]){
                r = 1;
                break; 
            }
        }
    }


    // // diagonais:
    // (j[0] == j[4] == j[8])
    // (j[2] == j[4] == j[6])

    return r;
}

