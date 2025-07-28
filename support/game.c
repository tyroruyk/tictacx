#include "game.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include "GameAI.h"


void win_message(char board[3][3], char player); // win message declaration
void clear();

void run_game(int mode) {
    char board[3][3] = { // empty game board initialization
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };
    char current_player = X; // always start with X
    int turn = 0; // turns counter
    int row, col;

    if (mode == 1) { // multiplayer
        while (1) {
            print_board(board);
            printf("\nPlayer \033[33m%c\033[0m\'s turn. Enter your move: ", current_player);

            if (scanf("%d %d", &row, &col) != 2) {
                while (getchar() != '\n'); // input buffer flush
                clear();
                printf("Invalid input. Please enter two numbers.\n");
                continue;
            }
            while (getchar() != '\n'); // input buffer flush

            // overflow handler
            if (row < 1 || row > 3 || col < 1 || col > 3) {
                clear();
                printf("Row and column must be between 1 and 3.\n");
                continue;
            }

            row--; col--;

            // double-input handler
            if (board[row][col] != EMPTY) {
                clear();
                printf("Cell is already taken!\n");
                continue;
            }

            clear();

            board[row][col] = current_player;

                                        // DEBUG: print the current state of the board
                                        // Uncomment the next line to see debug output

                                        /*
                                        printf("DEBUG: Player=%c placed at [%d][%d]\n", current_player, row, col);
                                        print_board(board);
                                        */

            turn++;

            // row and column check
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

            // diagonal checks
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

            // draw logic
            if (turn == 9) {
                clear();
                print_board(board);
                printf("It's a draw!\n");
                break;
            }
        }
    } else if (mode == 2) { // easy ai


        while(1){

        print_board(board);
        printf("\nPlayer \033[33m%c\033[0m's turn. Enter your move: ", current_player);
        if (current_player ==X){
        if (scanf("%d %d", &row, &col) != 2) {
            while (getchar() != '\n'); // input buffer flush
            clear();
            printf("Invalid input. Please enter two numbers.\n");
            continue;}
        while (getchar() != '\n'); // input buffer flush
        if(row<1 || row>3 || col<1 || col>3){
            clear();
            printf("Row and column must be between 1 and 3.\n");
            continue;
        }
        row--; col--;
            if (board[row][col] != EMPTY) {
                clear();
                printf("Cell is already taken!\n");
                continue;
            }
            board[row][col] = X;
            }
        else{ai_move(board);}   
        turn++;
        clear();


                for (int i = 0; i < 3; i++) {
            if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                clear();
                print_board(board);
                if (current_player == O)
                    printf("\n\033[32mPlayer %c (Computer) wins!\033[0m\n", current_player);
                else
                    printf("\n\033[32mPlayer %c wins!\033[0m\n", current_player);
                return;
            }
            if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                clear();
                print_board(board);
                if (current_player == O)
                    printf("\n\033[32mPlayer %c (Computer) wins!\033[0m\n", current_player);
                else
                    printf("\n\033[32mPlayer %c wins!\033[0m\n", current_player);
                return;
            }
        }

        if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            clear();
            print_board(board);
            if (current_player == O)
                printf("\n\033[32mPlayer %c (Computer) wins!\033[0m\n", current_player);
            else
                printf("\n\033[32mPlayer %c wins!\033[0m\n", current_player);
            return;
        }

        if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            clear();
            print_board(board);
            if (current_player == O)
                printf("\n\033[32mPlayer %c (Computer) wins!\033[0m\n", current_player);
            else
                printf("\n\033[32mPlayer %c wins!\033[0m\n", current_player);
            return;
        }

        if (turn == 9) {
            clear();
            print_board(board);
            printf("It's a draw!\n");
            break;
        }

        // Switch players
        current_player = (current_player == X) ? O : X;


    } }else {
        return;
    }
}

// win message definition
void win_message(char board[3][3], char player) {
    print_board(board);
    printf("\n\033[32mPlayer %c wins!\033[0m\n", player);
}
