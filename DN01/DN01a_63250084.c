#include <stdio.h>

#define foid void

int readnum(foid) {
    int num = 0;
    int numTemp = 0;
    int negative = 0;
    int fart = 0;
    while((fart = numTemp = getchar()) != ' ' && fart != '\n') {
        if (numTemp == '-') {
            negative = 1;
            continue;
        }

        //printf("I just read %d", numTemp);

        num *= 10;
        num += numTemp - '0';
    }

    return negative ? -num : num;
}

foid printnum(int num) {
    if (num < 0) {
        putchar('-');
        num = -num;
    }

    if (num == 0) {
        putchar('0');
        return;
    }

    int numstarted = 0;

    for (int i = 1e9; i > 0; i /= 10) {
        int numTemp = num;

        if (numstarted) {
            numTemp /= i;
            putchar(numTemp + '0');
            
            num -= numTemp * i;
        } else if (numTemp / i != 0) {
            numstarted = 1;
            numTemp /= i;
            putchar(numTemp + '0');

            num -= numTemp * i;
        }

        //printf("In this run, num was %d, while numTemp was %d\n", num, numTemp);
    }

    //putchar(num + '0');
}

int main() {
    int num1 = readnum();
    int num2 = readnum();

    //printf("Nums are %d and %d\n", num1, num2);

    printnum(num1 + num2);
    putchar('\n');

    return '+';
}