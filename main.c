/*
 * Authors:
  - 2524093042 – Avishek Dutta *(Lead)* mailto:avishek.dutta@example.com
  - 2524709042 – Md Ishrak Mashroor mailto: ishrak.mashroor.252@northsouth.edu
  - 2524767042 – Ashab Mahmud Raseen mailto:ashab.raseen@example.com
  - 2524508042 – Sneha Nandy mailto:sneha.nandy@example.com

 *
 * Group: 02
 *
 * Version: 7.1
 * Since: 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include "support/game.h"
#include "support/GameAI.h"

#ifdef _WIN32 // Windows
#include <windows.h> // For Windows console functions
#endif  // _WIN32 ifdef

char X = 'X', Y = 'Y', EMPTY = ' ';

void instructions();
void about();
void clear();

int main() {
    #ifdef _WIN32 // preprocessor directive for Windows
        // Check if the console supports UTF-8 
        if (GetConsoleOutputCP() != 65001) {  
            // printf("Windows: Unicode (UTF-8) is not enabled.\n");
            // return 0;
            system("chcp 65001");  // runs this code to enable UTF-8 in the console (in this case - windows powershell)
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
    printf("Welcome to \033[31mTicTacX!\033[0m\n");  // ANSI escape codes for colored text, in this case RED 

    while (1) {  // while true
        int choice;

        // this segment of code is for the main menu and allows the player to visualize the choices to be made and how

        printf("1. Human vs Human\n");
        printf("2. Human vs AI\n");
        printf("3. How to play the game\n");
        printf("4. About the project\n");
        printf("5. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);  // read the choice from the player 
        while (getchar() != '\n'); // input buffer flush, escape sequence to clear the input buffer 
        clear();

        /*
        this segment of the coe allows the program to work 
        based on the the whether the player chooses to play against another human,
        play against the AI, or watch the AI play against itself.

        after each choice, the run_game() function is called from game.h
        which handles the game logic for the selected mode.

        for choices 5, 6, 7
        the instructions() and about() functions are called to display the instructions
        and information about the project, respectively.
        */

        if (choice == 1) {
            printf("Press any key to start the game..."); // similar to the previous segment, this allows the player to start the game
            getchar(); 
            clear();

            run_game(1); // run game @ mode == 1  [ refer to game.c for reference]

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
            instructions();

            getchar();
            clear();
            continue;
        } else if (choice == 4) {
            about();

            getchar();
            clear();
            continue;
        } else if (choice == 5) {
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
