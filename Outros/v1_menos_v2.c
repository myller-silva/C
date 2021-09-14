#include <stdio.h>
#include <stdlib.h>
#define N 7
#define CLS system("cls")

void exibir_v(int [], int );
void ordenar_v(int [], int );
int a_menos_b(int [], int [], int , int []);

int main(void) {
	CLS;

	int a[N]= {1, 65, 10, 71, 3, 4, 9};
	int b[N]= {2, 71, 4, 0, 32, 9, 9};	
	
	int c[N];
	int tam_c=0;
	
	printf("a: ");
	ordenar_v(a, N);
	exibir_v(a, N);

	printf("b: ");	
	ordenar_v(b, N);
	exibir_v(b, N);

	tam_c = a_menos_b(a, b, N, c);
	printf("c: ");
	ordenar_v(c, tam_c);
	exibir_v(c, tam_c);

  return 0;
}
void exibir_v(int v[], int tam){
	for(int c=0; c<tam; c++){
		printf("%d ", v[c]);
	}
	puts("");
}

void ordenar_v(int v[], int tam){
	int aux;
	for(int c=0; c<tam; c++){
		for(int k=0; k<tam; k++){
			if(v[c]<v[k]){
				aux = v[c];
				v[c] = v[k];
				v[k] = aux;
			}
		}
	}
}

int a_menos_b(int a[], int b[], int tam, int c[]){
	int tam_c=0;
	int i=0, j=0;

	for(i=0; i<N; i++){
		int e=0;
		for(j=0; j<N; j++){
			if( a[i]==b[j] ){
				e=1;
				break;
			}
		}
		if(!e){
			c[tam_c++] = a[i];
		}
	}
	return tam_c;
}
