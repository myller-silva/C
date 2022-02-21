#include <stdio.h>
#include <stdlib.h>
#include "vec_i.h"

int main(int argc, char *argv[]){

	int vetor[] = {71, 84, 52, 81, 89, 72, 80, 67, 120, 90, 80, 78, 69, 91, 71, 75, 75, 88, 78, 73,
86, 78, 75, 73, 80, 78, 73, 81, 77, 82};
	int *vetor_ordenado = NULL;

	// ordenado:
	vetor_ordenado = sort_i(vetor, 30);

	show_vec_i(vetor_ordenado, 30, "%d ");

	return 0;
}
