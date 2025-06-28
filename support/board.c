#include <stdio.h>
#include "board.h"

#define RESET "\033[0m" // ANSI escape code to reset text formatting
#define RED "\033[31m" // ANSI escape code for red text
#define BLUE "\033[34m" // ansi escape code for blue text
#define WHITE "\033[37m" // ansi escape code for white text
#define BLACK_BG "\033[40m" // ANSI escape code for black background

void print_cell(char c) {
    if (c == X) printf(RED BLACK_BG " %c " RESET, c); // ANSI escape code for red text and black background
    else if (c == O) printf(BLUE BLACK_BG " %c " RESET, c); // ANSI escape code for blue text and black background
    else printf(BLACK_BG "   " RESET); // ANSI escape code for black background with no text
}

/*
the print_board() function prints the Tic Tac Toe board in a formatted way.
It uses ANSI escape codes to color the text and format the output.
*/

void print_board(char board[3][3]) {
    printf("    1   2   3\n");
    printf("  " BLACK_BG WHITE "╔═══╦═══╦═══╗\n" RESET);

    for (int i = 0; i < 3; i++) {
        printf("%d " BLACK_BG WHITE "║" RESET, i + 1);
        for (int j = 0; j < 3; j++) {
            print_cell(board[i][j]);
            printf(BLACK_BG WHITE "║" RESET);
        }
        printf("\n");

        if (i < 2) printf("  " BLACK_BG WHITE "╠═══╬═══╬═══╣\n" RESET);
    }

    printf("  " BLACK_BG WHITE "╚═══╩═══╩═══╝\n" RESET);
}
