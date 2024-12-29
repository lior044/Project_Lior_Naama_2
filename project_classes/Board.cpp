#include "Board.h"

//char board[BOARD_SIZE][BOARD_SIZE] = {
//    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, //0     
//    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, //1    black
//    {'#', '#', '#', '#', '#', '#', '#', '#'}, //2
//    {'#', '#', '#', '#', '#', '#', '#', '#'}, //3
//    {'#', '#', '#', '#', '#', '#', '#', '#'}, //4
//    {'#', '#', '#', '#', '#', '#', '#', '#'}, //5
//    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, //6    white
//    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}  //7
//};  //A    B    C    D    E    F    G    H

Board::Board() {
    _Move_log = Move_Log();
    turn = WHITE;
    game_code = 0;
}
Board::~Board() {}

int Board::check_Check(int x_current, int y_current, int x_next, int y_next) {
    //switch turn to see if other king in check
    if (turn == WHITE) {
        turn = BLACK;
    }

    else {
        turn = WHITE;
    }
    _Move_log.set_Check(King::check_if_in_check(board, turn));

    //switch back
    if (turn == WHITE) {
        turn = BLACK;
    }

    else {
        turn = WHITE;
    }

    return _Move_log.get_Check();
}
int Board::check_self_check(int x_current, int y_current, int x_next, int y_next) {
    //update board to next turn
    char temp_board[BOARD_SIZE][BOARD_SIZE];
    // Copy the current board to a temporary board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            temp_board[i][j] = board[i][j];
        }
    }

    // Simulate the move on the temporary board
    temp_board[y_next][x_next] = temp_board[y_current][x_current];
    temp_board[y_current][x_current] = '#';

    _Move_log.set_self_check(King::check_if_in_check(temp_board, turn));

    return _Move_log.get_self_check();
}
void Board::check_Move_Invalid_Piece(int x_current, int y_current) {
    if (turn) {     //if it is black`s turn
        if (board[y_current][x_current] < 97 || board[y_current][x_current] > 122) {   //check if it is not black piece in the current index
            _Move_log.set_Move_Invalid_Piece(1);
        }
        else {
            _Move_log.set_Move_Invalid_Piece(0);
        }
    }

    else {  //if it is white`s turn
        if (board[y_current][x_current] < 65 || board[y_current][x_current] > 90) {   //check if it is not white piece in the current index 
            _Move_log.set_Move_Invalid_Piece(1);
        }
        else {
            _Move_log.set_Move_Invalid_Piece(0);
        }
    }
}
void Board::check_Move_to_self_piece(int x_next, int y_next) {
    if (turn) {     //if it is black`s turn
        if (board[y_next][x_next] >= 97 && board[y_next][x_next] <= 122) {   //check if it is a black piece in the next index
            _Move_log.set_Move_to_self_piece(1);
        }
        else {
            _Move_log.set_Move_to_self_piece(0);
        }
    }

    else {     //if it is white`s turn
        if (board[y_next][x_next] >= 65 && board[y_next][x_next] <= 90) {   //check if it is a white piece in the next index
            _Move_log.set_Move_to_self_piece(1);
        }
        else {
            _Move_log.set_Move_to_self_piece(0);
        }
    }
}
void Board::check_Invalid_Index(int x_current, int y_current, int x_next, int y_next) {
    if (x_current < 0 || x_current > 7 || y_current < 0 || y_current > 7 || x_next < 0 || x_next > 7 || y_next < 0 || y_next > 7) {   //check if all index`s are in correct range
        _Move_log.set_Invalid_Index(1);
    }
    else {
        _Move_log.set_Invalid_Index(0);
    }
}
void Board::check_Move_To_Same_Index(int x_current, int y_current, int x_next, int  y_next) {
    if (x_current == x_next && y_current == y_next) {  //check if trying to move to same index
        _Move_log.set_Move_To_Same_Index(1);
    }
    else {
        _Move_log.set_Move_To_Same_Index(0);
    }
}
void Board::check_Invalid_move(int x_current, int y_current, int x_next, int y_next) {

    switch (board[y_current][x_current]) {
    case 'r':
    case 'R':
        _Move_log.set_Invalid_move(Rook::Invalid_move(x_current, y_current, x_next, y_next, board));
        break;

    case 'k':
    case 'K':
        _Move_log.set_Invalid_move(King::Invalid_move(x_current, y_current, x_next, y_next));
        break;

    case 'b':
    case 'B':
        
        break;

    case 'n':
    case 'N':
        
        break;

    case 'q':
    case 'Q':
        
        break;

    case 'p':
    case 'P':
        _Move_log.set_Invalid_move(Pawn::Invalid_move(x_current, y_current, x_next, y_next, board));
        break;




    }
}

void Board::print_Move_Log() {
    cout << "Invalid Index: " << _Move_log.get_Invalid_Index() << endl;
    cout << "Move to Same Index: " << _Move_log.get_Move_To_Same_Index() << endl;
    cout << "Move Invalid Piece: " << _Move_log.get_Move_Invalid_Piece() << endl;
    cout << "Move to Self Piece: " << _Move_log.get_Move_to_self_piece() << endl;
    cout << "Invalid move: " << _Move_log.get_Invalid_move() << endl;
    cout << "Check: " << _Move_log.get_Check() << endl;
    cout << "Self Check: " << _Move_log.get_self_check() << endl;
}

int Board::get_turn() const {
    return turn;
}

void Board::set_turn(int set) {
    turn = set;
}


//check if one of the base checks is on if so no need to chech for checks of self check
int Board::check_for_positive_checks_in_move_log() const {
    int move_Invalid = 0;

    if (_Move_log.get_Invalid_Index()) {
        move_Invalid = 5;
    }
    if (_Move_log.get_Move_To_Same_Index()) {
        move_Invalid = 7;
    }
    if (_Move_log.get_Move_Invalid_Piece()) {
        move_Invalid = 2;
    }
    if (_Move_log.get_Move_to_self_piece()) {
        move_Invalid = 3;
    }
    if (_Move_log.get_Invalid_move()) {
        move_Invalid = 6;
    }

    return move_Invalid;
}


void Board::print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl; // Move to the next row
    }
}

void Board::update_board(int x_current, int y_current, int x_next, int y_next) {
    board[y_next][x_next] = board[y_current][x_current];
    board[y_current][x_current] = '#';
}