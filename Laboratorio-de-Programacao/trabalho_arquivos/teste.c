#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct func{
	int id;
	char nome[30];
	int qt;
	float custo;
}FUNC;

void ordenar_por_nome(char *nome_arq, int tot);

int main(){
    system("cls");
    int tot;
	FILE *fp = fopen("tot_cad.txt", "r");
    fscanf(fp, "%d", &tot);
    fclose(fp);

    fp = fopen("hardware.dat", "rb");
	FUNC est[tot];
    fread(est, sizeof(FUNC), tot, fp);
    fclose(fp);
	
	for(int c=0; c<tot; c++){
        puts(est[c].nome);
    }
    puts("");

    
    return 0;
}