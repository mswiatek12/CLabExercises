#include <stdio.h>
#include <stdlib.h>

void wypelnij(float A_1[][6], int lines){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < 6; j++) {
            *(*(A_1+i)+j) = -1.5 + 0.4 + 0.4*i + 0.4*j + i*5*0.4 - 0.4;
        }
    }
}

void wypisz_d(float A_1[][6], int lines){
    for(int i = 0; i < lines; i++){
        printf("\n");
        for(int j = 0; j < 6; j++) {
            printf("%0.1lf ", *(*(A_1+i)+j));
        }
    }
    printf("\n");
}

int main() {
    float A_1[8][6] = {0};
    float A_2[10][6] = {0};
    wypelnij(A_1, 8);
    wypelnij(A_2, 10);
    printf("tab 1:\n");
    wypisz_d(A_1, 8);
    printf("tab 2:\n");
    wypisz_d(A_2, 10);

    return 0;
}