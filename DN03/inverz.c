
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c inverz.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "inverz.h"

long inverz(long x, long a, long b) {
    long mid = (a + b) / 2;
    long upper = b;
    long lower = a;

    while (1) {
        if (f(mid) >= x) {
            upper = mid;
        } else {
            lower = mid + 1;
        }
        mid = (lower + upper) / 2;

        if (f(mid) == x) {
            return mid;
        }
    }
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.