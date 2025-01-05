#pragma once
#define BOARD_SIZE 8
#include "Move_Log.h"

//al the pieces
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"

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
    int get_code();
    void set_code(int code);
    void set_all_Move_log_to_0();
    int check_for_positive_checks_in_move_log() const;

    void print_Move_Log();
    void print_board();
    void update_board(int x_current, int y_current, int x_next, int y_next);
    static string stringborad(char board[8][8]);
    static void getmove(const string& move, int& x_current, int& y_current, int& x_next, int& y_next);
    bool processMove(Board& board, int x_current, int y_current, int x_next, int y_next);

private:
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'}, //0 
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, //1
        {'#', '#', '#', '#', '#', '#', '#', '#'}, //2
        {'#', '#', '#', '#', '#', '#', '#', '#'}, //3
        {'#', '#', '#', '#', '#', '#', '#', '#'}, //4
        {'#', '#', '#', '#', '#', '#', '#', '#'}, //5
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, //6
        {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'}  //7
    };  //A    B    C    D    E    F    G    H

    int game_code;
    int turn;
    Move_Log _Move_log;


};