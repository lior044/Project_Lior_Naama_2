#include "Bishop.h"

int Bishop::Invalid_move(int x_current, int y_current, int x_next, int y_next, char board[8][8]) 
{
	int i = 0;
	int Invalid = 0;
	int x;
	int y;


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

	return Invalid; // 0 if valid, 1 if invalid
}