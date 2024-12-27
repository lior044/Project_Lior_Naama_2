#pragma once
#define BOARD_SIZE 8
#include "Move_Log.h"

//al the pieces
#include "Rook.h"
#include "King.h"

class Board {
public:
    Board();
    ~Board();
    void check_Check(int x_current, int y_current, int x_next, int y_next);
    void check_self_check(int x_current, int y_current, int x_next, int y_next);
    void check_Move_Invalid_Piece(int x_current, int y_current);
    void check_Move_to_self_piece(int x_next, int y_next);
    void check_Invalid_Index(int x_current, int y_current, int x_next, int y_next);
    void check_Move_To_Same_Index(int x_current, int y_current, int x_next, int y_next);
    void check_Invalid_move(int x_current, int y_current, int x_next, int y_next);

    void print_Move_Log();

private:
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'#', '#', '#', '#', '#', '#', 'b', '#'}, //0 
        {'#', '#', '#', '#', '#', 'B', '#', '#'}, //1
        {'#', '#', '#', '#', '#', '#', '#', '#'}, //2
        {'#', '#', '#', 'K', '#', '#', '#', '#'}, //3
        {'#', '#', '#', '#', 'p', '#', '#', '#'}, //4
        {'#', '#', '#', '#', '#', '#', '#', '#'}, //5
        {'#', '#', '#', 'Q', '#', '#', '#', '#'}, //6
        {'#', '#', '#', 'q', '#', '#', '#', '#'}  //7
    };  //A    B    C    D    E    F    G    H

    int game_code;
    int turn;
    Move_Log _Move_log;


};