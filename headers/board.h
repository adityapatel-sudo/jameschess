
typedef struct PieceMove{
    int row_from;
    int col_from;
    int row_to;
    int col_to;
} PieceMove;

typedef struct MoveNode
{
    PieceMove move;
    struct MoveNode* nextMove;
} MoveNode;


// Function prototypes
void initialize_board();
void initialize_board_custom(char brd[8][8]);
void print_board(char brd[8][8]);
int is_move_valid(int row_from, int col_from, int row_to, int col_to);
void make_move(int row_from, int col_from, int row_to, int col_to);
MoveNode* get_moves(char brd[8][8], int player_turn);

//board data functions
int enPassantAvailable(int metaData);
int enPassantPawnRow(int metaData);
int enPassantPawnCol(int metaData);
int whiteKingCastleAvailable(int metaData);
int blackKingCastleAvailable(int metaData);
void setEnPassantAvailable(int *metaData);
void setEnPassantUnavailable(int *metaData);
void setEnPassantPawnRow(int *metaData, int row);
void setEnPassantPawnCol(int *metaData, int col);
void setWhiteKingCastleAvailable(int *metaData);
void setBlackKingCastleAvailable(int *metaData);
void setWhiteKingCastleUnavailable(int *metaData);
void setBlackKingCastleUnavailable(int *metaData);
void initMetaData(int *metaData);
void printMetaData(int metaData);


//pieceMoves 
//all of these will return a list of possible moves  
MoveNode* get_pawn_moves(char board[8][8], int row_from, int col_from, int player_turn);
MoveNode* check_en_passant(int row_from, int col_from, int player_turn, int metadata);
MoveNode* get_rook_moves(int row_from, int col_from);
MoveNode* get_bishop_moves(int row_from, int col_from);
MoveNode* get_knight_moves(int row_from, int col_from);
MoveNode* get_queen_moves(int row_from, int col_from);
MoveNode* get_king_moves(int row_from, int col_from);

//get piece data
int isBlackPiece(char piece);
int isWhitePiece(char piece);

//MoveNode Manipulation
MoveNode* makeMoveNode(int row_from, int col_from, int row_to, int col_to);
void addToEnd(MoveNode *head, MoveNode* add);
