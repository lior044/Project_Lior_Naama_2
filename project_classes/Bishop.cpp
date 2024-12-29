#include "Bishop.h"

int Bishop::Invalid_move(int x_current, int y_current, int x_next, int y_next, char board[8][8]) 
{
	int i = 0;
	int Invalid = 0;
	int x;
	int y;

	if (x_next - x_current == y_next - y_current)
	{
		int x, y;
	}

	if (x_current < x_next && y_current < y_next) { // Bottom-right 
		for (x = x_current + 1, y = y_current + 1; x < x_next && y < y_next; ++x, ++y)
		{
			if ((board[y][x] >= 65 && board[y][x] <= 90) || (board[y][x] >= 97 && board[y][x] <= 122)) {
				Invalid = 1; // Path is blocked
				return Invalid;
			}
		}
	}
	if (x_current < x_next && y_current < y_next) { // Bottom-left 
		for (x = x_current -1, y = y_current + 1; x < x_next && y < y_next; ++x, ++y)
		{
			if ((board[y][x] >= 65 && board[y][x] <= 90) || (board[y][x] >= 97 && board[y][x] <= 122)) {
				Invalid = 1; // Path is blocked
				return Invalid;
			}
		}
	}
	if (x_current < x_next && y_current < y_next) { // top-right 
		for (x = x_current + 1, y = y_current - 1; x < x_next && y < y_next; ++x, ++y)
		{
			if ((board[y][x] >= 65 && board[y][x] <= 90) || (board[y][x] >= 97 && board[y][x] <= 122)) {
				Invalid = 1; // Path is blocked
				return Invalid;
			}
		}
	}
	if (x_current < x_next && y_current < y_next) { // top-left 
		for (x = x_current - 1, y = y_current -  1; x < x_next && y < y_next; ++x, ++y)
		{
			if ((board[y][x] >= 65 && board[y][x] <= 90) || (board[y][x] >= 97 && board[y][x] <= 122)) {
				Invalid = 1; // Path is blocked
				return Invalid;
			}
		}
	}

 else 
	{
	 Invalid = 1; // Not a valid diagonal move
	}

	return Invalid; // 0 if valid, 1 if invalid
}