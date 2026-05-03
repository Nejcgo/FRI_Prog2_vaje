#include <stdio.h>
#include <stdlib.h>

#define width 8
#define height 8

char board[height][width + 1];
int count = 0;

int jump(int col, int row, int dir) {
    int dcol[8] = {2, 1, -1, -2, -2, -1,  1,  2};
    int drow[8] = {1, 2,  2,  1, -1, -2, -2, -1};

    if (col + dcol[dir] < 0 || col + dcol[dir] > width - 1) return -1;
    if (row + drow[dir] < 0 || row + drow[dir] > width - 1) return -1;

    return (col + dcol[dir]) + width * (row + drow[dir]);
}

int solve(int col, int row) {
    count++;

    printf("%d %d -- %d\n", col, row, count);
    printf("%s\n\n", (char*) board);

    if (row == height) return 0;                // stop
    if (col == width) return solve(0, row + 1); // preskok v novo vrstico

    if (board[col][row] != '.') return solve(col + 1, row); // upsi, neprazno polje! :3c

    int firstoption = solve(col + 1, row); // eh, ne ga dat ...

    board[col][row] = 'N'; // ampak, kaj pa, če ga damo?
    for (int i = 0; i < width; i++) {
        int jmp = jump(col, row, i);
        if (jmp == -1) continue;

        board[jmp%width][jmp/width] = 'X';
    }

    int secondoption = solve(col + 1, row) + 1;

    // dajmo spucat za sabo
    

    return firstoption > secondoption ? firstoption : secondoption;
}

int main() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = '.';
        }
        board[i][width] = '\n';
    }
    board[height - 1][width] = '\n';

    int val = solve(0, 0);

    printf("%d\n", val);
    printf("%s\n", (char*) board);
}

