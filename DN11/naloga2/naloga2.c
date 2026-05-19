
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"
// Začeto 19:45
// Zaključeno 20:11

int izpisiA(A*, char*);
int izpisiB(B*, char*);

int izpisiC(C* c, char* cilj) {
    long ciljStart = (long)cilj;

    if (c == NULL) {
        sprintf(cilj, "NULL");
        return 4;
    }

    cilj += sprintf(cilj, "{%s, ", c->r == true ? "true" : "false");
    cilj += izpisiA(c->a, cilj);
    cilj += sprintf(cilj, ", ");
    cilj += izpisiB(c->b, cilj);
    cilj += sprintf(cilj, "}");

    return (int)((long)cilj - ciljStart);
}

int izpisiB(B* b, char* cilj) {
    long ciljStart = (long) cilj;

    if (b == NULL) {
        sprintf(cilj, "NULL");
        return 4;
    }

    cilj += sprintf(cilj, "{%s, ", b->q);
    cilj += izpisiC(b->c, cilj);
    cilj += sprintf(cilj, "}");

    return (int)((long)cilj - ciljStart);
}

int izpisiA(A* a, char* cilj) {
    long ciljStart = (long) cilj;

    if (a == NULL) {
        sprintf(cilj, "NULL");
        return 4;
    }

    cilj += sprintf(cilj, "{%d, ", a->p);
    cilj += izpisiB(a->b, cilj);
    cilj += sprintf(cilj, "}");

    return (int)((long)cilj - ciljStart);
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
