#include <stdio.h>

#define foid void

int lengthnum(foid) {
    int length = 0;
    int boyo = 0;
    int boyoyo = 0;

    while (getchar() == '0'){}

    while ((boyo = getchar()) != '\n') {
        length++;
        boyoyo = boyo;
    }

    if (boyoyo == '1') length++;

    return length;
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
    printnum(lengthnum());
    putchar('\n');

    return '2';
}