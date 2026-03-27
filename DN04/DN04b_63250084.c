#include <stdlib.h>
#include <stdio.h>

// Gostiša je genije, a ovo je njegov zadatak DN04b_63250084.c - Broj parova

int main() {
    int numofnums; scanf("%d", &numofnums);
    int sum; scanf("%d", &sum);
    int stparov = 0;
    // 

    int* arej = (int*) malloc(numofnums * sizeof(int));

    for (int i = 0; i < numofnums; i++) {
        scanf("%d", arej + i);
    }

    for (int i = 0; i < numofnums; i++) {
        for (int j = i + 1; j < numofnums; j++) {
            if (arej[i] + arej[j] == sum) {
                stparov++;
            }
        } 
    }

    printf("%d\n", stparov);
}


