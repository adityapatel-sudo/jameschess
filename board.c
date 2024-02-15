#include "run.h"
#include "board.h"
#include "minimax.h"
#include <stdio.h>


char board[8][8];

// Other board manipulation functions...

// Global variables (if needed)
char board[8][8];

// Function implementations
void initialize_board() {
    // Initialize the board with starting positions of pieces
}

void print_board() {
    // Print the current state of the board
}

int is_move_valid(int row_from, int col_from, int row_to, int col_to) {
    // Check if the move is valid
    return row_from + col_from + row_to  + col_to;
}

void make_move(int row_from, int col_from, int row_to, int col_to) {
    // Make the move on the board
}