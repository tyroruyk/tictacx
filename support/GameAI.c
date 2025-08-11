/*
 * Authors:
  - 2524093042 – Avishek Dutta *(Lead)* mailto:avishek.dutta@example.com
  - 2524709042 – Md Ishrak Mashroor mailto: ishrak.mashroor.252@northsouth.edu
  - 2524767042 – Ashab Mahmud Raseen mailto:ashab.raseen.252@northsouth.edu
  - 2524508042 – Sneha Nandy mailto:sneha.nandy@example.com

 *
 * Group: 02
 *
 * Version: 1.2
 * Since: 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
/*
rhwe ai_move() function is used to make a random move for the AI in the Tic Tac Toe game.
It selects a random empty cell on the board and places the AI's symbol (O) there.
*/
#include "GameAI.h"
#include <unistd.h> // for sleep() function

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
