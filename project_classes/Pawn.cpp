#include "Pawn.h"

int Pawn::Invalid_move(int x_current, int y_current, int x_next, int y_next, char board[8][8]) {
	char pawn = board[y_current][x_current];
	int Invalid = 1;

	if (pawn == 'p') { //pawn is black and can only move dwan
		if (y_current == 1 && y_next == y_current + 2 && x_current == x_next && board[y_current + 1][x_current] == '#') { //checking if it is first pawn`s move and only watns to move two block down and not jumping over any one
			Invalid = 0;
		}

		if (y_next == y_current + 1 && x_current == x_next) { //checking if only wants to move one space
			Invalid = 0;
		}
		if ((y_next == y_current + 1) && (x_next == x_current + 1 || x_next == x_current - 1) && ((board[y_current + 1][x_current + 1] >= 65 && board[y_current + 1][x_current + 1] <= 90) || (board[y_current + 1][x_current - 1] >= 65 && board[y_current + 1][x_current - 1] <= 90))) { //checks that it eats other piece correctly
			Invalid = 0;
		}
	}
	else { //pawn is white and can only move up
		if (y_current == 7 && y_next == y_current - 2 && x_current == x_next && board[y_current - 1][x_current] == '#') { //checking if it is first pawn`s move and only watns to move two block down and not jumping over any one
			Invalid = 0;
		}

		if (y_next == y_current - 1 && x_current == x_next) { //checking if only wants to move one space
			Invalid = 0;
		}
		if ((y_next == y_current - 1) && (x_next == x_current + 1 || x_next == x_current - 1) && ((board[y_current - 1][x_current + 1] >= 65 && board[y_current - 1][x_current + 1] <= 90) || (board[y_current - 1][x_current - 1] >= 65 && board[y_current - 1][x_current - 1] <= 90))) { //checks that it eats other piece correctly
			Invalid = 0;
		}
	}

	return Invalid;
}