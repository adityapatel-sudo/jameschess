
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
int enPassantPawnColor(int metaData);
int whiteKingCastleAvailable(int metaData);
int blackKingCastleAvailable(int metaData);

//pieceMoves 
//all of these will return a list of possible moves  
MoveNode* get_pawn_moves(int row_from, int col_from, int player_turn);
MoveNode* get_rook_moves(int row_from, int col_from);
MoveNode* get_bishop_moves(int row_from, int col_from);
MoveNode* get_knight_moves(int row_from, int col_from);
MoveNode* get_queen_moves(int row_from, int col_from);
MoveNode* get_king_moves(int row_from, int col_from);
