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
#ifndef BOARD_H
#define BOARD_H

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

#define X 'X'
#define O 'O'
#define EMPTY ' '

void print_board(char board[3][3]);

#endif
