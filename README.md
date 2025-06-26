# TicTacX

Classic Tic-Tac-Toe game implemented in C as a project for the *CSE115* course. Played entirely through the command-line interface, featuring both multiplayer and AI game modes.

## About

- **Course:** CSE115 (Programming Language I)
- **Semester:** Summer 2025
- **Instructor:** Mohammad Shifat-E-Rabbi
- **Group:** 2
- **Members:**
  - 2524093042 – Avishek Dutta *(Lead)*
  - 2524709042 – Md Ishrak Mashroor
  - 2524767042 – Ashab Mahmud Raseen
  - 2524508042 – Sneha Nandy

## Game Modes

1. **Multiplayer Mode:** Two players can play against each other.
2. **AI Mode (Easy):** One player can play against a computer opponent.
3. **AI Mode (Hard):** One player can play against a more challenging computer opponent.
4. **AI vs AI Mode:** Two computer opponents play against each other.

## How to Play

1. Compile the code using a C compiler or makefile.
2. Run the executable.
3. Choose a game mode from the menu.
4. Players take turns by entering their moves in the format `row column` (e.g., `1 2` for row 1, column 2).
5. The game continues until a player wins or the board is full (draw).

## Interface and Features

- CLI-based interface using ANSI escape sequences for colors and formatting.
- Clean 3x3 grid display with real-time board updates using the `clear` command.
- Highlights player turns and win/draw results clearly.
- Input validation with helpful error messages for invalid entries or moves.
- Menu to select game modes.
- Prompts re-entry on invalid moves without breaking flow.
- Displays end-of-game messages for win or draw.
- Option to replay after each game.
- Clear instructions for controls and game rules.
- AI difficulty levels with different strategies.

## Installation

To run the game, follow these steps:
1. Clone the repository:
   ```bash
   git clone https://github.com/tyroruyk/tictacx.git
   ```
2. Navigate to the project directory:
   ```bash
   cd tictacx
    ```
3. Compile the code:
   ```bash
   make
   ```
   or
   ```bash
   mkdir build
   gcc main.c support/game.c support/board.c -o build/tictacx
   ```
4. Run the game:
   ```bash
   ./build/tictacx
   ```
5. Follow the on-screen instructions to play.

## Contributing
Contributions are welcome! If you find any bugs or have suggestions for improvements, please open an issue or submit a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details
