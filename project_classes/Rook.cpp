#include "Rook.h"

int Rook::Invalid_move(int x_current, int y_current, int x_next, int y_next, char board[8][8]) {
	int i = 0;
	int Invalid = 0;
	int x;
	int y;
	//check which direction is move

	if (x_current == x_next) {  //then the move is vertical
		x = x_current; //does not matter wich one
		if (y_current > y_next) { //check which way
			for (i = (y_current - 1); i > y_next; i--) {
				if ((board[i][x] >= 65 && board[i][x] <= 90) || (board[i][x] >= 97 && board[i][x] <= 122)) {
					Invalid = 1;
					return Invalid;
				}
			}
			return Invalid;
		}
		else {

			for (i = (y_current + 1); i < y_next; i++) {
				if ((board[i][x] >= 65 && board[i][x] <= 90) || (board[i][x] >= 97 && board[i][x] <= 122)) {
					Invalid = 1;
					return Invalid;
				}
			}
			return Invalid;
		}

	}

	if (y_current == y_next) {  //then move is horizontal
		y = y_current; //does not matter wich one
		if (x_current > x_next) { //check which way

			for (i = (x_current - 1); i > x_next; i--) {
				if ((board[y][i] >= 65 && board[y][i] <= 90) || (board[y][i] >= 97 && board[y][i] <= 122)) {
					Invalid = 1;
					return Invalid;
				}
			}
			return Invalid;
		}
		else {

			for (i = (x_current + 1); i < x_next; i++) {
				if ((board[y][i] >= 65 && board[y][i] <= 90) || (board[y][i] >= 97 && board[y][i] <= 122)) {
					Invalid = 1;
					return Invalid;
				}
			}
			return Invalid;
		}
	}
	else {
		Invalid = 1;
	}



	return Invalid;
}