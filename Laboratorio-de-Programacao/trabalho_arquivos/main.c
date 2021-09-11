#include <stdio.h>
#include <stdlib.h>
#define MX 30
#define TOT_de_ferramentas 4

typedef struct func{
	int id;
	char nome[MX];
	int qt;
	float custo;
}FUNC;

void menu();
void criar(char *, int );
void inserir(char *, int );
void listagem(char *, int );
void atualizar(char *, int );

int main(){
    system("clear");
    int tot=TOT_de_ferramentas;
	  int esc=-1;
    char *nome_arq = {"hardware.dat"};

    do{
        menu();
        scanf("%d", &esc);
        if(esc==1){
            inserir(nome_arq, tot);
            tot++;
        }else if(esc==2){
            listagem(nome_arq, tot);
        }else if(esc==3){
            puts("Funcao de remover ainda nao foi implementada");            
        }else if(esc==4){
            if(!tot){
                puts("Ainda nao ha ferramentas para atualizar");
            }else{
                atualizar( nome_arq, tot);
            }
        }
    }while(esc);
    return 0;
}

void menu(){
    puts("[1] Inserir");
    puts("[2] Listagem");
    puts("[3] Remover");
    puts("[4] Atualizar");
    puts("[0] Encerrar programa");
    printf(">>> ");
}
void criar(char *nome, int tam){
    FILE *fp=fopen(nome, "wb");
    FUNC v[tam];
    if(!fp) perror("Erro");
    for(int c=0; c<tam; c++){
        fwrite(&v[c], sizeof(FUNC), 1, fp);
    }
    fclose(fp);
}


void inserir(char *nome, int pos){
	FILE *fp=fopen(nome, "a+b");
	FUNC n;
	if(!fp) perror("Erro");
	n.id = pos;
	printf("Nome: ");
    scanf("%s", n.nome);
    getchar();
    printf("qt: ");
    scanf("%d", &n.qt);
    printf("Custo: ");
    scanf("%f", &n.custo);
    puts("");
	fwrite(&n, sizeof(FUNC), 1, fp);
	fclose(fp);
}
void listagem(char *nome_arq, int tam){
    system("clear");
    char *txt[] = {"ID", "NOME", "QT", "CUSTO"};
    FILE *l = fopen(nome_arq, "rb");
    FUNC lido[tam];    
    if(!l) perror("Erro");
    for(int c=0; c<tam; c++){
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
void atualizar(char *nome_arq, int tot){
    int id;
    FILE *fp = fopen(nome_arq, "rb");
    FUNC v[tot];
    if(!fp) perror("Erro");
    // recuperar:
    for(int c=0; c<tot; c++){
        fread(&v[c], sizeof(FUNC), 1, fp);        
    }
    fclose(fp);

    T:
    printf("ID da ferramenta que deseja atualizar: ");
    scanf("%d", &id);
    if( id<0 || tot<id ){
        puts("ID invalido, tente novamente.");
        goto T;
    }
    printf("Atualizando ferramenta: %s\n", v[id].nome);
    // atualizar:
    printf("Quantidade atual: ");
    scanf("%d", &v[id].qt);
    printf("Custo atual: ");
    scanf("%f", &v[id].custo);

    // salvar:
    fp = fopen(nome_arq, "wb");
    if(!fp) perror("Erro");

    for(int c=0; c<tot; c++){
        fwrite(&v[c], sizeof(FUNC), 1, fp);        
    }
    fclose(fp);

    puts("Ferramenta atualizada com sucesso");    
}