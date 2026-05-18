
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int getGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a > b) {
        int t = a; a = b; b = t;
    }

    while (b != 0) { // faking REA
        int t = b;
        b = a % b;
        a = t;
    }

    return a;
}

Ulomek shorten(Ulomek a) {
    int gcd;
    if ((gcd = getGCD(a.st, a.im)) != 1) {
        a.st /= gcd;
        a.im /= gcd;
    }

    if (a.st == 0) a.im = 1;

    return a;
}

Ulomek add(Ulomek a, Ulomek b) {
    int aMult = b.im;
    int bMult = a.im;

    a.st *= aMult;
    a.im *= aMult;
    b.st *= bMult;

    return shorten((Ulomek) {a.st+b.st, a.im});
}

Ulomek sub(Ulomek a, Ulomek b) {
    return add(a, (Ulomek) {-b.st, b.im});
}

Ulomek mul(Ulomek a, Ulomek b) {
    return shorten((Ulomek) {a.st*b.st, a.im*b.im});
}

Ulomek skalarniProdukt(Tocka a, Tocka b) {
    return add(mul(a.x, b.x), mul(a.y, b.y));
}

Tocka multVectorByReal(Tocka v, Ulomek x) {
    v.x = mul(v.x, x);
    v.y = mul(v.y, x);

    return v;
}

Ulomek divide(Ulomek a, Ulomek b) {
    return shorten((Ulomek) {a.st*b.im, a.im*b.st});
}

Tocka vectorProjBOnA(Tocka a, Tocka b) {
    Ulomek adotb = skalarniProdukt(a, b);
    Ulomek adota = skalarniProdukt(a, a);

    return multVectorByReal(a, divide(adotb, adota));
}

Tocka projekcija(Tocka t, Premica p) {
    Ulomek offset = p.n;
    p.n.st = 0;
    t.y = sub(t.y, offset);
    Tocka lineVector = (Tocka) {(Ulomek) {1, 1}, p.k};

    Tocka normalizedProjection = vectorProjBOnA(lineVector, t);
    normalizedProjection.y = add(normalizedProjection.y, offset);

    return normalizedProjection;
}

#ifndef test

int main() {
    return 0;
}

#endif
