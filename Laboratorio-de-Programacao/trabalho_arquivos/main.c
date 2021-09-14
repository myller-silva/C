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
void ordem_alfabetica(char *, int );
void validar_FILE(FILE * , char *, int );

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
				puts("\nFerramenta adicionada");
				tot++;
				break;
			case 2:
				listar(nome_arq, tot);
				break;
			case 3:
				if(tot) remover(nome_arq, tot);
				puts("\nFerramenta removida");
				tot--;
				break;
			case 4:
				atualizar(nome_arq, tot);
				puts("\nFerramenta atualizada");
				break;
			case 5:
				ordenar_por_id(nome_arq, tot);
				puts("\nEstoque ordenado por ID");
				break;
			case 6:
				ordem_alfabetica(nome_arq, tot);
				puts("\nEstoque ordenado por ordem alfabetica");
				break;
			default:
				puts("\nOperacao invalida");
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
	puts("[6] Ordenar estoque por ordem alfabetica");	
    puts("[0] Encerrar programa");
    printf(">>> ");
}
int tot_pecas(char *nome_arq){
	int qt=0;
	FILE *fp=fopen(nome_arq, "a+");
	validar_FILE(fp , "tot_pecas", 1);
	// if(!fp){
	// 	perror("Erro");
	// 	exit(6);
	// }
	fscanf(fp, "%d", &qt);	
	fclose(fp);
	return qt;
}
void atualizar_tot(char *nome_arq , int tot){
	FILE *fp=fopen(nome_arq, "w");
	validar_FILE(fp , "atualiar_tot", 2);
	// if(!fp){
	// 	perror("Erro");
	//  exit(2);
	// }
	fprintf(fp, "%d", tot);
	fclose(fp);
}
void inserir(char *nome_arq, int tot){
	FILE *fp=fopen(nome_arq, "ab");	
	validar_FILE(fp , "inserir", 3);
	FUNC n;
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
    FUNC est[tot];
	
    FILE *fp = fopen(nome_arq, "rb");
	validar_FILE(fp , "listar", 4);

	// ler:
    fread(est, sizeof(FUNC), tot, fp);
    fclose(fp);

	// exibir:
    printf("%3.3s %15.10s %5.3s\t%s\n\n", txt[0], txt[1], txt[2], txt[3]);
    for(int c=0; c<tot; c++){
        printf("%.3d %15.10s %5.3d\tR$%6.2f\n", est[c].id, est[c].nome, est[c].qt, est[c].custo);
    }
}
void atualizar(char *nome_arq, int tot){
	FUNC est[tot];
	FUNC n;
	int id;

	FILE *fp = fopen(nome_arq, "rb");
	validar_FILE(fp, "atualizar", 5);
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
		goto I;
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
	validar_FILE(fp, "atualizar", 6);
	fwrite(est, sizeof(FUNC), tot, fp);
	fclose(fp);
}
void remover(char *nome_arq, int tot){
	FILE *fp = fopen(nome_arq, "rb");
	validar_FILE(fp, "remover", 7);

	FUNC est[tot];
	FUNC n_est[tot-1];
	int id;
	int k=0;

	printf("Id da ferramenta a ser removida: ");
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
	validar_FILE(fp, "remover", 8);

	fwrite(n_est, sizeof(FUNC), tot-1, fp);	
	fclose(fp);
}
int verificar_nome(char *nome_arq, int tot, char *nome_ferramenta){
	FILE *fp = fopen(nome_arq, "rb");
	validar_FILE(fp, "verificar_nome", 9);
	FUNC est[tot];
	// for(int c=0; c<tot; c++){
    //     fread(&est[c], sizeof(FUNC), 1, fp);
    // }
	fread(est, sizeof(FUNC), tot, fp);
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
	validar_FILE(fp, "verificar_ID", 10);
	FUNC est[tot];
	fread(est, sizeof(FUNC), tot, fp);
	fclose(fp);	
	for(int c=0; c<tot; c++){
		if(est[c].id == ID){
			return 1;
		}
	}
	return 0;
}
void ordenar_por_id(char *nome_arq, int tot){
	FUNC est[tot];
	FUNC aux;
	int i, j;

	FILE *fp = fopen(nome_arq, "rb");
	validar_FILE(fp, "ordenar por IP", 11);
	fread(est, sizeof(FUNC), tot, fp);
	fclose(fp);

	// ordenar estoque:
	for(i=1; i<tot; i++){
		for(j=tot-1; j>=i; j--){
			if(est[j-1].id>est[j].id){
				aux = est[j-1];
				est[j-1] = est[j];
				est[j] = aux;
			}			
		}
	}
	fp = fopen(nome_arq, "wb");
	validar_FILE(fp, "ordenar por IP", 12);
	fwrite(est, sizeof(FUNC), tot, fp);
	fclose(fp);
}
void ordem_alfabetica(char *nome_arq, int tot){
	FUNC est[tot];
	FUNC aux;
	int i, j;

	FILE *fp = fopen(nome_arq, "rb");
	validar_FILE(fp, "ordem_alfabetica", 13);	
	fread(est, sizeof(FUNC), tot, fp);
	fclose(fp);

	// ordem crescente:
	for( i=0;i<tot;i++){
        for( j=0;j<tot;j++){
            if( strcmp(est[i].nome, est[j].nome) < 0){
				aux = est[i];
				est[i] = est[j];
				est[j] = aux;
            }
        }
    }
	fp = fopen(nome_arq, "wb");
	validar_FILE(fp, "ordem_alfabetica", 13);	
	fwrite(est, sizeof(FUNC), tot, fp);
	fclose(fp);	
}
void validar_FILE(FILE *fp , char *msg, int valor_exit){
	if(!fp){
		fprintf(stderr, "Erro em: %s\n", msg);
		exit(valor_exit);
	}
}

