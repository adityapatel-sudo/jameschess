#include "run.h"
#include "board.h"
#include "minimax.h"
#include <stdio.h>




// Function implementations
int minimax(int depth, int alpha, int beta, int is_maximizing) {
    // Implementation of minimax algorithm with alpha-beta pruning
    printf("%d %d\n", depth, is_move_valid(1,2,3,4));
    return 0;
}

int evaluate_position(char board[]) {
    // Evaluation function to assign a numerical value to the position
    return 0;
}
