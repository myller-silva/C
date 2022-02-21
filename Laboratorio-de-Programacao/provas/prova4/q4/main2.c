#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct func{
	int id;
	char nome[30];
}FUNC;


int main(){
	system("cls");
    
	char *arq_tot_nomes = "tot_cad.txt";	
	char *nome_arq = "hardware.dat";
	int tot = tot_nomes( arq_tot_nomes );
    
	do{
		menu();
		scanf("%d", &op);
		puts("");
		switch(op){
			case 0:
				break;
			case 1:
				inserir(nome_arq, tot);
				puts("\nNome adicionado");
				tot++;
				break;
			case 2:
				// remover(nome_arq, tot);
				puts("\nFuncao de remover ainda nao implementada");
				break;
            default:
				puts("\nOperacao invalida");
		}
		atualizar_tot(arq_tot_nomes, tot);
	}while(op);


    return 0;
}

void menu(){
    puts("\n[1] Inserir");
    puts("[2] Remover");
    puts("[0] Encerrar programa");
    printf(">>> ");
}

void inserir(char *nome_arq, int tot){
	FILE *fp=fopen(nome_arq, "ab");	
    if(!fp){
		fprintf(stderr, "Erro em: %s\n", "inserir");
		exit(1);
	}
	FUNC n;
    n.id = tot++;
    printf("Nome: ");
    scanf("%s", n.nome);    
	fwrite(&n, sizeof(FUNC), 1, fp);
	fclose(fp);
}


int tot_nomes(char *nome_arq){
	int qt=0;
	FILE *fp=fopen(nome_arq, "a+");
    if(!fp){
		fprintf(stderr, "Erro em: %s\n", "total de nomes");
		exit(valor_exit);
	}
	fscanf(fp, "%d", &qt);	
	fclose(fp);
	return qt;
}
