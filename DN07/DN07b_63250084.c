#include <stdio.h>
#include <stdlib.h>

void writecombos(char** array, char* buffer, int len, int level) {
    if (level == len) {
        buffer[level] = '\0';
        printf("%s\n", buffer);
        return;
    }

    for (int i = 0; array[level][i] != '\0'; i++) {
        buffer[level] = array[level][i];
        writecombos(array, buffer, len, level + 1);
    }
}

int main() {
    int num = 0;
    scanf("%d", &num);

    char** array = (char**) calloc(num, sizeof(char*));
    char* buffer = (char*) calloc(num + 1, sizeof(char));
    for (int i = 0; i < num; i++) buffer[i] = '.';

    for (int i = 0; i < num; i++) {
        array[i] = (char*) calloc(43, sizeof(char));
        char temp = 0;
        scanf(" %c", &temp);
        for (int j = 0; temp != '\n' && j < 42; j++) {
            array[i][j] = temp;
            scanf("%c", &temp);
        }
    }

    writecombos(array, buffer, num, 0);

    for (int i = 0; i < num; i++) free(array[i]);
    free(array);
    free(buffer);

    return 'combos';
}