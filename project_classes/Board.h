#pragma once
#define BOARD_SIZE 8
#include "Move_Log.h"

//al the pieces
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Bishop.h"

class Board {
public:
    Board();
    ~Board();
    int check_Check(int x_current, int y_current, int x_next, int y_next);
    int check_self_check(int x_current, int y_current, int x_next, int y_next);
    void check_Move_Invalid_Piece(int x_current, int y_current);
    void check_Move_to_self_piece(int x_next, int y_next);
    void check_Invalid_Index(int x_current, int y_current, int x_next, int y_next);
    void check_Move_To_Same_Index(int x_current, int y_current, int x_next, int y_next);
    void check_Invalid_move(int x_current, int y_current, int x_next, int y_next);
    int get_turn() const;
    void set_turn(int set);

    int check_for_positive_checks_in_move_log() const;

    void print_Move_Log();
    void print_board();
    void update_board(int x_current, int y_current, int x_next, int y_next);

private:
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'#', '#', 'r', 'k', 'r', 'b', '#', '#'}, //0 
        {'#', '#', '#', '#', 'p', '#', '#', '#'}, //1
        {'#', '#', '#', '#', '#', '#', '#', '#'}, //2
        {'#', '#', '#', '#', '#', '#', '#', '#'}, //3
        {'#', '#', '#', '#', '#', '#', '#', '#'}, //4
        {'#', '#', '#', 'r', '#', '#', '#', '#'}, //5
        {'#', '#', 'R', '#', 'P', '#', '#', '#'}, //6
        {'#', '#', '#', 'K', 'R', 'B', '#', '#'}  //7
    };  //A    B    C    D    E    F    G    H

    int game_code;
    int turn;
    Move_Log _Move_log;


};