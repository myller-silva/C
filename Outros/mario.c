#include <stdio.h>
#include <stdlib.h>

void print_piramide(int );

int main(){
	// system("clear");

	int esc=0;

	do{
	printf("Altura: ");
	scanf("%d", &esc);
		if(esc<=0 || esc>8) puts("Numero invalido.\nApenas numeros no intervalo [1, 8]");
		else break;		
	}while(1);

	print_piramide(esc);

	return 0;
}

void print_piramide(int esc){
	char *fases[] = {
	"       # #",
	"      ## ##",
	"     ### ###",
	"    #### ####",
	"   ##### #####",
	"  ###### ######",
	" ####### #######",
	"######## ########"
	};
	
	for(int c=0; c<esc; c++){
		puts(fases[c]);
	}
}
