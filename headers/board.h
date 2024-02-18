
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


enum {
    WHITE = 0,
    BLACK = 1
};


// Function prototypes
void initialize_board();
void initialize_board_custom(char brd[8][8]);
void print_board(char brd[8][8]);
char convert_to_letter(int num);
void edit_boardxy(char brd[8][8], int x, int y, char val);
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
void setEnPassantLocation(int *metadata, int row, int col);
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
void get_pawn_moves(MoveNode* head, char board[8][8], int row_from, int col_from, int player_turn);
void check_en_passant(MoveNode* head, char board[8][8], int row_from, int col_from, int player_turn, int metadata);
void get_rook_moves(MoveNode* head, char board[8][8], int row_from, int col_from);
void get_bishop_moves(MoveNode* head, char board[8][8], int row_from, int col_from);
void get_knight_moves(MoveNode* head, char board[8][8], int row_from, int col_from);
void get_queen_moves(MoveNode* head, char board[8][8], int row_from, int col_from);
void get_king_moves(MoveNode* head, char board[8][8], int row_from, int col_from);

//get piece data
int isBlackPiece(char piece);
int isWhitePiece(char piece);
int pieceColor(char piece);

//MoveNode Manipulation
MoveNode* makeMoveNode(int row_from, int col_from, int row_to, int col_to);
void addToEnd(MoveNode *head, MoveNode* add);
void printMoveNodes(MoveNode *head);
