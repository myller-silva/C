#include <stdio.h>
#include <stdlib.h>
#define MX 30

int validar_int();
int main(){
	int n;
	printf("Digite um numero: ");
	// n = validar_float();
	scanf("%d", &n);
	printf("%d ", n);

	return 0;
}

int validar_int(){
	char c[MX];
	int n;

	fgets(c, MX, stdin);
	n = atoi(c);

	return n;
}
