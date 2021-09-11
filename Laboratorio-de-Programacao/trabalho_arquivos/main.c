#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct func{
	int id;
	char nome[30];
	int qt;
	float custo;
}FUNC;

void menu();
int tot_pecas(char *);
void atualizar_tot(char *, int );
void inserir(char *, int );
void listar(char *, int );
void atualizar(char *, int );
void remover(char *, char *);

int main(){
	system("clear");
	char *arq_tot_pecas = "tot_prod.txt";	
	char *nome_arq = "hardware.dat";
	int tot = tot_pecas( arq_tot_pecas );
	int op;

	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				inserir(nome_arq, tot);
				tot++;
				break;
			case 2:
				listar(nome_arq, tot);
				break;
			case 3:
				puts("Ainda nao implementado");
				// if(tot) remover(nome_arq, arq_tot_pecas);
				// tot--;
				break;
			case 4:
				atualizar(nome_arq, tot);
				break;
		}
		if(op>4){
			puts("Operacao invalida");
		}
	}
	while(op);
	atualizar_tot("tot_prod.txt", tot);
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
int tot_pecas(char *nome_arq){
	int qt;
	FILE *fp=fopen(nome_arq, "r");
	if(!fp){
		perror("Verifique se ha o arquivo contendo a quantidade de ferramentas atuais");
		exit(6);
	}
	fscanf(fp, "%d", &qt);	
	fclose(fp);
	return qt;
}
void atualizar_tot(char *nome_arq , int tot){
	FILE *fp=fopen(nome_arq, "w");
	if(!fp){
		perror("Erro");
	}
	fprintf(fp, "%d", tot);
	fclose(fp);
}
void inserir(char *nome_arq, int tot){
	FILE *fp=fopen(nome_arq, "ab");	
	FUNC n;
	if(!fp){
		perror("Erro");
		exit(2);
	}
	n.id = tot;
	printf("Nome: ");
	scanf("%s", n.nome);
	printf("qt: ");
	scanf("%d", &n.qt);
	printf("custo: ");
	scanf("%f", &n.custo);	
	fwrite(&n, sizeof(FUNC), 1, fp);

	fclose(fp);
}
void listar(char *nome_arq, int tot){
	system("clear");
    char *txt[] = {"ID", "NOME", "QT", "CUSTO"};
    FILE *l = fopen(nome_arq, "rb");
    FUNC lido[tot];

    if(!l){
		perror("Erro");
		exit(5);
	}

    for(int c=0; c<tot; c++){
        fread(&lido[c], sizeof(FUNC), 1, l);
    }
    puts("\t>>> listagem <<<\n");
    printf("%3.3s %15.10s %5.3s   %s\n\n", txt[0], txt[1], txt[2], txt[3]);

    for(int c=0; c<tot; c++){
        printf("%.3d %15.10s %5.3d R$%6.2f\n", lido[c].id, lido[c].nome, lido[c].qt, lido[c].custo);
    }	
    puts("");

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
    if( id<0 || tot<=id ){
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
	puts("\n>>>Ferramenta atualizada<<<\n");    
}



void remover(char *nome_arq, char *arq_tot_pecas){
	FILE *fp = fopen(nome_arq, "rb");	
	int tot = tot_pecas(arq_tot_pecas);
	int e;

	if(!fp){
		perror("Erro");
	}
	FUNC o[tot];
	FUNC n[tot-1];

	R:
	printf("Digite o ID da ferramenta que deseja remover: ");
	scanf("%d", &e);
	if(e<0 || tot<=e){
		printf("ID invalido. Apenas numeros no intervalo de [0, %d]\n", tot-1);
		puts("Tente novamente 3 segundos.");
		sleep(3);
		goto R;
	}
	fread(&o, sizeof(FUNC), 1, fp);
	rewind(fp);
	int k=0;
	for(int c=0; c<tot; c++){
		if(o[c].id == e){
			continue;
		}
		n[k] = o[c];
		k++;
	}
	fclose(fp);
}
