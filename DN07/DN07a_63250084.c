#include <stdio.h>
#include <stdlib.h>

int getdepthnode(int** array, int len, int node) {
    if (node == 0) return 0;

    int depth = 0;
    int parent = 0;
    for (int i = 0; i < len; i++) {
        if (array[i][0] == node || array[i][1] == node) {
            parent = i;
            //printf("node: %d, parent: %d\n", node, parent);
            break;
        }
    }

    return getdepthnode(array, len, parent) + 1;
}

int main() {
    int num = 0;
    scanf("%d", &num);

    int** array = (int**) calloc(num, sizeof(int*));

    for (int i = 0; i < num; i++) {
        array[i] = (int*) calloc(2, sizeof(int));
        scanf("%d %d", array[i], array[i] + 1);
    }

    /*for (int i = 0; i < num; i++) {
        printf("Node: %d has children %d and %d\n", i, array[i][0], array[i][1]);
    }*/

    int max = 0;
    for (int i = 0; i <= num; i++) {
        int temp = getdepthnode(array, num, i);
        max = temp > max ? temp : max;
    }

    printf("%d\n", max);

    for (int i = 0; i < num; i++) free(array[i]);
    free(array);

    return 'tree';
}