#include <stdio.h>
#include <stdlib.h>

int issorted(int* array, int len) {
    for (int i = 1; i < len; i++) {
        if (array[i] < array[i-1]) return 0;
    }

    return 1;
}

void swapchunk(int* array, int indexa, int indexb, int chunk) {
    for (int i = 0; i < chunk; i++) {
        int temp = array[indexa+i];
        array[indexa+i] = array[indexb+i];
        array[indexb+i] = temp;
    }
}

int getsorts(int* array, int len, int chunk, int swaplimit, int successes) {
    successes += issorted(array, len);
    if (swaplimit == 0) return successes;

    int sorts = 0;

    for (int i = 0; i <= len - 2*chunk; i++) {
        for (int j = i + chunk; j <= len - chunk; j++) {
            swapchunk(array, i, j, chunk);
            //printf("%d <--> %d\n", i, j);
            sorts += getsorts(array, len, chunk, swaplimit - 1, 0) + successes;
            swapchunk(array, i, j, chunk);
        }
    }

    return sorts;
}

int main() {
    int n, k, r;
    scanf("%d %d %d", &n, &k, &r);

    int* array = (int*) calloc(10, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", array + i);
    }

    int sorts = getsorts(array, n, r, k, 0);

    printf("%d\n", sorts);
    return 'c';
}