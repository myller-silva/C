#include <stdio.h>
#include <stdlib.h>
#define MX 3 //quantidade maxima de materiais registrados

typedef struct registro{
    unsigned char registro;
    char nome[30];
    unsigned int quantidade;
    float custo;
}REG;

int main(){
    system("cls");
    REG ferramenta[MX];
    FILE *fp;
    fp = fopen("hardware.txt", "wb");
    if(!fp){
        perror("Erro ao abrir o arquivo hardware.txt");
		exit(1);
    }   
    for(int c=0; c<MX; c++){
        printf("\n>>> Registro %d <<<\n", c);
        ferramenta[c].registro = c;
        puts("nome: ");
        scanf("%s", ferramenta[c].nome);
        puts("quantidade: ");
        scanf("%d", &ferramenta[c].quantidade);
        puts("custo: ");
        scanf("%f", &ferramenta[c].custo);
    }
    fwrite(&ferramenta, sizeof(ferramenta), 1, fp);
	fclose(fp);

    return 0;
}