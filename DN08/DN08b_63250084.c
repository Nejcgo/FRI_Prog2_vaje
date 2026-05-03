#include <stdio.h>
#include <stdlib.h>

int turnarray[20];

int canwhitewin(int n, int k) {
    if (n % (k + 1) == 0) return 0;
    return 1;
}

void printmoves(int depth) {
    printf("%d", turnarray[0]);

    for (int i = 1; i <= depth; i++) {
        if (i % 2 == 0) {
            printf(" -> %d", turnarray[i]);
        } else {
            printf(" -> [%d]", turnarray[i]);
        }
    }

    printf("\n");
}

void putmove(int n, int k, int depth) {
    if (n == 0) {
        printmoves(depth - 1);
        return;
    }

    if (depth % 2 == 0) {
        turnarray[depth] = n % (k + 1);
        //printf("white: %d\n", n % (k + 1));
        putmove(n - (n % (k + 1)), k, depth + 1);
    } else {
        for (int i = 1; i <= k && i <= n; i++) {
            turnarray[depth] = i;
            //printf("black: %d\n", i);
            putmove(n - i, k, depth + 1);
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    if (!canwhitewin(n, k)) {
        printf("CRNI\n");
    } else {
        putmove(n, k, 0);
    }

    return 'w';
}