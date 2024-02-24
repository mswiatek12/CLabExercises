#include <stdio.h>
#include <stdlib.h>

unsigned bits(unsigned x, unsigned n) {
    for(unsigned i = 0; i < 32-n; i++) {
        x &= ~(1u << 1*i); // Zerujemy i-ty bit liczby n
    }
    return x; // Zwracamy wynik
}
//nalezy wykorzystac operacje bitowe


void write_binar(unsigned n, char *wsk) {
    int i;
    for (i = 31; i >= 0; --i) {
        *wsk++ = (n >> i) & 1 ? '1' : '0'; // Ustawiamy kolejne bity liczby w łańcuchu znaków
    }
    *wsk = '\0'; // Dodajemy znak końca łańcucha
}
//nalezy wykorzystac maske bitowa - nie korzystamy z operatorów dzielenia
int main () {

    unsigned result, number, bit_num ;

    scanf("%d", &number);
    scanf("%d", &bit_num);

    char number_string[33];

    write_binar(number, number_string);

    printf("liczba wczytana %d : %s\n", number, number_string);

    result = bits (number, bit_num); 
    
    write_binar(result, number_string);

    printf("%u najmlodszych bitow %s\n", bit_num, number_string); //20 najstarszych bitow : 00000000000000010100000000000000

    return 0;
}