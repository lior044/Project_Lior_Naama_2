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
	string move = "d5d4";
	Board my_board;
	int x_current;
	int y_current;
	int x_next;
	int y_next;

	//turn move into readable index
	x_current = move[0] - 97;
	y_current = move[1] - 48;
	y_current = 8 - y_current; //sync accessing method with index method
	x_next = move[2] - 97;
	y_next = move[3] - 48;
	y_next = 8 - y_next;       //same here


	//go through all the checks
	my_board.check_Invalid_Index(x_current, y_current, x_next, y_next);		 //check index
	my_board.check_Move_To_Same_Index(x_current, y_current, x_next, y_next); //check if it`s the same index
	my_board.check_Move_Invalid_Piece(x_current, y_current);				 //check piece to be moved
	my_board.check_Move_to_self_piece(x_next, y_next);						 //check if end index is not current player`s piece
	my_board.check_Invalid_move(x_current, y_current, x_next, y_next);		 //check if move is valid for that piece
	my_board.check_self_check(x_current, y_current, x_next, y_next);

	my_board.print_Move_Log();

	return 0;
}