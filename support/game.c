#include "game.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

//extern char X, O, EMPTY;

void win_message(char board[3][3], char player);

void run_game(int mode) {
    char board[3][3] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };
    char current_player = X;
    int turn = 0;
    int row, col;

    if (mode == 1) {
        while (1) {
            print_board(board);
            printf("Player \033[33m%c\033[0m\'s turn. Enter your move: ", current_player);

            if (scanf("%d %d", &row, &col) != 2) {
                while (getchar() != '\n');
                system("clear || cls");
                printf("Invalid input. Please enter two numbers.\n");
                continue;
            }
            while (getchar() != '\n');

            if (row < 1 || row > 3 || col < 1 || col > 3) {
                system("clear || cls");
                printf("Row and column must be between 1 and 3.\n");
                continue;
            }

            row--; col--;

            if (board[row][col] != EMPTY) {
                system("clear || cls");
                printf("Cell is already taken!\n");
                continue;
            }

            system("clear || cls");

            board[row][col] = current_player;
            turn++;

            for (int i = 0; i < 3; i++) {
                if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                    win_message(board, current_player);
                    return;
                }
                if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                    win_message(board, current_player);
                    return;
                }
            }

            if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                win_message(board, current_player);
                return;
            }
            if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                win_message(board, current_player);
                return;
            }

            if (current_player == X) current_player = O;
            else current_player = X;

            if (turn == 9) {
                system("clear || cls");
                print_board(board);
                printf("It's a draw!\n");
                break;
            }
        }
    } else if (mode == 2) {
        printf("Coming soon! - Easy AI\n");
    } else if (mode == 3) {
        printf("Coming soon! - Hard AI\n");
    } else if (mode == 4) {
        printf("Coming soon! - AI vs AI\n");
    } else {
        return;
    }
}

void win_message(char board[3][3], char player) {
    print_board(board);
    printf("\033[32mPlayer %c wins!\033[0m\n", player);
}
