#include <stdio.h>
#include <stdlib.h>
#define MX 30
#define TAM 100

typedef struct func{
	int id;
	char nome[MX];
	int qt;
	float custo;
}FUNC;

void criar(char *, int );
void inserir(char *, int );
void listagem(char *, int );
void menu();

int main(){
    system("cls");
    int pos=0, esc=-1;
    char *nome_arq = {"hardware.dat"};

    criar(nome_arq, TAM);
    
    // inserir:
    do{
        menu();
        scanf("%d", &esc);
        if(esc==1){
            inserir(nome_arq, pos);
            pos++;
        }else if(esc==2){
            listagem(nome_arq, pos);
        }else if(esc==3){
            puts("Funcao de remover ainda nao foi implementada");
        }
    }while(esc);
    // listagem(nome_arq, pos);
    // FILE *l = fopen("hardware.dat", "rb");
    // FUNC lido[TAM];    
    // for(int c=0; c<TAM; c++){
    //     fread(&lido[c], sizeof(FUNC), 1, l);
    // }
    // char *txt[] = {"ID", "NOME", "QT", "CUSTO"};
    // puts("\t>>> listagem <<<\n");
    // printf("%3.3s %15.10s %5.3s   %s\n\n", txt[0], txt[1], txt[2], txt[3]);
    // for(int c=0; c<pos; c++){
    //     printf("%.3d %15.10s %5.3d R$%5.2f\n", lido[c].id, lido[c].nome, lido[c].qt, lido[c].custo);
    // }

    return 0;
}

void menu(){
    puts("[1] Inserir");
    puts("[2] Listagem");
    puts("[3] Remover");
    puts("[0] Encerrar programa");
}

void inserir(char *nome_arq, int pos){
    // recuperar:
    FILE *fp=fopen(nome_arq, "rb");
    FUNC v[TAM];
    for(int c=0; c<TAM; c++){
        fread(&v[c], sizeof(FUNC), 1, fp);
    }
    fclose(fp);

    v[pos].id = pos;
    printf("Nome: ");
    scanf("%s", v[pos].nome);
    getchar();
    printf("qt: ");
    scanf("%d", &v[pos].qt);
    printf("Custo: ");
    scanf("%f", &v[pos].custo);
    puts("\n");

    // sobrescrever:    
    FILE *e =fopen(nome_arq, "wb");
    for(int c=0; c<TAM; c++){
        fwrite(&v[c], sizeof(FUNC), 1, e);
    }
    fclose(e);
}

void criar(char *nome, int tam){
    FILE *fp=fopen(nome, "wb");
    FUNC v[tam];
    for(int c=0; c<tam; c++){
        fwrite(&v[c], sizeof(FUNC), 1, fp);
    }
    fclose(fp);
}

void listagem(char *nome_arq, int tam){
    char *txt[] = {"ID", "NOME", "QT", "CUSTO"};
    FILE *l = fopen(nome_arq, "rb");
    FUNC lido[TAM];    
    for(int c=0; c<TAM; c++){
        fread(&lido[c], sizeof(FUNC), 1, l);
    }
    puts("\t>>> listagem <<<\n");
    printf("%3.3s %15.10s %5.3s   %s\n\n", txt[0], txt[1], txt[2], txt[3]);
    for(int c=0; c<tam; c++){
        printf("%.3d %15.10s %5.3d R$%5.2f\n", lido[c].id, lido[c].nome, lido[c].qt, lido[c].custo);
    }
    puts("\n");
    fclose(l);
}