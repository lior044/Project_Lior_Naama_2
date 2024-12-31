#include "Queen.h"

int Queen::Invalid_move(int x_current, int y_current, int x_next, int y_next, char board[8][8]) {
	
	int i = 0;
	int Invalid = 0;
	int x;
	int y;

	//check rook moves
	

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

	//if not rook then check bishop moves
	else {
		
		if (x_current < x_next && y_current < y_next) { // Bottom-right 
			if (x_next - x_current != y_next - y_current) { // make sure going in a straight diagonal
				Invalid = 1;
			}
			for (x = x_current, y = y_current; x < x_next && y < y_next; x++, y++)
			{
				if (x != x_current && y != y_current) {//skip same space
					if ((board[y][x] >= 65 && board[y][x] <= 90) || (board[y][x] >= 97 && board[y][x] <= 122)) {
						Invalid = 1; // Path is blocked
						return Invalid;
					}
				}

			}
		}

		if (x_current > x_next && y_current < y_next) { // Bottom-left 
			if (x_current - x_next != y_next - y_current) { // make sure going in a straight diagonal
				Invalid = 1;
			}
			for (x = x_current, y = y_current; x > x_next && y < y_next; x--, y++)
			{
				if (x != x_current && y != y_current) { //skip same space
					if ((board[y][x] >= 65 && board[y][x] <= 90) || (board[y][x] >= 97 && board[y][x] <= 122)) {
						Invalid = 1; // Path is blocked
						return Invalid;
					}
				}

			}
		}

		if (x_current < x_next && y_current > y_next) { // top-right 
			if (x_next - x_current != y_current - y_next) { // make sure going in a straight diagonal
				Invalid = 1;
			}
			for (x = x_current, y = y_current; x < x_next && y > y_next; x++, y--)
			{
				if (x != x_current && y != y_current) {
					if ((board[y][x] >= 65 && board[y][x] <= 90) || (board[y][x] >= 97 && board[y][x] <= 122)) {
						Invalid = 1; // Path is blocked
						return Invalid;
					}
				}

			}
		}

		if (x_current > x_next && y_current > y_next) { // top-left 
			if (x_current - x_next != y_current - y_next) { // make sure going in a straight diagonal
				Invalid = 1;
			}
			for (x = x_current, y = y_current; x > x_next && y > y_next; x--, y--)
			{
				if (x != x_current && y != y_current) {
					if ((board[y][x] >= 65 && board[y][x] <= 90) || (board[y][x] >= 97 && board[y][x] <= 122)) {
						Invalid = 1; // Path is blocked
						return Invalid;
					}
				}

			}
		}
	}



	



	return Invalid;
}
