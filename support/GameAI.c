#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

// Function to make a random valid move for AI
void ai_move(char board[3][3]) {
    int row, col;
    srand(time(NULL));

    while (1) {
        row = rand() % 3;
        col = rand() % 3;
        if (board[row][col] == EMPTY) {
            board[row][col] = O;  // Computer is always O
            printf("Computer played at: %d %d\n", row + 1, col + 1);
            break;
        }
    }
}
