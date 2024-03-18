#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double d_rand(double min, double max) {
    double range = max - min;
    double random_value = rand() / (double)RAND_MAX;
    return min + random_value * range;
}

void d_array_set_random(double *first, double *last, double min, double max){
    last--;
    for(last; last >= first; last--) {
        *last = d_rand(min, max);
    }
    printf("\n");
}

double *my_alloc(int i_min, int i_max){
    size_t size = i_max - i_min + 1;
    double *tab = (double*)malloc(size*sizeof(double));
    for(int i = 0; i < size; i++) {
        tab[i] = 8.8;
    }
    return (tab - i_min);
}

void my_free(double **my_tab, int i_min){
    if(my_tab == NULL || *my_tab == NULL) return; 
    free(*my_tab + i_min);
    *my_tab = NULL;
}


int main() {
    srand(time(NULL));
    //==========zadanie==========
    double *mytab = my_alloc(-2, 4);
    for(int i = -2; i < 4; i++){
        printf("[%d] = %0.1lf | adres elementu: %p\n", i, mytab[i], mytab+i);
    } 
    printf("\n");

    size_t size = 6;
    d_array_set_random(mytab-1, mytab+3, -5.0, 5.0);

    for(int i = -2; i < 4; i++){
        printf("[%d] = %0.1lf | adres elementu: %p\n", i, mytab[i], mytab+i);
    } 
    my_free(&mytab, -2);

    my_free(&mytab, -2);

    return 0;
}