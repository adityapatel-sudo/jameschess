#include "run.h"
#include "board.h"
#include "minimax.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


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

// Function implementations
void initialize_board_custom(char board[8][8]) {
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

void print_board(char brd[8][8]) {
    // Print the horizontal line
    printf("  -----------------\n");
    // Loop through each row
    for (int i = 0; i < 8; ++i) {
        // Print the row number
        printf("%d| ", 8 - i);
        // Loop through each column
        for (int j = 0; j < 8; ++j) {
            // Print the piece or empty space
            printf("%c ", brd[7-i][j]);
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
 * @brief edits board given x, y, and val
 */
void edit_boardxy(char brd[8][8], int x, int y, char val) {
    brd[y][x] = val;
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
struct MoveNode* get_moves(char brd[8][8], int player_turn) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            
        }
    }
}

/**
 * next 10 functions explained here:
 * 
 * will all be stored in one integer to save some space
 * 
 * digit 0 from right will be 0 if en passant not available, 1 if available
 * digit 1 from right will be row of the en passant destination
 * digit 2 from right will be col of the en passant destination
 * digit 3 from right will be 0 if white king can castle, 1 if not
 * digit 4 from right will be 0 if black king can castle, 1 if not
 * more metadata can be stored in digits 5,6,7
*/
//returns 0 if en passant not available, 1 if available
int enPassantAvailable(int metaData) {
    return metaData % 2; 
}
int enPassantPawnRow(int metaData) {
    return (metaData/10) % 10;
}
int enPassantPawnCol(int metaData) {
    return (metaData/100) % 10;
}
// returns will be 0 if white king can castle, 1 if not
int whiteKingCastleAvailable(int metaData) {
    return (metaData/1000) % 2;
}
int blackKingCastleAvailable(int metaData) {
    return ((metaData)/10000) % 2;
}
void setEnPassantAvailable(int *metaData) {
    *metaData = ((*metaData/10)*10)+1;
}
void setEnPassantUnavailable(int *metaData) {
    *metaData = ((*metaData/10)*10);
}
void setEnPassantLocation(int *metadata, int row, int col) {
    setEnPassantPawnRow(metadata, row);
    setEnPassantPawnCol(metadata, col);
}
void setEnPassantPawnRow(int *metaData, int row) {
    int temp = *metaData % 10;
    *metaData = (*metaData/100)*100 + (row * 10) + temp;
}
void setEnPassantPawnCol(int *metaData, int col) {
    int temp = *metaData % 100;
    *metaData = (*metaData/1000)*1000 + (col * 100) + temp;
}
void setWhiteKingCastleAvailable(int *metaData) {
    int temp = *metaData % 1000;
    *metaData = (*metaData/10000)*10000 + 1000 + temp;
}
void setBlackKingCastleAvailable(int *metaData) {
    int temp = *metaData % 10000;
    *metaData = (*metaData/100000)*100000 + 10000 + temp;
}
void setWhiteKingCastleUnavailable(int *metaData) {
    int temp = *metaData % 1000;
    *metaData = (*metaData/10000)*10000 + temp;
}
void setBlackKingCastleUnavailable(int *metaData) {
    int temp = *metaData % 10000;
    *metaData = (*metaData/100000)*100000 + temp;
}
void initMetaData(int *metaData) {
    setWhiteKingCastleAvailable(metaData);
    setBlackKingCastleAvailable(metaData);
    setEnPassantUnavailable(metaData);
}
void printMetaData(int metaData){
    printf("%d\n",enPassantAvailable(metaData));
    printf("%d\n",blackKingCastleAvailable(metaData));
    printf("%d\n",whiteKingCastleAvailable(metaData));
}

/*
PIECE MOVE FUNCTIONS
*/

void get_pawn_moves(MoveNode* head, char board[8][8], int row_from, int col_from, int player_turn) {
    if (player_turn == WHITE) { // white turn
        addToEnd(head, makeMoveNode(row_from, col_from, row_from, col_from+1));
        if (row_from == 1) {
            addToEnd(head, makeMoveNode(row_from, col_from, row_from, col_from+2));
        }
        //check if pawn can take diagonally left
        if (col_from > 0 && isBlackPiece(board[row_from+1][col_from-1])) {
            addToEnd(head, makeMoveNode(row_from, col_from, row_from+1, col_from-1));
        }
        //check if pawn can take diagonally right
        if (col_from < 7 && isBlackPiece(board[row_from+1][col_from+1])) {
            addToEnd(head, makeMoveNode(row_from, col_from, row_from+1, col_from+1));
        }
    } else { // black turn
        addToEnd(head, makeMoveNode(row_from, col_from, row_from, col_from-1));
        if (row_from == 6) {
            addToEnd(head, makeMoveNode(row_from, col_from, row_from, col_from-2));
        }
        //check if pawn can take diagonally left
        if (col_from > 0 && isWhitePiece(board[row_from-1][col_from-1])) {
            addToEnd(head, makeMoveNode(row_from, col_from, row_from+1, col_from-1));
        }
        //check if pawn can take diagonally right
        if (col_from < 7 && isWhitePiece(board[row_from-1][col_from+1])) {
            addToEnd(head, makeMoveNode(row_from, col_from, row_from+1, col_from+1));
        }
    }
}
void check_en_passant(MoveNode* head, char board[8][8], int row_from, int col_from, int player_turn, int metadata) {
    if (enPassantAvailable(metadata) == 0) return;
    int epRow = enPassantPawnRow(metadata);
    int epCol = enPassantPawnCol(metadata);
    if (player_turn == WHITE) {// white turn
        if (epCol > 0 && board[epRow-1][epCol-1] == 'P') { // en passant to the right
            addToEnd(head, makeMoveNode(epRow-1,epCol-1,epRow,epCol));
        }
        if (epCol < 7 && board[epRow-1][epCol+1] == 'P') { // en passant to the left
            addToEnd(head, makeMoveNode(epRow-1,epCol+1,epRow,epCol));
        }
    } else { // black turn
        if (epCol > 0 && board[epRow+1][epCol-1] == 'p') { // en passant to the right
            addToEnd(head, makeMoveNode(epRow+1,epCol-1,epRow,epCol));
        }
        if (epCol < 7 && board[epRow+1][epCol+1] == 'p') { // en passant to the left
            addToEnd(head, makeMoveNode(epRow+1,epCol+1,epRow,epCol));
        }
    }
}
void get_rook_moves(MoveNode* head, int row_from, int col_from);
void get_bishop_moves(MoveNode* head, int row_from, int col_from);
void get_knight_moves(MoveNode* head, int row_from, int col_from);
void get_queen_moves(MoveNode* head, int row_from, int col_from);
void get_king_moves(MoveNode* head, int row_from, int col_from);


/**
 * @brief returns new MoveNode* with null next, and argument parameters
 */
MoveNode* makeMoveNode(int row_from, int col_from, int row_to, int col_to) {
    MoveNode* move = (MoveNode *)malloc(sizeof(MoveNode));
    move->move.col_from = col_from;
    move->move.col_to = col_to;
    move->move.row_from = row_from;
    move->move.row_to = row_to;
    return move;
}
/**
 * @brief adds MoveNode* head to end of MoveNode* add
 */
void addToEnd(MoveNode *head, MoveNode* add){
    while (head->nextMove != NULL) {
        head = head->nextMove;
    }
    head->nextMove = add;
}
/**
 * @brief prints the movenodes
 */
void printMoveNodes(MoveNode *head) {
    while (head != NULL)
    {
        printf("from: row-%d col-%d  to: row-%d col-%d\n", 
            head->move.row_from,
            head->move.col_from,
            head->move.row_to,
            head->move.col_to);
        head = head->nextMove;
    }
    printf("\n");
}

/**
 * @brief returns non-zero if black, zero if not black
 */
int isBlackPiece(char piece) {
    return islower(piece);
}
/**
 * @brief returns non-zero if white, zero if not white
 */
int isWhitePiece(char piece) {
    return isupper(piece);
}