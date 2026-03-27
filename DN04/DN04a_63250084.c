#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    
    int k = n;

    int* arejena = (int*) malloc(n * sizeof(int));
    int* arejdva = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", arejdva + i);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", arejena + i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arejdva[(i + j) % n] != arejena[j]) {
                goto jebote;
            }
        }
        if (i < k) k = i;
        jebote:
    }

    printf("%d\n", k);
}
