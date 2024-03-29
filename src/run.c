#include "run.h"
#include "board.h"
#include "minimax.h"
#include <stdio.h>

char extraboard[8][8];

int main() {
    initialize_board_custom(extraboard);
    extraboard[2][1] = 'a';
    int metaData = 0;
    initMetaData(&metaData);

    edit_boardxy(extraboard, 6, 3, 'K');
    print_board(extraboard); 

    MoveNode *moves = makeMoveNode(-1, -1, -1, -1);
    get_king_moves(moves, extraboard, 0,4);
    printMoveNodes(moves);
    return 0;
}