#include "game.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>


void runIntelligentAI(GameState *state) {
    // Implement the intelligent AI logic here
    // This could involve checking for winning moves, blocking opponent moves, etc.
    int i, j;
    char ai = state->currentPlayer;
    char human = (ai == 'X') ? 'O' : 'X';

    // 1. Check for a winning move
    for (i = 0; i < state->boardSize; i++) {
      for (j = 0; j < state->boardSize; j++) {
        if (state->board[i][j] == ' ') {
          state->board[i][j] = ai;
          if (checkWin(state, ai)) {
            return;
          }
          state->board[i][j] = ' ';
        }
      }
    }

    // 2. Block human's winning move
    for (i = 0; i < state->boardSize; i++) {
      for (j = 0; j < state->boardSize; j++) {
        if (state->board[i][j] == ' ') {
          state->board[i][j] = human;
          if (checkWin(state, human)) {
            state->board[i][j] = ai;
            return;
          }
          state->board[i][j] = ' ';
        }
      }
    }

    // 3. Take center if available
    int center = state->boardSize / 2;
    if (state->board[center][center] == ' ') {
      state->board[center][center] = ai;
      return;
    }

    // 4. Take a corner if available
    int corners[4][2] = {{0,0}, {0,state->boardSize-1}, {state->boardSize-1,0}, {state->boardSize-1,state->boardSize-1}};
    for (i = 0; i < 4; i++) {
      int x = corners[i][0], y = corners[i][1];
      if (state->board[x][y] == ' ') {
        state->board[x][y] = ai;
        return;
      }
    }

    // 5. Take any available spot
    for (i = 0; i < state->boardSize; i++) {
      for (j = 0; j < state->boardSize; j++) {
        if (state->board[i][j] == ' ') {
          state->board[i][j] = ai;
          return;
        }
      }
    }
    
} 