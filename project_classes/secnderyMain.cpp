#include "secnderyMain.h"
#include <iostream>
#include <string>
#include <stdexcept>

int SecondaryMain::gamefunc(const std::string& move)
{
   
    
    int x_current;
    int y_current;
    int x_next;
    int y_next;
    try {
        My_Board.set_all_Move_log_to_0();
        My_Board.set_code(0);
        Board::getmove(move, x_current, y_current, x_next, y_next);

        // Run standard checks
        My_Board.check_Invalid_Index(x_current, y_current, x_next, y_next);
        My_Board.check_Move_To_Same_Index(x_current, y_current, x_next, y_next);
        My_Board.check_Move_Invalid_Piece(x_current, y_current);
        My_Board.check_Move_to_self_piece(x_next, y_next);
        My_Board.check_Invalid_move(x_current, y_current, x_next, y_next);

       
		//checking for basic Invalidations so that there will not be any problems when checking for self and enemy checks
		if (My_Board.check_for_positive_checks_in_move_log() != 0) {
            My_Board.set_code(My_Board.check_for_positive_checks_in_move_log());

		}

		else {
			//check for self check
			if (My_Board.check_self_check(x_current, y_current, x_next, y_next)) {
				My_Board.set_code(4);

			}
			//update board and check for enemy check
			else {
				My_Board.update_board(x_current, y_current, x_next, y_next);
				if (My_Board.check_Check(x_current, y_current, x_next, y_next)) {
                    My_Board.set_code(1);

				}
                //switch turn
                My_Board.set_turn(My_Board.get_turn() == WHITE ? BLACK : WHITE);
			}

		}


        // Return the updated board state as a string
        //return My_Board.stringborad();

    }
    catch (const std::exception& e) {
        return 0;
    }

    return 0;
}

SecondaryMain::SecondaryMain(Board& my_board) {
    My_Board = my_board;
}

SecondaryMain::~SecondaryMain(){}
Board SecondaryMain::get_board() const {
    return My_Board;
}

//std::string move;
//Board my_board;
//int x_current;
//int y_current;
//int x_next;
//int y_next;