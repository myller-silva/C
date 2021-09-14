#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct func{
	int id;
	char nome[30];
	int qt;
	float custo;
}FUNC;

int tot_pecas(char *);
void atualizar_tot(char *, int );

void menu();
void inserir(char *, int );
void listar(char *, int );
void remover(char *, int );
void atualizar(char *, int );
int verificar_nome(char *, int , char *);
int verificar_ID(char*, int , int );
void ordenar_por_id(char *, int );

int main(){
	system("cls");
	char *arq_tot_pecas = "tot_cad.txt";	
	char *nome_arq = "hardware.dat";
	int tot = tot_pecas( arq_tot_pecas );
	int op;

	do{
		menu();
		scanf("%d", &op);
		puts("");
		switch(op){
			case 0:
				break;
			case 1:
				inserir(nome_arq, tot);
				puts("Ferramenta adicionada");
				tot++;
				break;
			case 2:
				listar(nome_arq, tot);
				break;
			case 3:
				if(tot) remover(nome_arq, tot);
				puts("Ferramenta removida");
				tot--;
				break;
			case 4:
				atualizar(nome_arq, tot);
				puts("Ferramenta atualizada");
				break;
			case 5:
				ordenar_por_id(nome_arq, tot);
				puts("Estoque ordenado");
				break;
			default:
				puts("Operacao invalida");
		}
		atualizar_tot(arq_tot_pecas, tot);
	}while(op);

    return 0;
}


void menu(){
    puts("\n[1] Inserir");
    puts("[2] Listagem");
    puts("[3] Remover");
    puts("[4] Atualizar");
	puts("[5] Ordenar estoque por ID");
    puts("[0] Encerrar programa");
    printf(">>> ");
}
int tot_pecas(char *nome_arq){
	int qt=0;
	FILE *fp=fopen(nome_arq, "a+");
	if(!fp){
		perror("Erro");
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
	// n.id = tot;
	ID:
	printf("ID: ");
	scanf("%d", &n.id);
	if( verificar_ID(nome_arq, tot, n.id) ){
		puts("Ja existe uma ferramenta com este ID.\nTente novamente.");
		goto ID;
	}
	N:	
	printf("Nome: ");
	scanf("%s", n.nome);
	if( verificar_nome(nome_arq, tot, n.nome) ){
		puts("Ja existe uma ferramenta com este nome.\nTente Novamente.");
		goto N;
	}

	printf("qt: ");
	scanf("%d", &n.qt);
	printf("custo: ");
	scanf("%f", &n.custo);	
	fwrite(&n, sizeof(FUNC), 1, fp);

	fclose(fp);
}
void listar(char *nome_arq, int tot){
	system("cls");
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
	FILE *fp = fopen(nome_arq, "rb");
	if(!fp){
		perror("Erro");
		exit(13);
	}
	FUNC est[tot];
	FUNC n;
	int id;
	fread(est, sizeof(FUNC), tot, fp);
	fclose(fp);

	ID:
	printf("ID da ferramenta: ");
	scanf("%d", &id);
	if( !verificar_ID(nome_arq, tot, id) ){
		puts("ID invalido.\nTente novamente.");
		goto ID;
	}

	I:
	printf("Novo ID: ");
	scanf("%d", &n.id);
	if( verificar_ID(nome_arq, tot, n.id) && n.id!=id ){
		puts("Ja existe uma ferramenta com este ID.\nTente novamente.(o antigo ID eh aceitavel)");
		goto N;
	}

	N:
	printf("Nome: ");
	scanf("%s", n.nome);	
	int e=0;
	if( verificar_nome(nome_arq, tot, n.nome) ){
		for(int c=0; c<tot; c++){
			if(est[c].id == id){
				e = strcmp( est[c].nome, n.nome );
			}
		}
	}
	if(e){
		puts("Ja existe uma ferramenta com este nome.\nTente novamente.(o nome antigo eh aceitavel).\n");
		goto N;
	}
	printf("Qt atual: ");
	scanf("%d", &n.qt);
	printf("Custo atual: ");
	scanf("%f", &n.custo);	
	for(int c=0; c<tot; c++){
		if(est[c].id == id){
			est[c] = n;
		}
	}
	fp = fopen(nome_arq, "wb");
	fwrite(est, sizeof(FUNC), tot, fp);
	fclose(fp);
}
void remover(char *nome_arq, int tot){
	FILE *fp = fopen(nome_arq, "rb");
	FUNC est[tot];
	FUNC n_est[tot-1];
	int id;
	int k=0;
	if(!fp){
		perror("Erro");
		exit(14);
	}
	printf("Id da ferramenta a ser remvida: ");
	scanf("%d", &id);
	fread(est, sizeof(FUNC), tot, fp);
	fclose(fp);
	for(int c=0; c<tot; c++){
		if(est[c].id == id){
			continue;
		}
		n_est[k] = est[c];
		k++;
	}
	fp = fopen(nome_arq, "wb");
	if(!fp){
		perror("Erro");
		exit(15);
	}
	fwrite(n_est, sizeof(FUNC), tot-1, fp);
	fclose(fp);
}
int verificar_nome(char *nome_arq, int tot, char *nome_ferramenta){
	FILE *fp = fopen(nome_arq, "rb");
	FUNC est[tot];

	if(!fp){
		perror("Erro");
		exit(11);
	}

	for(int c=0; c<tot; c++){
        fread(&est[c], sizeof(FUNC), 1, fp);
    }
	fclose(fp);

	for(int c=0; c<tot; c++){
		if( !strcmp(est[c].nome, nome_ferramenta) ){
			return 1;
		}
	}
	return 0;
}
int verificar_ID(char*nome_arq, int tot, int ID){
	FILE *fp = fopen(nome_arq, "rb");
	if(!fp){
		perror("Erro");
		exit(12);
	}
	FUNC est[tot];
	// obs:
	fread(est, sizeof(FUNC), tot, fp);
	
	for(int c=0; c<tot; c++){
		if(est[c].id == ID){
			return 1;
		}
	}
	return 0;
}
void ordenar_por_id(char *nome_arq, int tot){
	FILE *fp = fopen(nome_arq, "rb");
	FUNC est[tot];
	FUNC est_ord[tot];
	int i, j, aux, c;
	int ID_s[tot];

	fread(est, sizeof(FUNC), tot, fp);
	fclose(fp);

	for(i=0; i<tot; i++){
		ID_s[i] = est[i].id;
	}
	// ordenar vec:
	for(i=1; i<tot; i++){
		for(j=tot-1; j>=i; j--){
			if(ID_s[j-1]>ID_s[j]){
				aux = ID_s[j-1];
				ID_s[j-1] = ID_s[j];
				ID_s[j] = aux;
			}			
		}
	}
	// ordenar estoque:
	for(int c=0; c<tot; c++){
		for(int k=0; k<tot; k++){
			if(est[k].id == ID_s[c]){
				est_ord[c] = est[k];
			}
		}
	}
	fp = fopen(nome_arq, "wb");
	fwrite(est_ord, sizeof(FUNC), tot, fp);
	fclose(fp);
}