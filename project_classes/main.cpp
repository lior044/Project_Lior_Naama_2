#include <iostream>
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

int main() {
	string move;
	Board my_board;
	int x_current;
	int y_current;
	int x_next;
	int y_next;


	while (true) {
		my_board.print_board();
		if (my_board.get_turn() == WHITE) {
			cout << "What is your move WHITE?" << endl;
			cin >> move;
		}

		else {
			cout << "What is your move BLACK?" << endl;
			cin >> move;
		}

		//turn move into readable index
		x_current = move[0] - 97;
		y_current = move[1] - 48;
		y_current = 8 - y_current; //sync accessing method with index method
		x_next = move[2] - 97;
		y_next = move[3] - 48;
		y_next = 8 - y_next;       //same here

		//run standered checks
		my_board.check_Invalid_Index(x_current, y_current, x_next, y_next);
		my_board.check_Move_To_Same_Index(x_current, y_current, x_next, y_next);
		my_board.check_Move_Invalid_Piece(x_current, y_current);
		my_board.check_Move_to_self_piece(x_next, y_next);
		my_board.check_Invalid_move(x_current, y_current, x_next, y_next);

		
		//checking for basic Invalidations so that there will not be any problems when checking for self and enemy checks
		if (my_board.check_for_positive_checks_in_move_log() != 0) {
			cerr << "ERROR number: " + to_string(my_board.check_for_positive_checks_in_move_log()) << endl;
			cout << "Please try another move." << endl;

		}

		else {
			//check for self check
			if (my_board.check_self_check(x_current, y_current, x_next, y_next)) {
				cerr << "ERROR number: " + to_string(4) << endl;
				cout << "Please try another move." << endl;

			}
			//update board and check for enemy check
			else {
				my_board.update_board(x_current, y_current, x_next, y_next);
				if (my_board.check_Check(x_current, y_current, x_next, y_next)) {
					cout << "Nice move!" << endl;
					if (my_board.get_turn() == WHITE) {
						cout << "Black is on check!" << endl;
					}
					else {
						cout << "White is on check" << endl;
					}
				}
				//switch turn
				if (my_board.get_turn() == WHITE) {
					my_board.set_turn(BLACK);
				}

				else {
					my_board.set_turn(WHITE);
				}
			}

		}


	}

	return 0;
}