
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

Vozlisce* zdesetkaj(Vozlisce* zacetek, int k) {
    Vozlisce* next;
    Vozlisce* this = zacetek;

    for (int i = 1; i < k; i++) {
        if (this == NULL) return NULL;
        next = this->naslednje;
        free(this);
        this = next;
    }

    this->naslednje = zdesetkaj(this->naslednje, k);

    return this;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
