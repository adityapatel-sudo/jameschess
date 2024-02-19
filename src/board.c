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

char convert_to_letter(int num) {
    if (num < 0 || num > 7) {
        return ' '; // Return a space for out-of-range numbers
    }
    return 'a' + num;
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

void get_pawn_moves(MoveNode* head, char board[8][8], int row_from, int col_from) {
    if (pieceColor(board[row_from][col_from]) == WHITE) { // white turn
        if (board[row_from][col_from+1] == ' ')
            addToEnd(head, makeMoveNode(row_from, col_from, row_from, col_from+1));
        if (row_from == 1 && board[row_from][col_from+2] == ' ') {
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
        if (board[row_from][col_from-1] == ' ')
            addToEnd(head, makeMoveNode(row_from, col_from, row_from, col_from-1));
        if (row_from == 6 && board[row_from][col_from-2] == ' ') {
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
void check_en_passant(MoveNode* head, char board[8][8], int row_from, int col_from, int metadata) {
    if (enPassantAvailable(metadata) == 0) return;
    int epRow = enPassantPawnRow(metadata);
    int epCol = enPassantPawnCol(metadata);
    if (pieceColor(board[row_from][col_from]) == WHITE) {// white turn
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
void get_rook_moves(MoveNode* head, char board[8][8], int row_from, int col_from) {
    //check left
    for (int i = col_from-1; i>=0; i--) {
        if (board[row_from][i] == ' ') { // if piece is empty
            addToEnd(head, makeMoveNode(row_from, col_from, row_from, i));
        } else if (pieceColor(board[row_from][i]) == pieceColor(board[row_from][col_from])) { // if own peice break
            break;
        } else if (pieceColor(board[row_from][i]) != pieceColor(board[row_from][col_from])){ // if opponenent piece add move then break
            addToEnd(head, makeMoveNode(row_from, col_from, row_from, i));
            break;
        }
    }
    //check right
    for (int i = col_from+1; i<8; i++) {
        if (board[row_from][i] == ' ') { // if piece is empty
            addToEnd(head, makeMoveNode(row_from, col_from, row_from, i));
        } else if (pieceColor(board[row_from][i]) == pieceColor(board[row_from][col_from])) { // if own peice break
            break;
        } else if (pieceColor(board[row_from][i]) != pieceColor(board[row_from][col_from])){ // if opponenent piece add move then break
            addToEnd(head, makeMoveNode(row_from, col_from, row_from, i));
            break;
        }
    }
    //check up
    for (int i = row_from+1; i<8; i++) {
        if (board[i][col_from] == ' ') { // if piece is empty
            addToEnd(head, makeMoveNode(row_from, col_from, i, col_from));
        } else if (pieceColor(board[i][col_from]) == pieceColor(board[row_from][col_from])) { // if own peice break
            break;
        } else if (pieceColor(board[i][col_from]) != pieceColor(board[row_from][col_from])){ // if opponenent piece add move then break
            addToEnd(head, makeMoveNode(row_from, col_from, i, col_from));
            break;
        }
    }
    //check down
    for (int i = row_from-1; i>=0; i--) {
        if (board[i][col_from] == ' ') { // if piece is empty
            addToEnd(head, makeMoveNode(row_from, col_from, i, col_from));
        } else if (pieceColor(board[i][col_from]) == pieceColor(board[row_from][col_from])) { // if own peice break
            break;
        } else if (pieceColor(board[i][col_from]) != pieceColor(board[row_from][col_from])){ // if opponenent piece add move then break
            addToEnd(head, makeMoveNode(row_from, col_from, i, col_from));
            break;
        }
    }
}
void get_bishop_moves(MoveNode* head, char board[8][8], int row_from, int col_from) {
    //check up left
    for (int col = col_from-1, row = row_from + 1;col >=0 && row <8; col--, row++) {
        if (board[row][col] == ' ') { // if piece is empty
            addToEnd(head, makeMoveNode(row_from, col_from, row, col));
        } else if (pieceColor(board[row][col]) == pieceColor(board[row_from][col_from])) { // if own peice break
            break;
        } else if (pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])){ // if opponenent piece add move then break
            addToEnd(head, makeMoveNode(row_from, col_from, row, col));
            break;
        }
    }
    //check up right
    for (int col = col_from+1, row = row_from + 1;col <8 && row <8; col++, row++) {
        if (board[row][col] == ' ') { // if piece is empty
            addToEnd(head, makeMoveNode(row_from, col_from, row, col));
        } else if (pieceColor(board[row][col]) == pieceColor(board[row_from][col_from])) { // if own peice break
            break;
        } else if (pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])){ // if opponenent piece add move then break
            addToEnd(head, makeMoveNode(row_from, col_from, row, col));
            break;
        }
    }
    //check down left
    for (int col = col_from-1, row = row_from - 1;col >=0 && row >=0; col--, row--) {
        if (board[row][col] == ' ') { // if piece is empty
            addToEnd(head, makeMoveNode(row_from, col_from, row, col));
        } else if (pieceColor(board[row][col]) == pieceColor(board[row_from][col_from])) { // if own peice break
            break;
        } else if (pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])){ // if opponenent piece add move then break
            addToEnd(head, makeMoveNode(row_from, col_from, row, col));
            break;
        }
    }
    //check down right
    for (int col = col_from+1, row = row_from - 1;col <8 && row >=0; col++, row--) {
        if (board[row][col] == ' ') { // if piece is empty
            addToEnd(head, makeMoveNode(row_from, col_from, row, col));
        } else if (pieceColor(board[row][col]) == pieceColor(board[row_from][col_from])) { // if own peice break
            break;
        } else if (pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])){ // if opponenent piece add move then break
            addToEnd(head, makeMoveNode(row_from, col_from, row, col));
            break;
        }
    }
}
void get_knight_moves(MoveNode* head, char board[8][8], int row_from, int col_from) {
    int row;
    int col;
    //check up then left
    row = row_from - 1;
    col = col_from + 2;
    if (in_bounds(row,col) && pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])) {
        addToEnd(head, makeMoveNode(row_from,col_from,row,col));
    }
    //check up then right
    row = row_from + 1;
    col = col_from + 2;
    if (in_bounds(row,col) && pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])) {
        addToEnd(head, makeMoveNode(row_from,col_from,row,col));
    }
    //check right then up
    row = row_from + 2;
    col = col_from + 1;
    if (in_bounds(row,col) && pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])) {
        addToEnd(head, makeMoveNode(row_from,col_from,row,col));
    }
    //check right then down
    row = row_from + 2;
    col = col_from - 1;
    if (in_bounds(row,col) && pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])) {
        addToEnd(head, makeMoveNode(row_from,col_from,row,col));
    }
    //check down then right
    row = row_from + 1;
    col = col_from - 2;
    if (in_bounds(row,col) && pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])) {
        addToEnd(head, makeMoveNode(row_from,col_from,row,col));
    }
    //check down then left
    row = row_from - 1;
    col = col_from - 2;
    if (in_bounds(row,col) && pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])) {
        addToEnd(head, makeMoveNode(row_from,col_from,row,col));
    }
    //check left then down
    row = row_from - 2;
    col = col_from - 1;
    if (in_bounds(row,col) && pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])) {
        addToEnd(head, makeMoveNode(row_from,col_from,row,col));
    }
    //check left then up
    row = row_from - 2;
    col = col_from + 1;
    if (in_bounds(row,col) && pieceColor(board[row][col]) != pieceColor(board[row_from][col_from])) {
        addToEnd(head, makeMoveNode(row_from,col_from,row,col));
    }
}
void get_queen_moves(MoveNode* head, char board[8][8], int row_from, int col_from) {
    get_rook_moves(head, board, row_from, col_from);
    get_bishop_moves(head, board, row_from, col_from);
}
void get_king_moves(MoveNode* head, char board[8][8], int row_from, int col_from) {
    
}
int in_bounds(int row, int col) {
    return (row < 8 && row >= 0 && col < 8 && col >=0);
}


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

void deleteMoveNodes(MoveNode* head) {
    MoveNode *cur = head;
    while (cur != NULL) {
        cur = head->nextMove;
        free(head);
        head = cur;
    }
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
    printf("moves:\n");
    while (head != NULL)
    {
        printf("from: %c%d to %c%d\n", 
            convert_to_letter(head->move.col_from),
            head->move.row_from+1,
            convert_to_letter(head->move.col_to),
            head->move.row_to+1);
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

/**
 * @brief returns BLACK or WHITE
 */
int pieceColor(char piece) {
    if (isBlackPiece(piece)) return BLACK;
    if (isWhitePiece(piece)) return WHITE;
    return EMPTY;
}
int reversePieceColor(char piece) {
    if (isBlackPiece(piece)) return WHITE;
    if (isWhitePiece(piece)) return BLACK;
    return EMPTY;
}