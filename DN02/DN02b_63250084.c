#include <stdio.h>

#define foid void

int main() {
    int num = 0;
    int state = 0; 
    // 0 = first num 
    // 1 = mr. space
    // 2 = we shraterd with a 0, waow (could be octal, hex, or bin! That's so crazy, slime, I almost gave a shit...)
    // 3 = decimal chud (1-9)
    // 4 = octal gaygay (0-7)
    // 5 = waitin for sex (0x)
    // 6 = sex mode (0x... A-F)
    // 7 = waitin for bin (0b)
    // 8 = binman (0b... 0-1)
    
    int didwefuckupyet = 0;

    while (0);

    while (((num = getchar()))) {
        if (num == ' ' || num == '\n') {
            if (state != 0) {
                if (state == 5 || state == 7) {
                    didwefuckupyet = 1; 
                }
                putchar('0' + !didwefuckupyet);
                didwefuckupyet = 0; // :D yippie!
                state = 0;          
            }
            if (num == 10) break;
            continue;
        }

        switch (state) {
        case 0:
            if (num == '0') state = 2;
            else if (num > '0' && num <= '9') state = 3;
            else goto we_fucked_up;
            break;

        case 1:
            goto mrspace; // :)
            break;

        case 2:
            if (num == 'x') state = 5;
            else if (num == 'b') state = 7;
            else if (num >= '0' && num <= '7') state = 4;
            else goto we_fucked_up;
            break;

        case 3:
            if (num < '0' || num > '9') goto we_fucked_up;
            break;

        case 4:
            if (num < '0' || num > '7') goto we_fucked_up;
            break;

        case 5:
        case 6:
            if ((num >= '0' && num <= '9') || (num >= 'A' && num <= 'F')) {
                state = 6;
            } else {
                goto we_fucked_up;
            }
            break;

        case 7:
        case 8:
            if (num == '0' || num == '1') {
                state = 8;
            } else {
                goto we_fucked_up;
            }
            break;

        we_fucked_up:
        mrspace:
            didwefuckupyet = 1;
            state = 1;
            break;

        default:
            putchar('u'); putchar('p'); putchar('s');
            break;
        } 
    }

    putchar('\n');

    return '0';
}