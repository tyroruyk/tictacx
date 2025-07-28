#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

// Function to make a random valid move for AI
void ai_move(char board[3][3]) {
    int row, col;
    sleep(1); // Add 1 second time buffer
    srand(time(NULL)); // Seed the random number generator

    while (1) {
        row = rand() % 3; // Random row between 0 and 2
        col = rand() % 3; // Random column between 0 and 2
        if (board[row][col] == EMPTY) {
            board[row][col] = O;  // Computer is always O
            printf("Computer played at: %d %d\n", row + 1, col + 1);
            sleep(1); // Add 1 second time buffer
            break;
        }
    }
}
