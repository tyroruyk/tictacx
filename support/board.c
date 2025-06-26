#include <stdio.h>
#include "board.h"

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

void print_cell(char c) {
    if (c == X) printf(RED " %c " RESET, c);
    else if (c == O) printf(BLUE " %c " RESET, c);
    else printf("   ");
}

void print_board(char board[3][3]) {
    printf("    1   2   3\n");
    printf("  ╔═══╦═══╦═══╗\n");

    for (int i = 0; i < 3; i++) {
        printf("%d ║", i + 1);
        for (int j = 0; j < 3; j++) {
            print_cell(board[i][j]);
            printf("║");
        }
        printf("\n");

        if (i < 2) printf("  ╠═══╬═══╬═══╣\n");
    }

    printf("  ╚═══╩═══╩═══╝\n");
}
