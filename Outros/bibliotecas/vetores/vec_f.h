float *random_vec_f(int tam, float LS, float LI);
void show_vec_f(float *v, int tam, char *formatacao);
void show_matriz_f(float *matriz, int lin, int col, char *formatacao);
float min_vec_f(float *v, int tam);
float max_vec_f(float *v, int tam);
int x_in_vec_f(float *v, int tam, float x);

// media/ mediana / moda 
float media_vec_f(float *v, int tam);
float mediana_vec_f(float *v, int tam);
// float moda_vec_f(float *v, int tam);
// bug:
float *moda_vec_f(float *v, int tam, int *qt);

// ordenacao:
float *bubble_sort_f(float *v, int tam);
float *sort_f(float *v, int tam);
