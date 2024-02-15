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
    // Capital means white
    // Initialize the white pieces
    board[0][0] = 'R'; // 'R' for rook
    board[0][1] = 'N'; // 'N' for knight
    board[0][2] = 'B'; // 'B' for bishop
    board[0][3] = 'Q'; // 'Q' for queen
    board[0][4] = 'K'; // 'K' for king
    board[0][5] = 'B'; 
    board[0][6] = 'N'; 
    board[0][7] = 'R'; 
    for (int i = 0; i < 8; ++i) {
        board[1][i] = 'P'; // 'P' for pawn
    }

    // Initialize the empty squares
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = ' '; // Empty square represented by space
        }
    }

    // Initialize the black pieces (mirrored to the white pieces)
    for (int i = 0; i < 8; ++i) {
        board[7][i] = board[0][i] + 32; // Convert uppercase to lowercase for black pieces
        board[6][i] = 'P' + 32; // 'P' for pawn, converted to lowercase
    }
}

void print_board() {
    // Print the horizontal line
    printf("  -----------------\n");
    // Loop through each row
    for (int i = 0; i < 8; ++i) {
        // Print the row number
        printf("%d| ", 8 - i);
        // Loop through each column
        for (int j = 0; j < 8; ++j) {
            // Print the piece or empty space
            printf("%c ", board[7-i][j]);
        }
        // Move to the next row
        printf("|\n");
    }
    // Print the horizontal line
    printf("  -----------------\n");
    // Print the column labels (letters)
    printf("   a b c d e f g h\n");

}

/**
 * @brief checks if a move is valid
 * 
 * @return int 0 if valid,
 *         1 if not piece,
 *         2 if move not valid for piece,
 *         3 if move not allowed because in check after
 */
int is_move_valid(int row_from, int col_from, int row_to, int col_to) {

    char piece = board[row_from][col_from];
    
    return row_from + col_from + row_to  + col_to;
}

void make_move(int row_from, int col_from, int row_to, int col_to) {
    // Make the move on the board
}