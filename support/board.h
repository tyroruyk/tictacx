/*
 * Authors:
  - 2524093042 – Avishek Dutta *(Lead)* mailto:avishek.dutta@example.com
  - 2524709042 – Md Ishrak Mashroor mailto: ishrak.mashroor.252@northsouth.edu
  - 2524767042 – Ashab Mahmud Raseen mailto:ashab.raseen@example.com
  - 2524508042 – Sneha Nandy mailto:sneha.nandy@example.com

 *
 * Group: 02
 *
 * Version: 1.0
 * Since: 1.0
 */
#ifndef BOARD_H // include guard to prevent multiple inclusions
#define BOARD_H // include guard

#define RESET "\033[0m" // ANSI escape code to reset text formatting
#define RED "\033[31m" // ANSI escape code for red text
#define BLUE "\033[34m" // ANSI escape code for blue text

#define X 'X' // define X as a character
#define O 'O' // define O as a character
#define EMPTY ' ' // define EMPTY as a character

void print_board(char board[3][3]); // call print_board() from board.c function to print the board

#endif
