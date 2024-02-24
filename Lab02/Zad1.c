#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int*b){
int temp = *a;
*a = *b;
*b = temp;
return;}

int find_min_id(int *ptr, int size) {
    int min = *ptr;
    int id = 0;
    for(int i = 0; i < size;i++){
        if(min > *(ptr+i)){
            min = *(ptr+i);
            id = i;
        }
    }
    return id;
}

int *wypisz_i(int *ptr, int size, int *tab){
    int min = *ptr;
    for(int i = 0; i < 5; i++) {
        min = *(ptr + i*10);
        for(int j = 0; j < 10; j++){
            if(min > *(ptr+10*i+j)){
                min = *(ptr+j+10*i);
            }
        }
        tab[i] = min;
    }
    printf("min[0-9] = %d, min[10-19] = %d, min[20-29] = %d, min[30-39] = %d, min[40-49] = %d\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
    return tab;
}

void sort(int *pocz, int *koniec){
    for(int *i = pocz; i < koniec; i++) {
        int size = koniec - i;
        int id = find_min_id(i, size);
        swap(i, i + id); 
    }
}
void wypisz_d(int *poczatek, int *koniec) {
    for(int *p = poczatek; p < koniec; p++)
        printf("%4d ", *p);
    printf("\n");
}

int main() {
    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
    int *tab;
    int id = find_min_id(tab_A, sizeof(tab_A)/sizeof(int));
    printf("min id = %d\n", id);
    tab = (int*)malloc(5*sizeof(int));
    tab = wypisz_i(tab_A, sizeof(tab_A)/sizeof(int), tab);
    free(tab);
    sort(tab_A, tab_A+50);
    wypisz_d(tab_A, tab_A+50);

    return 0;
}