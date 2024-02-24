#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_d(double A_1[][4], int lines) {
    for(int i = 0; i < lines; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%0.1lf ", A_1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double suma(double *abc, int rows) {
    double suma = 0.0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < 4; j++) {
            suma += *(abc + i * 4 + j);
        }
    }
    return suma;
}

int main() {
    srand(time(NULL));
    double abc[5][4] = {0};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            abc[i][j] = rand() % 21 - 10;
        }
    }
    wypisz_d(abc, 5);

    double suma_all = suma(*abc, 5);
    double suma1 = suma(*abc, 3) - abc[2][2] - abc[2][3];
    double suma2 = suma(*(abc + 2), 3) - abc[2][0] - abc[2][1];

    printf("suma calkowita: (%0.1lf)\nsuma 1 polowy: (%0.1lf)\nsuma 2 polowy: (%0.1lf)\n", suma_all, suma1, suma2);

    return 0;
}

