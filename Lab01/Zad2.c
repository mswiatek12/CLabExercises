#include <stdio.h>
#include <stdlib.h>

void zamiana(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void odwroctab(int *ptr, const int size) {
    int i;
    for(i = 0; i < size/2; i++) {
        zamiana(ptr + i, ptr + size -1 - i);
    }
}

void zamientab(int *ptr1, int *ptr2, const int size){
    for(int i = 0; i < size; i++){
        zamiana(ptr1 + i, ptr2 + i);
    }
}

int main() {
    int a = 10;
    int b = 20;
    zamiana(&a, &b);
    printf("a = %d, b = %d\n", a, b);


    return 0;
}