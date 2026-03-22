
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c tranzitivnost.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "tranzitivnost.h"

int tranzitivnost(int a, int b) {
    int transgender = 1;
    int antitransgender = 1;

    for (int x = a; x <= b; x++) {
        for (int z = a; z <= b; z++) {
            if (!f(x,z)) {
                for (int y = a; y <= b; y++) {
                    transgender = !(f(x,y) && f(y,z)) && transgender;
                }
            } else {
                for (int y = a; y <= b; y++) {
                    antitransgender = !(f(x,y) && f(y,z)) && antitransgender;
                }
            }
        }
    }

    return 4 - 2*transgender - antitransgender;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
