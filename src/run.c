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
    printf("%d\n",enPassantAvailable(metaData));
    printf("%d\n",blackKingCastleAvailable(metaData));
    printf("%d\n",whiteKingCastleAvailable(metaData));

    printf("suck my dick");
    return 0;
}