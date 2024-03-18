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

void swap(double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}


double *min_pointer(double **tab, int size){
    double *ptr = *tab;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 7; j++){
            if(*ptr > *(*(tab+i)+j)){
                *ptr = *(*(tab+i)+j);
            }
        }
    }
    return ptr;
}

double **min_pointers_of_rows(double **tab, int size){
    double **ptr = malloc(4 * sizeof(double*));
    for(int i = 0; i < 4; i++) {
        ptr[i] = *(tab + i);
        for(int j = 0; j < (size/4); j++){
            if(*(*(ptr+i)) > *(*(tab+i)+j)){
                ptr[i] = *(tab+i)+j;
            }
        }
    }
    return ptr;
}



int main() {
    srand(time(NULL));
    double *A[4]; // Corrected to pointer array to match your function signatures
    for (int i = 0; i < 4; i++) {
        A[i] = malloc(7 * sizeof(double)); // Allocate each row
        if (!A[i]) return 1; // Check for allocation failure
    }
    d_array_set_random(*(A), *A + 7, -10, 10);
    d_array_set_random(*(A + 1), *(A + 1) + 7, -10, 10);
    d_array_set_random(*(A + 2), *(A + 2) + 7, -10, 10);
    d_array_set_random(*(A + 3), *(A + 3) + 7, -10, 10);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 7; j++){
            printf("%0.1lf\t", *(*(A+i)+j));
        }
        printf("\n");
    }
    printf("\n");
    double *drawer = min_pointer(A, 28);
    double **pointers = min_pointers_of_rows(A, 28);
    for (int i = 0; i < 4; i++) {
        printf("%p, %lf\n", pointers[i], *pointers[i]);
    }

    swap(drawer, pointers[0]);
    for (int i = 0; i < 4; i++) {
        printf("%p, %lf\n", pointers[i], *pointers[i]);
    }


    for (int i = 0; i < 4; i++) {
        free(*(A+i));
    }
    free(pointers);


    return 0;
}