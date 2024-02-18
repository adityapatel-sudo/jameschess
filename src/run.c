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

    setEnPassantAvailable(&metaData);
    setEnPassantLocation(&metaData, 5, 5);
    edit_boardxy(extraboard, 4, 4, 'P');
    edit_boardxy(extraboard, 6, 4, 'P');

    print_board(extraboard); 


    setBlackKingCastleUnavailable(&metaData);
    MoveNode *moves = makeMoveNode(-1, -1, -1, -1);


    check_en_passant(moves, extraboard, 4,4,WHITE,metaData);

    printMoveNodes(moves);
    return 0;
}