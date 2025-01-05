#include "secnderyMain.h"
#include <iostream>
#include <string>
#include <stdexcept>

std::string SecondaryMain::gamefunc(int x_current, int y_current, int x_next, int y_next)
{
   

    try {
        // Convert move string to indices
        x_current = _Move[0] - 'a';
        y_current = 8 - (_Move[1] - '0');
        x_next = _Move[2] - 'a';
        y_next = 8 - (_Move[3] - '0');

        // Run standard checks
        My_Board.check_Invalid_Index(x_current, y_current, x_next, y_next);
        My_Board.check_Move_To_Same_Index(x_current, y_current, x_next, y_next);
        My_Board.check_Move_Invalid_Piece(x_current, y_current);
        My_Board.check_Move_to_self_piece(x_next, y_next);
        My_Board.check_Invalid_move(x_current, y_current, x_next, y_next);

        // Check for invalidations in move log
        if (My_Board.check_for_positive_checks_in_move_log() != 0) 
        {
            return std::to_string(My_Board.check_for_positive_checks_in_move_log());
        }

        // Check for self-check
        if (My_Board.check_self_check(x_current, y_current, x_next, y_next)) {
            return "";
        }

        // Update board and switch turn
        My_Board.update_board(x_current, y_current, x_next, y_next);
        My_Board.set_turn(My_Board.get_turn() == WHITE ? BLACK : WHITE);

        // Return the updated board state as a string
        return My_Board.stringborad(My_Board);

    }
    catch (const std::exception& e) {
        return std::string("Error: ") + e.what();
    }
}

SecondaryMain::SecondaryMain(const std::string& move, Board& my_board) {
    _Move = move;
    My_Board = my_board;
}

SecondaryMain::~SecondaryMain(){}

//std::string move;
//Board my_board;
//int x_current;
//int y_current;
//int x_next;
//int y_next;