#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i_rand(int min, int max) {
    return rand() % (max-min+1) + min;
}

double d_rand(double min, double max) {
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}




int main() {
    int a;
    double b;

    srand(time(0)); // inicjalizacja losowego ziarna

    a = i_rand(-15, 20);
    b = d_rand(-15.0, 20.0);

    printf("wylosowano: %d oraz %g.\n", a, b);

    return 0;
}