#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int suma(const int *ptr, const int size);

int main(void) {
    int tab[N];
    int *p = NULL;
    for(p = tab; p < tab + N; p++){
        *p = rand() % (35-7+1);
        printf("p[%d] = %d\n", (int)(p-tab), *p);
    }

    printf("\n");

    //oblicz rekurencyjnie sumę elementów tablicy.
int su = suma(tab, 10); //nie używaj N
printf("su=%d\n",su);
return 0;
}

    //funkcja rekurencyjna liczaca sume elementów tablicy
int suma(const int *ptr, const int size){ //nie używaj N
if (size > 0)
return *ptr + suma(ptr+1, size - 1);
    else
return 0;
}