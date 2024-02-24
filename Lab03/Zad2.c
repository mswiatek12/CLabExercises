#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_i(int *tab, int size){  
    int i;
    printf("\n");
    for(i=0; i<size; i++){
        printf("%d ", *(tab+i));
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int size;

    printf("Insert the size of an array:\n");
    scanf("%d", &size);
    int *table = (int*)malloc(size*sizeof(int));

    for(int i = 0; i < size; i++){
        *(table+i) = rand() % 11-5;
    }

    int *tab1 = (int*)malloc(1*sizeof(int));
    int *tab2 = (int*)malloc(1*sizeof(int));

    int p = 0, np = 0;
    for(int i = 0; i < size; i++){
        if(((*(table+i))%2) == 0){
            p++;
            tab1 = (int*)realloc(tab1, p*sizeof(int));
            *(tab1+p-1) = *(table+i);
        }
        else {
            np++;
            tab2 = (int*)realloc(tab2, np*sizeof(int));
            *(tab2+np-1) = *(table+i);
        }
    }

    wypisz_i(table, size);
    wypisz_i(tab1, p);
    wypisz_i(tab2, np);
    free(table);
    free(tab1);
    free(tab2);

    return 0;
}