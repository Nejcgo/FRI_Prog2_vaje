#include <stdio.h>

#define foid void

int main() {
    int num = 0;
    int state = 0; // 0 = first num | 1 = all other nums for goog start (he is also the same as mr. space, I'm too lazy) | 2 = we shraterd with a 0, waow | 3 = mr. space
    int didwefuckupyet = 0;

    while (((num = getchar()))) {
        switch (state) {
        case 0:
            if (num == '0') {
                state = 2;
            } else if (num > '0' && num <= '9') {
                state = 3;
            } else {
                didwefuckupyet = 1;
                state = 3;
            }
            break;

        case 1:
            goto mrspace; // :)
            break;

        case 2:
            if (num == ' ' || num == '\n') {
                putchar('0' + !didwefuckupyet);
                didwefuckupyet = 0;
                state = 0;
            } else {
                didwefuckupyet = 1;
            }
        break;

        case 3:
        mrspace:
            if (num == ' ' || num == '\n') {
                putchar('0' + !didwefuckupyet);
                didwefuckupyet = 0;
                state = 0;
            } else if (num < '0' || num > '9') {
                didwefuckupyet = 1;
            }
        break;
        
        default:
            putchar('u');
            putchar('p');
            putchar('s');
            break;
        } 

        if (num == 10) break;
    }

    putchar('\n');

    return '0';
}