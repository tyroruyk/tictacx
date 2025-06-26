#include <stdio.h>
#include <stdlib.h>
#include "support/game.h"

#ifdef _WIN32
#include <windows.h>
#endif

char X = 'X', Y = 'Y', EMPTY = ' ';

void instructions();
void about();
void clear();

int main() {
    #ifdef _WIN32
        if (GetConsoleOutputCP() != 65001) {
            // printf("Windows: Unicode (UTF-8) is not enabled.\n");
            // return 0;
            system("chcp 65001");
        }
    #elif __linux__
        char *lang = getenv("LANG");
        if (!(lang && strstr(lang, "UTF-8"))) {
            printf("Linux: Unicode (UTF-8) not enabled\n");
            return 0;
        }
    #elif __APPLE__
        char *lang = getenv("LANG");
        if (!(lang && strstr(lang, "UTF-8"))) {
            printf("macOS: Unicode (UTF-8) not enabled\n");
            return 0;
        }
    #else
        printf("Unknown OS: Cannot check Unicode (UTF-8) support\n");
        return 0;
    #endif
    
    clear();
    printf("Welcome to \033[31mTicTacX!\033[0m\n");

    while (1) {
        int choice;
        printf("1. Human vs Human (Multiplayer)\n");
        printf("2. Human vs AI (Easy)\n");
        printf("3. Human vs AI (Hard)\n");
        printf("4. AI vs AI (Gameplay)\n");
        printf("5. How to play the game\n");
        printf("6. About the project\n");
        printf("7. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // input buffer flush
        clear();

        if (choice == 1) {
            printf("Press any key to start the game...");
            getchar();
            clear();

            run_game(1);

            printf("Press any key to return to the menu...");
            getchar();
            clear();
            continue;
        } else if (choice == 2) {
            printf("Press any key to start the game...");
            getchar();
            clear();

            run_game(2);

            printf("Press any key to return to the menu...");
            getchar();
            clear();
            continue;
        } else if (choice == 3) {
            printf("Press any key to start the game...");
            getchar();
            clear();

            run_game(3);

            printf("Press any key to return to the menu...");
            getchar();
            clear();
            continue;
        } else if (choice == 4) {
            printf("Press any key to start the game...");
            getchar();
            clear();

            run_game(4);

            printf("Press any key to return to the menu...");
            getchar();
            clear();
            continue;
        } else if (choice == 5) {
            instructions();

            getchar();
            clear();
            continue;
        } else if (choice == 6) {
            about();

            getchar();
            clear();
            continue;
        } else if (choice == 7) {
            break;
        } else {
            printf("Enter a valid choice!\n");
            
            printf("Press any key to return to the menu...");
            getchar();
            clear();
            continue;
        }
    }

    printf("Thanks for playing \033[31mTicTacX!\033[0m\n");
    printf("Press any key to exit...");
    getchar();

    return 0;
}

void instructions() {
    printf("==== How to Play TicTacX ====\n");
    printf("TicTacX is a classic Tic-Tac-Toe game for two players or vs AI.\n\n");
    printf("Game Board:\n");
    printf(" - The board is a 3x3 grid. Rows and columns are numbered 1 to 3.\n");
    printf(" - Each cell can be empty, 'X', or 'O'.\n\n");
    printf("How to Play:\n");
    printf("1. Players take turns to place their symbol (X or O) on the board.\n");
    printf("2. On your turn, enter the row and column numbers (e.g., 2 3 for row 2, column 3).\n");
    printf("3. The first player to get three of their symbols in a row (horizontally, vertically, or diagonally) wins.\n");
    printf("4. If all cells are filled and no player has three in a row, the game is a draw.\n");
    printf("\nTips:\n");
    printf(" - Enter valid row and column numbers (1-3).\n");
    printf(" - You cannot place your symbol in a cell that is already taken.\n");
    printf("\nPress any key to return to the menu...");
}

void about() {
    printf("==== About This Project ====\n");
    printf("\033[31mTicTacX\033[0m - A Classic Tic-Tac-Toe Game!\n");
    printf("Developed by Group 2 for CSE115\n");
    printf("Instructor: Mohammad Shifat-E-Rabbi\n");
    printf("\n");
    printf("Features:\n");
    printf("- Player vs Player mode\n");
    printf("- Player vs AI (Easy) mode\n");
    printf("- Planned: Player vs AI (Hard), AI vs AI modes\n");
    printf("\n");
    printf("Group Members:\n");
    printf("- Avishek Dutta (Lead)\n");
    printf("- Md Ishrak Mashroor\n");
    printf("- Ashab Mahmud Raseen\n");
    printf("- Sneha Nandy\n");
    printf("\n");
    printf("GitHub Repository: https://github.com/tyroruyk/tictacx\n");
    printf("\nPress any key to return to the menu...");
}

void clear() {
    system("clear || cls");
}
