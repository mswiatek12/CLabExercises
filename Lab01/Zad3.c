#include <stdio.h>
#include <stdlib.h>

int sum(int *ptr, int size, int *min, int *max) {
    int suma = 0;
    int srednia;
    int omin;
    int omax;
    srednia = suma / size;
    for(int i = 0; i < size; i++){
        suma += *(ptr+i);
        *min = *ptr;
        *max = *ptr;
        if(*min > *(ptr+i)) {
            *min = *(ptr+i);
        }
        if(*max < *(ptr+i)) {
            *max = *(ptr+i);
        }
    }
    omin = (*min - srednia) % 1;
    omax = *max - srednia; 
    return suma;
}


int main(){


    return 0;
}