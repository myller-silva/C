
int *random_vec_i(int tam , int max, int min);
void show_vec_i(int *v, int tam, char *formatacao);
void show_matriz_i(int *matriz, int lin, int col, char *formatacao);
int min_vec_i(int *v, int tam);
int max_vec_i(int *v, int tam);
// media/ mediana / moda 
float media_vec_i(int *v, int tam);
float mediana_vec_i(int *v, int tam);
int moda_vec_i(int *v, int tam) ;


// algoritmo de ordencao:
int *bubble_sort_i(int *v, int tam);
int *sort_i(int *v, int tam);