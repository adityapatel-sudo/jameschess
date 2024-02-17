#include "run.h"
#include "board.h"
#include "minimax.h"
#include <stdio.h>

extern char board[8][8];
char extraboard[8][8];

int main() {
    initialize_board();
    print_board(board);
    initialize_board_custom(extraboard);
    print_board(extraboard);
    return 0;
}