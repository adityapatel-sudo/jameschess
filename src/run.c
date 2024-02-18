#include "run.h"
#include "board.h"
#include "minimax.h"
#include <stdio.h>

extern char board[8][8];
char extraboard[8][8];

int main() {
    initialize_board_custom(extraboard);
    print_board(extraboard);
    int metaData = 0;
    initMetaData(&metaData);


    setBlackKingCastleUnavailable(&metaData);
    MoveNode *moves = get_pawn_moves(extraboard,1,0,0);
    printMoveNodes(moves);
    return 0;
}