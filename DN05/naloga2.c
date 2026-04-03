
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga2.c
./a.out


*/

#include <stdio.h>

#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    int* t = *a;
    *a = *b;
    *b = t;
}

void uredi(int** a, int** b, int** c) {
    if (*a > *b && *a > *c && *b > *c) {
        zamenjaj(a, c);
    } else if (*a > *b && *a > *c && *c > *b) {
        zamenjaj(a, b);
        zamenjaj(b, c);
    } else if (*b > *a && *b > *c && *a > *c) {
        zamenjaj(b, c);
        zamenjaj(a, b);
    } else if (*b > *a && *b > *c && *c > *a) {
        zamenjaj(b, c);
    } else if (*c > *a && *c > *b && *a > *b) {
        zamenjaj(a, b);
    }
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
