
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga1.c
./a.out

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int* poisci(int* t, int* dolzina, int** konec) {
    *dolzina = 1;

    while (t[1] != 0) {
        t++;
    }

    *konec = t;

    while (t[-1] != 0) {
        t--;
        (*dolzina)++;
    }

    return t;
}

#ifndef test

int main() {
    
}

#endif
