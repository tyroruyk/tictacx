#include <stdio.h>
#include <stdlib.h>
#include "support/game.h"

#ifdef _WIN32
#include <windows.h>
#endif

char X = 'X', Y = 'Y', EMPTY = ' ';

void about();
void clear();

int main() {
    #ifdef _WIN32
        if (GetConsoleOutputCP() != 65001) {
            printf("Windows: Unicode (UTF-8) is not enabled.\n");
            return 0;
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
        printf("5. About the project\n");
        printf("6. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // input buffer flush
        clear();

        if (choice == 1) {
            printf("Press any key to start the game...");
            getchar();
            clear();

             run_game(1);
            // run 1

            printf("Press any key to return to the menu...");
            getchar();
            clear();
            continue;
        } else if (choice == 2) {
            printf("Press any key to start the game...");
            getchar();
            clear();

            // run 2

            printf("Press any key to return to the menu...");
            getchar();
            clear();
            continue;
        } else if (choice == 3) {
            printf("Press any key to start the game...");
            getchar();
            clear();

            // run 3

            printf("Press any key to return to the menu...");
            getchar();
            clear();
            continue;
        } else if (choice == 4) {
            printf("Press any key to start the game...");
            getchar();
            clear();

            // run 4

            printf("Press any key to return to the menu...");
            getchar();
            clear();
            continue;
        } else if (choice == 5) {
            about();

            getchar();
            clear();
            continue;
        } else if (choice == 6) {
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

void about() {
    printf("==== About This Project ====\n");
    printf("Tic-Tac-Toe Game\n");
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
