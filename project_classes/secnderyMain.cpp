#include "secnderyMain.h"
#include <iostream>
#include <string>
#include <stdexcept>

std::string SecondaryMain::gamefunc(const std::string& move, Board& my_board, int x_current, int y_current, int x_next, int y_next)
{
   

    try {
        // Convert move string to indices
        x_current = move[0] - 'a';
        y_current = 8 - (move[1] - '0');
        x_next = move[2] - 'a';
        y_next = 8 - (move[3] - '0');

        // Run standard checks
        my_board.check_Invalid_Index(x_current, y_current, x_next, y_next);
        my_board.check_Move_To_Same_Index(x_current, y_current, x_next, y_next);
        my_board.check_Move_Invalid_Piece(x_current, y_current);
        my_board.check_Move_to_self_piece(x_next, y_next);
        my_board.check_Invalid_move(x_current, y_current, x_next, y_next);

        // Check for invalidations in move log
        if (my_board.check_for_positive_checks_in_move_log() != 0) 
        {
            return std::to_string(my_board.check_for_positive_checks_in_move_log());
        }

        // Check for self-check
        if (my_board.check_self_check(x_current, y_current, x_next, y_next)) {
            return "";
        }

        // Update board and switch turn
        my_board.update_board(x_current, y_current, x_next, y_next);
        my_board.set_turn(my_board.get_turn() == WHITE ? BLACK : WHITE);

        // Return the updated board state as a string
        return my_board.stringborad(my_board);

    }
    catch (const std::exception& e) {
        return std::string("Error: ") + e.what();
    }
}
