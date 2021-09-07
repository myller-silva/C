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
    FILE *fp;
    int pos;
    REG lido;
    
    fp = fopen( "hardware.txt", "rb" );
    if (!fp){
        perror("Erro ao abrir arquivo para leitura.");
        exit(1);
    }

    printf("Digite o numero do registro do produto que desejas verificar: ");
    scanf("%d", &pos);
    // reposicionar indicador do arquivo:
    fseek(fp, pos*sizeof(REG), SEEK_SET );
    // ler:
    fread(&lido, sizeof(REG), 1, fp);
    printf("Numero de Registro: %d\n", lido.registro);
    printf("Nome: %s\n", lido.nome);
    printf("Quantidade: %d\n", lido.quantidade);
    printf("Custo: R$%.2f\n", lido.custo);
    fclose(fp);

    return 0;
}
